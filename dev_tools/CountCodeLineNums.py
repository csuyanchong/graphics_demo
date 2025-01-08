import os

def count_lines_in_file(file_path):
    """统计单个文件的代码行数，忽略空行和注释行"""
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    code_lines = 0
    for line in lines:
        stripped_line = line.strip()
        if stripped_line and not stripped_line.startswith("//") and not stripped_line.startswith("/*"):
            code_lines += 1
    return code_lines

def count_lines_in_directory(directory_path):
    """递归统计目录下所有 C++ 文件的代码行数"""
    count_lines = 0
    # 遍历目录
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            # 只统计 .cpp 和 .h 文件
            if file.endswith(".cpp") or file.endswith(".h"):
                file_path = os.path.join(root, file)
                count_lines += count_lines_in_file(file_path)
    return count_lines

if __name__ == "__main__":
    # 输入项目根目录路径
    project_dir = "../src/"
    # project_dir = input("input root directory path: ")
    print("src={}".format(project_dir))
    total_lines = count_lines_in_directory(project_dir)
    print(f"project total code lines（exclude blank or comment lines）：{total_lines} line")
