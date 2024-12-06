// HeadersFromScratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> arr = {1, 2, 3};
 
    int* a = arr.data();

    for (int i = 0; i < arr.size(); i++) {
        std::cout << *(a + i) << std::endl;
    }

}