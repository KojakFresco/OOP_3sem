#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <iostream>

int* array_create(std::size_t size = 0) {
    int* array = new int[size]();
    return array;
}

void array_delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

void array_resize(int*& arr, std::size_t size, std::size_t new_size) {
    int* new_arr = new int[new_size]();

    for (int i = 0; i < std::min(size, new_size); ++i) {
        new_arr[i] = arr[i];
    }
    array_delete(arr);

    arr = new_arr;
}

void array_insert(int*& arr, std::size_t& size, std::size_t pos, int value) {
    if (pos > size) {
        throw std::invalid_argument("pos value should be less than or equal to size");
    }

    array_resize(arr, size, size + 1);
    for (std::size_t i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    ++size;
}

void array_remove(int*& arr, std::size_t& size, std::size_t pos) {
    if (pos >= size) {
        throw std::invalid_argument("pos value should be less than arr size");
    }

    for (std::size_t i = pos; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    array_resize(arr, size, size - 1);
    --size;
}

void array_print(const int* arr, const std::size_t size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i != size - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void reverse(int* arr, const std::size_t size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void array_rotate_left(int*& arr, const std::size_t size, std::size_t k) {
    for (int i = 0; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        ++j;
        arr[j] = key;
    }

    k %= size;

    reverse(arr, k);
    reverse(&arr[k], size - k);
    reverse(arr, size);
}
