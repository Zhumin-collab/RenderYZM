cmake_minimum_required(VERSION 3.15)

# Set the project name
project(LearnOpenGL)

# Add an executable
add_executable(LearnOpenGL main.cpp)

# Make sure that the build directory has the required directories
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)

# Add the shader files to the project
file(GLOB SHADERS "shaders/*")

# Copy the shader files to the build directory
file(COPY ${SHADERS} DESTINATION ${CMAKE_BINARY_DIR}/shaders)

# Add the assets directory
file(GLOB ASSETS "assets/*")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR}/assets)

# Add the include directory
target_include_directories(LearnOpenGL PRIVATE "src")
target_include_directories(LearnOpenGL PRIVATE "third_party/GLAD/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/GLFW/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/glm")
target_include_directories(LearnOpenGL PRIVATE "third_party/stb/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/assimp/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/imgui")

# Add the source files
file(GLOB SOURCES "src/*.cpp" "src/*.h" "third_party/imgui/*.cpp" "third_party/imgui/*.h")
target_sources(LearnOpenGL PRIVATE
    ${SOURCES}
    "third_party/GLAD/src/glad.c"
)

# Add the third party libraries
target_link_libraries(LearnOpenGL PRIVATE
    "E:/RenderYZM/third_party/GLFW/lib/glfw3.lib"
    "E:/RenderYZM/third_party/assimp/lib/assimp-vc143-mtd.lib"
)

# Add the dlls
file(GLOB DLLS "third_party/assimp/bin/*.dll")
file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})

