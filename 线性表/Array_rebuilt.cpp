#include <iostream>
#include <cmath>

using namespace std;

// 线性查找（无序列表）
int find_by_key_with_not_ordered(int key, const int A[], const int& length) {
    for (int i = 0; i < length; i++) {
        if (key == A[i]) {
            return i;
        }
    }
    return -1;
}

// 标准二分查找（有序列表）
int binary_search(int key, const int A[], const int& length) {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // 避免溢出
        if (key == A[mid]) {
            return mid;
        } else if (key < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// 斐波那契查找（有序列表）
int fibonacci_search(int key, const int A[], const int& length) {
    int fibMm2 = 0;  // (m-2)th Fibonacci number
    int fibMm1 = 1;  // (m-1)th Fibonacci number
    int fibM = fibMm2 + fibMm1; // mth Fibonacci number

    while (fibM < length) {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMm2, length - 1);
        if (A[i] < key) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        } else if (A[i] > key) {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        } else {
            return i;
        }
    }
    return -1;
}

// 插入元素
bool insert(int value, int place, int A[], int& length, int max_size) {
    if (length >= max_size || place < 0 || place > length) return false;
    for (int i = length; i > place; i--) {
        A[i] = A[i - 1];
    }
    A[place] = value;
    length++;
    return true;
}

// 删除元素
bool delete_by_key(int key, int A[], int& length) {
    for (int i = 0; i < length; i++) {
        if (key == A[i]) {
            for (int j = i; j < length - 1; j++) {
                A[j] = A[j + 1];
            }
            length--;
            return true;
        }
    }
    return false;
}

// 测试代码
int main() {
    const int MAX_SIZE = 100; // 数组最大长度
    int A[MAX_SIZE] = {1, 3, 5, 7, 9, 11}; // 初始数据
    int length = 6;

    cout << "线性查找 (5): " << find_by_key_with_not_ordered(5, A, length) << endl;
    cout << "二分查找 (7): " << binary_search(7, A, length) << endl;
    cout << "斐波那契查找 (11): " << fibonacci_search(11, A, length) << endl;

    if (insert(6, 3, A, length, MAX_SIZE)) {
        cout << "插入成功: ";
        for (int i = 0; i < length; i++) cout << A[i] << " ";
        cout << endl;
    } else {
        cout << "插入失败" << endl;
    }

    if (delete_by_key(5, A, length)) {
        cout << "删除成功: ";
        for (int i = 0; i < length; i++) cout << A[i] << " ";
        cout << endl;
    } else {
        cout << "删除失败" << endl;
    }

    return 0;
}