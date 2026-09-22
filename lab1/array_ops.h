#pragma once
#include <cstddef>

int* array_create(std::size_t size = 0); // new int[size], +1 слот под '\0' не нужен
void array_delete(int*& arr); // delete[] и обнулить указатель
void array_resize(int*& arr, std::size_t size, std::size_t new_size); // новая память + копия
void array_insert(int*& arr, std::size_t& size, std::size_t pos, int value); // вставка
void array_remove(int*& arr, std::size_t& size, std::size_t pos); // удаление
void array_print(const int* arr, std::size_t size);
void array_rotate_left(int*& arr, size_t size, size_t k);