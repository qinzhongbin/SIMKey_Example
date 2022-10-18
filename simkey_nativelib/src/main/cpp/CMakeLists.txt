cmake_minimum_required(VERSION 3.18.1)
project("simkey_nativelib")

# 头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 依赖库
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs)
# crypto
add_library(lib_crypto SHARED IMPORTED)
set_target_properties(lib_crypto PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libcrypto.so)
# curl
add_library(lib_curl SHARED IMPORTED)
set_target_properties(lib_curl PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libcurl.so)
# sdmp
add_library(lib_sdmp SHARED IMPORTED)
set_target_properties(lib_sdmp PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libsdmp.so)
# simkey
add_library(lib_simkey SHARED IMPORTED)
set_target_properties(lib_simkey PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libsimkey.so)
# ssl
add_library(lib_ssl SHARED IMPORTED)
set_target_properties(lib_ssl PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libssl.so)
# tysimkeylib
add_library(lib_tysimkeylib SHARED IMPORTED)
set_target_properties(lib_tysimkeylib PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libtysimkeylib.so)
# uv
add_library(lib_uv SHARED IMPORTED)
set_target_properties(lib_uv PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libuv.so)
# z
add_library(lib_z SHARED IMPORTED)
set_target_properties(lib_z PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libz.so)

# event
add_library(lib_event-2.1 SHARED IMPORTED)
set_target_properties(lib_event-2.1 PROPERTIES IMPORTED_LOCATION ${LIB_DIR}/${ANDROID_ABI}/libevent-2.1.so)







# 编译库
add_library(native-qcard SHARED qcard.cpp)
add_library(native-sdmp SHARED sdmp.cpp)
add_library(cJSON SHARED cJSON.c)

# 链接
target_link_libraries(native-qcard lib_crypto lib_curl lib_sdmp lib_simkey lib_gmp lib_tysimkeylib lib_uv lib_z log cJSON lib_event-2.1)
target_link_libraries(native-sdmp lib_crypto lib_curl lib_sdmp lib_simkey lib_gmp lib_tysimkeylib lib_uv lib_z log cJSON lib_event-2.1)
