/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: BlinnPhongMaterial
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_BLINNPHONGMATERIAL_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_BLINNPHONGMATERIAL_H_


#include "Material.h"

class BlinnPhongMaterial : public Material{
public:
    BlinnPhongMaterial(glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float alpha) : m_ka(ka), m_kd(kd), m_ks(ks), m_alpha
            (alpha) {
        setParameter("u_ka", m_ka);
        setParameter("u_kd", m_kd);
        setParameter("u_ks", m_ks);
        setParameter("u_alpha", m_alpha);
    };

private:
    // 环境光颜色
    glm::vec3 m_ka;
    // 漫反射颜色
    glm::vec3 m_kd;
    // 镜面反射颜色
    glm::vec3 m_ks;
    // 高光指数
    float m_alpha;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_BLINNPHONGMATERIAL_H_
