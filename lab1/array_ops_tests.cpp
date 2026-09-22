#include <array_ops.h>
#include <gtest/gtest.h>


TEST(ArrayMemTest, CorrectCreate) {
    std::size_t size = 5;
    int *arr = array_create(5);

    ASSERT_NE(arr, nullptr);

    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(arr[i], 0);
    }

    delete[] arr;
}

TEST(ArrayMemTest, CreateWithZeroElements) {
    int *arr = array_create(0);

    ASSERT_NE(arr, nullptr);

    delete[] arr;
}

TEST(ArrayMemTest, CorrectDelete) {
    int *arr = array_create(5);

    ASSERT_NE(arr, nullptr);

    array_delete(arr);

    ASSERT_EQ(arr, nullptr);
}

TEST(ArrayMemTest, DeleteHandlesNullptrSafely) {
    int *arr = nullptr;

    ASSERT_NO_THROW({ array_delete(arr); });
}

TEST(ArrayMemTest, CorrectResize) {
    int *arr = array_create(3);

    std::size_t new_size = 5;
    array_resize(arr, 3, new_size);

    for (int i = 0; i < new_size; ++i) {
        ASSERT_EQ(arr[i], 0);
    }

    array_delete(arr);
}

TEST(ArrayOpsTest, CorrectInsert) {
    std::size_t size = 0;
    int *arr = array_create(size);

    array_insert(arr, size, 0, 3);
    array_insert(arr, size, 0, 1);
    array_insert(arr, size, 2, 4);
    array_insert(arr, size, 1, 2);

    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(arr[i], i + 1);
    }

    array_delete(arr);
}

TEST(ArrayOpsTest, CorrectRemove) {
    std::size_t size = 5;
    int *arr = array_create(size);

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    array_remove(arr, size, 3);
    ASSERT_EQ(size, 4);
    ASSERT_EQ(arr[0], 0);
    ASSERT_EQ(arr[1], 1);
    ASSERT_EQ(arr[2], 2);
    ASSERT_EQ(arr[3], 4);


    array_remove(arr, size, 0);
    ASSERT_EQ(size, 3);
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[2], 4);

    array_remove(arr, size, 2);
    ASSERT_EQ(size, 2);
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);

    array_delete(arr);
}

TEST(ArrayOpsTest, CorrectRotateLeft) {
    std::size_t size = 5;
    int *arr = array_create(size);

    for (int i = 0; i < size; ++i) {
        arr[i] = size - i;
    }

    array_rotate_left(arr, size, 3);

    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(arr[i], (i + 3) % 5 + 1);
    }

    array_delete(arr);
}