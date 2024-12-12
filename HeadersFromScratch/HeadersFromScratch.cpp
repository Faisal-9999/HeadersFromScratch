#include <iostream>
#include <cassert>
#include <string>
#include "vector.h"
#include <stdexcept>

void testVectorObscureFunctions() {
    try {


        // Test Case: Swap
        vector<int> vec5{ 1, 2, 3 };
        vector<int> vec6{ 4, 5 };
        vec5.swap(vec6);
        assert(vec5.size() == 2 && vec6.size() == 3 && "swap should exchange sizes.");
        assert(vec5[0] == 4 && vec6[0] == 1 && "swap should exchange elements.");

        // Test Case: Assign
        vec5.assign(4, 7);  // Assign four elements of value 7
        assert(vec5.size() == 4 && vec5[0] == 7 && vec5[3] == 7 &&
            "assign should replace the vector contents with new values.");

        // Test Case: Front and Back
        vector<int> vec7{ 5, 10, 15 };
        assert(vec7.front() == 5 && "front should return the first element.");
        assert(vec7.back() == 15 && "back should return the last element.");

        // Test Case: Data
        int* data = vec7.data();
        assert(data[0] == 5 && data[1] == 10 && "data should return a pointer to the underlying array.");

        // Test Case: Emplace Back
        vector<std::pair<int, std::string>> vec8;
        vec8.emplace_back(1, "one");
        assert(vec8.size() == 1 && vec8[0].first == 1 && vec8[0].second == "one" &&
            "emplace_back should construct elements in place.");


        // Test Case: Emplace at Position
        vec8.emplace(vec8.begin(), 0, "zero");
        assert(vec8.size() == 2 && vec8[0].first == 0 && vec8[0].second == "zero" &&
            "emplace should construct elements in place at the specified position.");

        std::cout << "All obscure function tests passed successfully!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << "\n";
    }
}

int main() {
    testVectorObscureFunctions();


}