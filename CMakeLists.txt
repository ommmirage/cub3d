cmake_minimum_required(VERSION 3.17)
project(cub3d C)
set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c structs.h)

include_directories(/usr/include)

set(CMAKE_C_FLAGS -lm)

target_link_libraries(cub3d "-Lminilibx_linux/ -lmlx -L/usr/lib")
target_link_libraries(cub3d "-Lminilibx_linux -Imlx_linux -O3")
target_link_libraries(cub3d "-lXext -lX11 -lm")
target_link_libraries(cub3d /usr/lib/libmlx.a)