// HeadersFromScratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> arr = { 1, 2, 3, 4 };
    vector<int> arr2 = { 5, 6, 7, 8 };

    vector<int> arr3 = arr + arr2;

    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << std::endl;
    }

    std::cout << arr3.size() << std::endl;
    std::cout << arr3.max_size() << std::endl;
}