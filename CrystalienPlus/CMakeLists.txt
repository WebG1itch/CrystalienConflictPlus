cmake_minimum_required(VERSION 3.21)
project(CrystalienPlus)

set(CMAKE_CXX_STANDARD 20)

add_executable(CrystalienPlus src/main.cpp)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS window graphics audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy .dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLL "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
