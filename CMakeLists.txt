cmake_minimum_required (VERSION 3.20)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("bmpPicturePrinter" VERSION 1.0)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

add_executable(drawBmp 
				src/bmpPicturePrinter.cpp
				headers/bmpPicturePrinter.hpp
				src/BMPFile.cpp
				headers/BMPFile.hpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET drawBmp PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(drawBmp PUBLIC ${CMAKE_SOURCE_DIR}/headers)

#include(ExternalProject)
#ExternalProject_Add(gtest
#  URL https://github.com/google/googletest/archive/release-1.8.0.zip
#
#  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
#  INSTALL_COMMAND ""
#)

#add_executable(mytest test/test_bnpfile.cpp)

#add_dependencies(mytest gtest)

#include_directories(${source_dir}/include)
#target_link_libraries(mytest ${binary_dir}/libgtest.a)
#target_link_libraries(mytest ${binary_dir}/libgtest_main.a)

#enable_testing()
#add_test(
#	NAME mytest
#	COMMAND mytest)
