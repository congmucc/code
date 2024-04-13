import os


def rename_files(directory):
    # 遍历当前目录下的所有文件夹和文件
    for root, dirs, files in os.walk(directory):
        # 遍历当前目录下的所有文件夹
        for dir_name in dirs:
            # 检查目录名是否包含'heima'
            if 'heima' in dir_name:
                # 构建新目录名
                new_dir_name = dir_name.replace('heima', 'eason')
                # 打印旧目录名和新目录名
                print(f'Renaming directory {dir_name} to {new_dir_name}')
                # 重命名目录
                os.rename(os.path.join(root, dir_name), os.path.join(root, new_dir_name))

        # 遍历当前目录下的所有文件
        for filename in files:
            # 检查文件名是否包含'heima'
            if 'heima' in filename:
                # 构建新文件名
                new_filename = filename.replace('heima', 'eason')
                # 打印旧文件名和新文件名
                print(f'Renaming {filename} to {new_filename}')
                # 重命名文件
                os.rename(os.path.join(root, filename), os.path.join(root, new_filename))


# 替换文件名的目录路径
directory_path = r'C:\Users\Administrator\Desktop\Project\microservice\leadnews\eason-leadnews\eason-leadnews-common'

# 调用函数
rename_files(directory_path)
