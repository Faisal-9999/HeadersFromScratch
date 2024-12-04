// HeadersFromScratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> arr = { 1, 2, 3, 4 };

    vector<int>arr3(arr);

	for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << std::endl;
    }

    std::cout << arr3.max_size();
}