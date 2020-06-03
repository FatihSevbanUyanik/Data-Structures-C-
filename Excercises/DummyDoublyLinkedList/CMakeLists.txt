cmake_minimum_required(VERSION 3.12)
project(DummyDoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DummyDoublyLinkedList main.cpp DoublyLinkedList.cpp DoublyLinkedList.h CircularLinkedList.cpp CircularLinkedList.h)