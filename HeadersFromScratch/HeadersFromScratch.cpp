#include <iostream>
#include <cassert>
#include "vector.h" // Include your vector class header here

void test_reserve() {
    vector<int> vec;
    vec.reserve(10);
    assert(vec.max_size() >= 10 && "test_reserve: Reserve capacity failed");
}

void test_clear() {
    vector<int> vec = { 1, 2, 3, 4 };
    vec.clear();
    assert(vec.size() == 0 && "test_clear: Size after clear failed");
    assert(vec.max_size() >= 4 && "test_clear: Capacity after clear failed");
}

void test_front_and_back() {
    vector<int> vec = { 10, 20, 30, 40 };
    assert(vec.front() == 10 && "test_front_and_back: Front element failed");
    assert(vec.back() == 40 && "test_front_and_back: Back element failed");
}

void test_erase() {
    vector<int> vec = { 1, 2, 3, 4, 5 };
    vec.erase(2);
    assert(vec.size() == 4 && "test_erase: Size after erase failed");
    assert(vec[2] == 4 && "test_erase: Element shift after erase failed");
}

void test_insert() {
    vector<int> vec = { 1, 2, 3, 4 };
    vec.insert(2, 99);
    assert(vec.size() == 5 && "test_insert: Size after insert failed");
    assert(vec[2] == 99 && "test_insert: Inserted value incorrect");
    assert(vec[3] == 3 && "test_insert: Element shift after insert failed");
}

void test_shrink_to_fit() {
    vector<int> vec = { 1, 2, 3, 4 };
    vec.reserve(10);
    vec.shrink_to_fit();
    assert(vec.max_size() == vec.size() && "test_shrink_to_fit: Shrink to fit failed");
}

void test_self_assignment() {
    vector<int> vec = { 1, 2, 3 };
    vec = vec;
    assert(vec.size() == 3 && "test_self_assignment: Size after self-assignment failed");
    assert(vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && "test_self_assignment: Elements after self-assignment failed");
}

void test_copy_constructor() {
    vector<int> vec1 = { 10, 20, 30 };
    vector<int> vec2 = vec1;
    assert(vec2.size() == 3 && "test_copy_constructor: Size of copied vector failed");
    assert(vec2[0] == 10 && vec2[1] == 20 && vec2[2] == 30 && "test_copy_constructor: Copied elements incorrect");
}

void test_move_constructor() {
    vector<int> vec1 = { 5, 10, 15 };
    vector<int> vec2 = std::move(vec1);
    assert(vec1.size() == 0 && "test_move_constructor: Original vector not empty after move");
    assert(vec2.size() == 3 && "test_move_constructor: Moved vector size failed");
    assert(vec2[0] == 5 && vec2[1] == 10 && vec2[2] == 15 && "test_move_constructor: Moved elements incorrect");
}

void test_resize() {
    vector<int> vec = { 1, 2, 3 };
    vec.resize(5, 99);
    assert(vec.size() == 5 && "test_resize: Size after resize failed");
    assert(vec[3] == 99 && vec[4] == 99 && "test_resize: Resized elements incorrect");
}

void test_out_of_bounds() {
    vector<int> vec = { 1, 2, 3 };
    try {
        int value = vec[5];
        assert(false && "test_out_of_bounds: Did not throw exception for out-of-bounds access");
    }
    catch (const std::out_of_range&) {
        // Exception is expected
    }
}

void test_swap() {
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2 = { 4, 5 };
    vec1.swap(vec2);
    assert(vec1.size() == 2 && "test_swap: Size of vec1 after swap failed");
    assert(vec2.size() == 3 && "test_swap: Size of vec2 after swap failed");
    assert(vec1[0] == 4 && vec2[0] == 1 && "test_swap: Elements after swap incorrect");
}

void test_iterators() {
    vector<int> vec = { 1, 2, 3, 4 };
    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        sum += *it;
    }
    assert(sum == 10 && "test_iterators: Iterator sum failed");
}

void test_default_constructor() {
    vector<int> vec;
    assert(vec.size() == 0 && "test_default_constructor: Default constructor size failed");
    assert(vec.capacity() == 0 || vec.capacity() >= 0 && "test_default_constructor: Default constructor capacity failed");
}

void test_push_back() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    assert(vec.size() == 3 && "test_push_back: Size after push_back failed");
    assert(vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && "test_push_back: Elements after push_back incorrect");
}

void test_pop_back() {
    vector<int> vec = { 1, 2, 3 };
    vec.pop_back();
    assert(vec.size() == 2 && "test_pop_back: Size after pop_back failed");
    assert(vec[1] == 2 && "test_pop_back: Remaining elements after pop_back incorrect");
    try {
        vec.pop_back();
        vec.pop_back();
        vec.pop_back(); // Should throw exception
        assert(false && "test_pop_back: Did not throw exception when popping empty vector");
    }
    catch (...) {
        // Exception is expected
    }
}

void run_all_tests() {
    try {
        test_reserve();
        test_clear();
        test_front_and_back();
        test_erase();
        test_insert();
        test_shrink_to_fit();
        test_self_assignment();
        test_copy_constructor();
        test_move_constructor();
        test_resize();
        test_out_of_bounds();
        test_swap();
        test_iterators();
        test_default_constructor();
        test_push_back();
        test_pop_back();

        std::cout << "All tests passed successfully!" << std::endl;
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
}

int main() {
    run_all_tests();
    return 0;
}
