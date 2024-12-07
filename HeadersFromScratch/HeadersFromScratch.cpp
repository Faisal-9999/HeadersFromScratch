#include <iostream>
#include <stdexcept>
#include "vector.h" // Replace with your custom vector class header file

void testInitialization() {
    vector<int> v;
    if (v.size() != 0) {
        std::cout << "FAIL: vector initialization size test\n";
    }
    else {
        std::cout << "PASS: vector initialization size test\n";
    }
}

void testPushBack() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    if (v.size() != 2 || v[0] != 10 || v[1] != 20) {
        std::cout << "FAIL: push_back test\n";
    }
    else {
        std::cout << "PASS: push_back test\n";
    }
}

void testPopBack() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();

    if (v.size() != 1 || v[0] != 10) {
        std::cout << "FAIL: pop_back test\n";
    }
    else {
        std::cout << "PASS: pop_back test\n";
    }

    v.pop_back();
    try {
        v.pop_back(); // Should handle empty vector safely
        std::cout << "PASS: pop_back on empty vector test\n";
    }
    catch (std::underflow_error& e) {
        std::cout << "PASSED" << std::endl;
    }
    catch (...) {
        std::cout << "FAIL: pop_back on empty vector test\n";
    }
 
}

void testAtFunction() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    if (v.at(0) != 10 || v.at(1) != 20) {
        std::cout << "FAIL: at() function test\n";
    }
    else {
        std::cout << "PASS: at() function test\n";
    }

    try {
        v.at(2); // Out-of-bounds
        std::cout << "FAIL: at() out-of-bounds test\n";
    }
    catch (std::out_of_range&) {
        std::cout << "PASS: at() out-of-bounds test\n";
    }
}

void testClear() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.clear();

    if (v.size() != 0) {
        std::cout << "FAIL: clear test\n";
    }
    else {
        std::cout << "PASS: clear test\n";
    }
}

void testOperatorBracket() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    if (v[0] != 10 || v[1] != 20) {
        std::cout << "FAIL: operator[] test\n";
    }
    else {
        std::cout << "PASS: operator[] test\n";
    }

    try {
        v[2] = 30; // Out-of-bounds
        std::cout << "FAIL: operator[] out-of-bounds test\n";
    }
    catch (...) {
        std::cout << "PASS: operator[] out-of-bounds test\n";
    }
}

int main() {
    testInitialization();
    testPushBack();
    testPopBack();
    testAtFunction();
    testClear();
    testOperatorBracket();

    return 0;
}
