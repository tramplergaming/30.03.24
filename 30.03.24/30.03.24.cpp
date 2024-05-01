#include <iostream>
#include <cstdlib>
#include <Windows.h>

//#1

const int size1 = 100;
const int seqSize = 10;

int findMinSumSequence(int* arr, int startId = 0, int minStartId = 0, int minSum = 2147483647)
{
    if (startId + seqSize > size1) 
    {
        return minStartId;
    }

    int currSum = 0;
    for (int i = startId; i < startId + seqSize; ++i) 
    {
        currSum += arr[i];
    }

    if (currSum < minSum) 
    {
        minSum = currSum;
        minStartId = startId;
    }

    return findMinSumSequence(arr, startId + 1, minStartId, minSum);
}

//#2

template <typename T, size_t N>
T findMax(T(&arr)[N]) 
{
    return *std::max_element(arr, arr + N);
}

template <typename T, size_t Rows, size_t Cols>
T findMax(T(&arr)[Rows][Cols]) 
{
    T maxVal = arr[0][0];
    for (size_t i = 0; i < Rows; ++i) 
    {
        for (size_t j = 0; j < Cols; ++j) 
        {
            maxVal = max(maxVal, arr[i][j]);
        }
    }
    return maxVal;
}

template <typename T, size_t Depth, size_t Rows, size_t Cols>
T findMax(T(&arr)[Depth][Rows][Cols]) 
{
    T maxVal = arr[0][0][0];
    for (size_t i = 0; i < Depth; ++i) 
    {
        for (size_t j = 0; j < Rows; ++j) 
        {
            for (size_t k = 0; k < Cols; ++k) 
            {
                maxVal = max(maxVal, arr[i][j][k]);
            }
        }
    }
    return maxVal;
}

int findMax(int a, int b) 
{
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) 
{
    return max(a, max(b, c));
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr1[] = {3, 1, 4, 1, 5, 9};
    int arr2[3][2] = {{1, 5}, {3, 7}, {2, 4}};
    int arr3[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    int arr[size1];

    srand(time(NULL));

    for (int i = 0; i < size1; ++i)
    {
        arr[i] = rand() % 100 + 1;
    }

    int startIdx = findMinSumSequence(arr);
    
    std::cout << "======ЗАДАНИЕ 1======";

    std::cout << "\n\nНачальная позиция минимальной последовательности: " << startIdx;

    std::cout << "\n\n======ЗАДАНИЕ 1======";

    std::cout << "\n\nМаксимум в arr1: " << findMax(arr1);
    std::cout << "\nМаксимум в arr2: " << findMax(arr2);
    std::cout << "\nМаксимум в arr3: " << findMax(arr3);
    std::cout << "\nМаксимум из 2 и 5: " << findMax(2, 5);
    std::cout << "\nМаксимум из 1, 4 и 9: " << findMax(1, 4, 9);

    return 0;
}