cmake_minimum_required(VERSION 3.10)
project(CPP_Project)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 获取code目录下所有的cpp文件
file(GLOB_RECURSE SOURCES "code/*.cpp")

# 遍历每个cpp文件，创建对应的可执行文件
foreach(source_file ${SOURCES})
    # 获取文件名（不含路径和扩展名）
    get_filename_component(EXEC_NAME ${source_file} NAME_WE)
    # 获取文件所在的相对路径
    get_filename_component(SOURCE_PATH ${source_file} PATH)
    
    # 创建可执行文件
    add_executable(${EXEC_NAME} ${source_file})
    
    # 如果需要，可以在这里添加特定的链接库
    # target_link_libraries(${EXEC_NAME} ...)
endforeach()