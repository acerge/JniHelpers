cmake_minimum_required(VERSION 3.10)
project(FancyNativeLib)
#find_library(JVM_LIB NAMES jvm HINTS "$ENV{JAVA_HOME}/lib/server")
#message("--Find JVM_LIB: " "${JVM_LIB}")
#set(JAVA_JVM_LIBRARY "${JVM_LIB}")
#set(JAVA_AWT_LIBRARY "$ENV{JAVA_HOME}/lib/libjawt.so")
#set(JAVA_JVM_LIBRARY "$ENV{JAVA_HOME}/lib/server/libjvm.so")
#set(JAVA_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
#set(JAVA_INCLUDE_PATH2 "$ENV{JAVA_HOME}/include/linux")
#set(JAVA_AWT_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
#find_package(JNI REQUIRED)
include_directories("$ENV{JAVA_HOME}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/jnihelper")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/hashlib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/fancy")

file(GLOB libFancyNative_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp)
file(GLOB libFancyNative_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.h)

#link_directories(${JAVA_JVM_LIBRARY})
add_library(FancyNative SHARED ${libFancyNative_SOURCES} ${libFancyNative_HEADERS})

set(CMAKE_CXX_FLAGS "-fPIC")
set_target_properties(FancyNative PROPERTIES CMAKE_SHARED_LINKER_FLAGS "-fPIC")

