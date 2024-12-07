// HeadersFromScratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(11);

    for (auto i = arr.cbegin(); i != arr.cend(); i++) {
        std::cout << *i << std::endl;
    }
}
