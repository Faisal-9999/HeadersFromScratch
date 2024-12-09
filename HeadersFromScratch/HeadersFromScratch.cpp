#include <iostream>
#include <assert.h>
#include "vector.h"

void test_at() {
    vector<int> vec = { 1, 2, 3 };
    assert(vec.at(0) == 1 && "test_at: At index 0 failed");
    assert(vec.at(1) == 2 && "test_at: At index 1 failed");
    assert(vec.at(2) == 3 && "test_at: At index 2 failed");

    try {
        vec.at(5);  // Should throw exception
        assert(false && "test_at: Did not throw exception for out-of-bounds access");
    }
    catch (const std::out_of_range&) {
        // Expected exception
    }
}

void test_resize_without_value() {
    vector<int> vec = { 1, 2, 3 };
    vec.resize(5);  // New size, default-constructed elements (typically 0 for integers)
    assert(vec.size() == 5 && "test_resize_without_value: Size after resize failed");
    assert(vec[3] == 0 && "test_resize_without_value: New elements should be default-initialized");
    assert(vec[4] == 0 && "test_resize_without_value: New elements should be default-initialized");

    vec.resize(2);  // Shrink size
    assert(vec.size() == 2 && "test_resize_without_value: Size after shrink failed");
    assert(vec[0] == 1 && "test_resize_without_value: Elements after shrinking failed");
    assert(vec[1] == 2 && "test_resize_without_value: Elements after shrinking failed");
}

void test_copy_assignment_operator() {
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2;
    vec2 = vec1;  // Use the copy assignment operator

    assert(vec2.size() == 3 && "test_copy_assignment_operator: Size after copy assignment failed");
    assert(vec2[0] == 1 && vec2[1] == 2 && vec2[2] == 3 && "test_copy_assignment_operator: Elements after copy assignment failed");

    // Make sure it handles self-assignment correctly
    vec1 = vec1;  // Self-assignment should not cause issues
    assert(vec1.size() == 3 && "test_copy_assignment_operator: Self-assignment failed");
    assert(vec1[0] == 1 && vec1[1] == 2 && vec1[2] == 3 && "test_copy_assignment_operator: Self-assignment failed");
}

void test_move_assignment_operator() {
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2;
    vec2 = std::move(vec1);  // Use the move assignment operator

    assert(vec2.size() == 3 && "test_move_assignment_operator: Size after move assignment failed");
    assert(vec2[0] == 1 && vec2[1] == 2 && vec2[2] == 3 && "test_move_assignment_operator: Elements after move assignment failed");
    assert(vec1.size() == 0 && "test_move_assignment_operator: Original vector should be empty after move assignment");

    // Ensure no unintended data copying
    vec2.push_back(4);
    assert(vec2.size() == 4 && "test_move_assignment_operator: Size after push_back on moved vector failed");
}

void test_initialization_with_range() {
    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2(vec1.begin(), vec1.end());  // Initialize a new vector using a range of another vector

    assert(vec2.size() == 3 && "test_initialization_with_range: Size after range initialization failed");
    assert(vec2[0] == 1 && vec2[1] == 2 && vec2[2] == 3 && "test_initialization_with_range: Elements after range initialization failed");
}

void test_push_back_with_large_data() {
    vector<int> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i);
    }
    assert(vec.size() == 1000 && "test_push_back_with_large_data: Size after many push_backs failed");
    assert(vec[999] == 999 && "test_push_back_with_large_data: Last element after push_back failed");
}

void test_pop_back_with_single_element() {
    vector<int> vec = { 10 };
    vec.pop_back();
    assert(vec.size() == 0 && "test_pop_back_with_single_element: Size after pop_back failed");
}

void test_push_back_after_resize() {
    vector<int> vec = { 1, 2, 3 };
    vec.resize(5);  // Increase size
    vec.push_back(4);  // Add a new element
    assert(vec.size() == 6 && "test_push_back_after_resize: Size after push_back failed");
    assert(vec[5] == 4 && "test_push_back_after_resize: New element after push_back failed");
}

void test_insert_at_beginning() {
    vector<int> vec = { 2, 3, 4 };
    vec.insert(0, 1);  // Insert at the beginning
    assert(vec.size() == 4 && "test_insert_at_beginning: Size after insert failed");
    assert(vec[0] == 1 && "test_insert_at_beginning: Element at index 0 after insert failed");
}

void test_insert_at_end() {
    vector<int> vec = { 1, 2, 3 };
    vec.insert(3, 4);  // Insert at the end
    assert(vec.size() == 4 && "test_insert_at_end: Size after insert failed");
    assert(vec[3] == 4 && "test_insert_at_end: Element at the end after insert failed");
}

void test_reverse_iterators() {
    vector<int> vec = { 1, 2, 3, 4 };
    int sum = 0;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        sum += *it;
    }
    assert(sum == 10 && "test_reverse_iterators: Reverse iterator sum failed");
}

void test_erase_range() {
    vector<int> vec = { 1, 2, 3, 4, 5 };
    vec.erase(1, 3);  // Erase the range from index 1 to 2 (2 and 3)
    assert(vec.size() == 3 && "test_erase_range: Size after range erase failed");
    assert(vec[0] == 1 && vec[1] == 4 && vec[2] == 5 && "test_erase_range: Elements after range erase incorrect");
}

void run_additional_tests() {
    try {
        test_at();
        test_resize_without_value();
        test_copy_assignment_operator();
        test_move_assignment_operator();
        test_initialization_with_range();
        test_push_back_with_large_data();
        test_pop_back_with_single_element();
        test_push_back_after_resize();
        test_insert_at_beginning();
        test_insert_at_end();
        test_reverse_iterators();
        test_erase_range();

        std::cout << "All additional tests passed successfully!" << std::endl;
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
}

int main() {
    run_additional_tests();

    return 0;
}