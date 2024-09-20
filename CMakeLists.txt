cmake_minimum_required (VERSION 3.20)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("bmpPicturePrinter" VERSION 1.1)

set(CXX_STANDARD c++20)
set(CXX_STANDARD_REQUIRED ON)

add_executable (drawBmp 
				src/bmpPicturePrinter.cpp
				headers/bmpPicturePrinter.hpp
				src/BMPFile.cpp
				headers/BMPFile.hpp)


target_include_directories(drawBmp PUBLIC ${CMAKE_SOURCE_DIR}/headers)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET drawBmp PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(external/googletest)

add_executable(runTest test/test_bmpfile.cpp)

target_link_libraries(runTest gtest gtest_main)

target_link_libraries(runTest BMPDrawer)

enable_testing()
add_test(test BMPFileTest COMMAND runTest)