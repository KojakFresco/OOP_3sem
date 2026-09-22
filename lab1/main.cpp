#include <iostream>
#include <windows.h>
#include <array_ops.h>

int main() {
    // system("chcp 65001 > nul");

    int *arr;
    std::size_t size, new_size;

    int cmd, value, pos;

    while (std::cout << "1. Создать массив\t2. Напечатать\n"
           "3. Вставить элемент\t4. Удалить элемент\n"
           "5. Изменить размер\t6. Циклический сдвиг влево\n"
           "0. Выход" << std::endl && std::cin >> cmd) {
        switch (cmd) {
            case 1: {
                arr = array_create();
                size = 0;
                break;
            }
            case 2: {
                array_print(arr, size);
                break;
            }
            case 3: {
                std::cout << "Введите значение и позицию (0-индексация) через пробел" << std::endl;
                std::cin >> value >> pos;
                array_insert(arr, size, pos, value);
                break;
            }
            case 4: {
                std::cout << "Введите позицию удаляемого элемента" << std::endl;
                std::cin >> pos;
                array_remove(arr, size, pos);
                break;
            }
            case 5: {
                std::cout << "Введите новый размер массива" << std::endl;
                std::cin >> new_size;
                array_resize(arr, size, new_size);
                break;
            }
            case 6: {
                std::cout << "Введите длину сдвига" << std::endl;
                std::cin >> new_size;
                array_rotate_left(arr, size, new_size);
                break;
            }
            case 0: {
                array_delete(arr);
                return 0;
            }
            default: std::cout << "Введите команду из списка" << std::endl;
        }
    }
}
