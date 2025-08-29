# cmake_minimum_required(VERSION 3.16)
# project(GetInfoFromFias)

# # --- C++ стандарт ---
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # --- Toolchain vcpkg (подставь свой путь) ---
# set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# # --- Находим пакет Boost.URL (статический) ---
# find_package(boost-url REQUIRED)

# # --- Собираем все cpp файлы из src/ ---
# file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# # --- Создаём исполняемый файл ---
# add_executable(GetInfoFromFias ${SOURCES})

# # --- Линковка ---
# target_link_libraries(GetInfoFromFias PRIVATE 
#     boost-url::boost-url   # статическая Boost.URL
#     winhttp                # Windows HTTP API
# )

# # --- Определяем выходную папку для exe ---
# set_target_properties(GetInfoFromFias PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
# )




cmake_minimum_required(VERSION 3.16)
project(getInfoFromFias)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Пути к Boost.URL
include_directories(
    "${CMAKE_SOURCE_DIR}/external/boost-url/include"
    "${CMAKE_SOURCE_DIR}/external/boost config/include"    
    )


# Заголовочные файлы
#include_directories(include)

# Исходники
set(SOURCES
   src/main.cpp
#    src/HTTPGet.cpp
)

#set(HEADER 
#    include/main.hpp
#    include/HTTPGet.hpp
#)

# Создаём исполняемый файл
add_executable(getInfoFromFias ${SOURCES})
# add_executable(GetInfoFromFias src/main.cpp)

set_target_properties(getInfoFromFias PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
)

# Линкуем WinHTTP
# target_link_libraries(getInfoFromFias winhttp)