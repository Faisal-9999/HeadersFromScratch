// HeadersFromScratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> arr = { 1, 2, 3, 4 };
    
    arr.insert(10, 3);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
}