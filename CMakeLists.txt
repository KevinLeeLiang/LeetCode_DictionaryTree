cmake_minimum_required(VERSION 3.17)
project(DictionaryTree)

set(CMAKE_CXX_STANDARD 17)
include_directories(util)
add_executable(DictionaryTree main.cpp util/util.h test_factory.h L14_longestCommonPrefix/L14_longestCommonPrefix.cpp L14_longestCommonPrefix/L14_longestCommonPrefix.h L139_wordBreak/L139_wordBreak.cpp L139_wordBreak/L139_wordBreak.h)