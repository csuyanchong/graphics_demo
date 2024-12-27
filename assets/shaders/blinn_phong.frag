#version 450 core

layout(location = 0) out vec4 color;

in vec3 v_out_posView;
in vec3 v_out_normal;
in vec2 v_out_texture_coord;

uniform vec3 u_light_direction;
uniform vec3 u_light_color;
uniform float u_light_intensity;

uniform vec3 u_ka;
uniform vec3 u_kd;
uniform vec3 u_ks;
uniform float u_alpha;

// intensity_diffuse:0.55, intensity_ambient: 0.25, intensitySpecular: 0.8;

//float intensityDiffuse = 0.45f;
//float intensitySpecular = 1.0f;
float ambient_intensity =  0.2f;
float gamma_correct = 2.2f;


vec3 linearToSRGB(vec3 color) {
    vec3 res = pow(color, vec3 (1.0f / gamma_correct));
    return res;
}

vec3 computeDiffuse(vec3 kd, float cosTheta, vec3 colorLight, float intensity) {
    vec3 res = kd * cosTheta  * colorLight * intensity;
    return res;
}

vec3 computeSpecular(vec3 ks, float cosPhai, float alpha, vec3 colorLight, float intensity) {
    vec3 res = ks * pow(cosPhai, alpha) * colorLight * intensity;
    return res;
}

vec3 computeAmbient(vec3 ka, float intensity) {
    vec3 res = ka * intensity;
    return res;
}

void main() {
    vec3 dirNormal = normalize(v_out_normal);

    vec3 dirLight = normalize(-u_light_direction);

    float cosinTheta = dot(dirNormal, dirLight);

    vec3 dirView = -v_out_posView;

    dirView = normalize(dirView);

    vec3 dirHalf = normalize(dirLight + dirView);

    float cosinPhai = dot(dirHalf, dirNormal);

    // Blinn-phong shading
    vec3 colorDiffuse = vec3(0);
    vec3 colorSpecular = vec3(0);
    if (cosinTheta > 0) {
        // 计算漫反射和镜面反射
        // 1.漫反射
        colorDiffuse = computeDiffuse(u_kd, cosinTheta, u_light_color, u_light_intensity);
        // 2.镜面反射
        colorSpecular = computeSpecular(u_ks, cosinPhai, u_alpha, u_light_color, u_light_intensity);
    }
    // 3.环境光
    vec3 colorAmbient = computeAmbient(u_ka, ambient_intensity);

    // 最终颜色
    vec3 colorFinal = colorDiffuse + colorSpecular + colorAmbient;

    // gamma校正
    vec3 colorGammaCorrected = linearToSRGB(colorFinal);
    color = vec4(colorGammaCorrected, 1.0f);
}