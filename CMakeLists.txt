cmake_minimum_required(VERSION 3.16)
project(GetInfoFromFias)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Заголовочные файлы
#include_directories(include)

# Исходники
#set(SOURCES
#    src/main.cpp
#    src/HTTPGet.cpp
#)

#set(HEADER 
#    include/main.hpp
#    include/HTTPGet.hpp
#)

# Создаём исполняемый файл
#add_executable(getInfoFromFias ${SOURCES})
add_executable(GetInfoFromFias src/main.cpp)

set_target_properties(GetInfoFromFias PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
)

# Линкуем WinHTTP
# target_link_libraries(getInfoFromFias winhttp)