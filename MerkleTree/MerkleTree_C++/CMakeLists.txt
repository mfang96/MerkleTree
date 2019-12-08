cmake_minimum_required(VERSION 3.9)
project(MerkleTree)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

include_directories("/usr/local/opt/openssl/include")
#link_directories("/usr/local/opt/openssl/lib")
link_libraries("/usr/local/opt/openssl/lib/libcrypto.a")

add_executable(MerkleTree
        main.cpp
        Node.cpp
        Node.h
        MTree.cpp
        MTree.h
        )
