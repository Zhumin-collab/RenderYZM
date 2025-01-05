CMAKE_MINIMUM_REQUIRED_VERSION(3.15)

# Set the project name
project(LearnOpenGL)

# Add an executable
add_executable(LearnOpenGL main.cpp)

# Add the shader files to the project
file(GLOB SHADERS "shaders/*")

# Copy the shader files to the build directory
file(COPY ${SHADERS} DESTINATION ${CMAKE_BINARY_DIR}/shaders)

# Add the include directory
target_include_directories(LearnOpenGL PRIVATE "third_party/GLAD/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/GLFW/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/glm")
target_include_directories(LearnOpenGL PRIVATE "third_party/stb/include")
target_include_directories(LearnOpenGL PRIVATE "third_party/assimp/include")

# Add the source files
target_sources(LearnOpenGL PRIVATE
    "src/*.cpp"
    "src/*.h"
    "third_party/GLAD/src/glad.c"
)

# Add the third party libraries
target_link_libraries(LearnOpenGL PRIVATE
    "third_party/GLFW/lib/glfw3.lib"
    "third_party/assimp/lib/assimp-vc143-mt.lib"
)

# Add the dlls
file(GLOB DLLS "third_party/assimp/bin/*.dll")
file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR})