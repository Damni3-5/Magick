project(main)

add_executable (main 
"main.cpp"
"src/Buffer.h"
"src/Random.h"
"src/Shader.cpp" "src/Shader.h"
"src/include.h")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assert DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(OpenGL REQUIRED)
target_link_libraries(main PRIVATE OpenGL::GL)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)

find_package(glad CONFIG REQUIRED)
target_link_libraries(main PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(main PRIVATE imgui::imgui)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

