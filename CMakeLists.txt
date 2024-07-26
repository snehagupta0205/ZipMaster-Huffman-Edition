cmake_minimum_required(VERSION 3.0)
project(HuffmanCoding)

# Add executable for encoding
add_executable(huffmanCoding main.cpp huffman.cpp)

# Add executable for decoding
add_executable(huffmanDecoding huffmandecoding.cpp huffman.cpp)

# Set output directories
set_target_properties(huffmanCoding PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(huffmanDecoding PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
