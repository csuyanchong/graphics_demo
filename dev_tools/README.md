# 开发工具说明
***

## CountCodeLinesNums.py
[脚本位置](CountCodeLineNums.py)

1. 主要功能：
   <p>统计 C++ 项目中的代码行数。</p>

2. 代码说明：
   1. count_lines_in_file(file_path):
   打开文件，读取其中的每一行。
   忽略空行和以 // 开头的单行注释以及 /* */ 包围的多行注释（可以根据实际需求扩展对注释的支持）。
   统计有效的代码行数。
   
   2. count_lines_in_directory(directory_path):
   使用 os.walk() 递归遍历目录中的所有文件。
   对于每个 .cpp 或 .h 文件，调用 count_lines_in_file 来统计行数，并将其累加。

3. 使用方法：
  运行脚本时输入项目的根目录路径，脚本将统计该目录下所有 .cpp 和 .h 文件的代码行数。

4. 扩展功能：
  可以根据需要修改脚本来忽略其他类型的文件（例如，测试文件或资源文件）。
  可以调整注释行的识别方式，支持更多注释格式（例如多行注释的开头和结尾）。
