cmake_minimum_required(VERSION 3.10)
project(ripterms-paladium)

# Utiliser le standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajouter les fichiers source
set(SOURCES main.cpp)

# Trouver et inclure les paquets nécessaires
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(imgui REQUIRED)

# Inclure les répertoires
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${IMGUI_INCLUDE_DIRS})

# Ajouter l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier les bibliothèques nécessaires
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw imgui)
