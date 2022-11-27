cmake_minimum_required(VERSION 3.16) # Use the newest cmake version that is available on Ubuntu 20.04 LTS

project(
    cpp_example_project  # Project name
    LANGUAGES CXX        # Enable c++ support
)

set(CMAKE_CXX_STANDARD 20) # Use c++ 20 for everything
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Don't allow anything below that
set(CMAKE_CXX_EXTENSIONS OFF) # No compiler-specific extensions to the language. Everything should be compiler independent
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Export compile command to support IDEs like vscode or clion

add_compile_options(
    -Wall -Wextra -Wpedantic
    -Winit-self -Wold-style-cast -Wcast-qual -Wundef
    -Woverloaded-virtual
    -Wconversion
    -Wzero-as-null-pointer-constant
    -fsanitize=address
    -fsanitize=undefined
    -fsanitize=float-cast-overflow
) # Enable all warnings that could be helpful

add_link_options(
    -fsanitize=address
    -fsanitize=undefined
    -fsanitize=float-cast-overflow
) # Same for the linker

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)
add_executable(example ${SRC_FILES})