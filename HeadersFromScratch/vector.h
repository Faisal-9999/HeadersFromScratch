#pragma once

#include <iostream>
#include <initializer_list>

template<typename T>

class vector {
private:

	T* arr;
	int length;
	int space;

public:


	vector() {
		length = 0;
		space = 1;
		arr = new T[space];
	}

	vector(std::initializer_list<T> list) {
		length = list.size();
		space = list.size() * 2;

		arr = new T[space];

		int i = 0;

		for (const T& value : list) {
			arr[i++] = value;
		}
	}

	~vector() {
		delete[] arr;
	}

	bool operator==(vector<T>& other) {
		if (other.size() != length) {
			return false;
		}


		for (int i = 0; i < length; i++){
			if (arr[i] != other[i]) {
				return false;
			}
		}

		return true;
	}
	
	bool operator!= (const vector<T>& other) {
		return !(*this == other);
	}

	T& operator[] (int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Out of bound indexing");
		}


		return arr[index];
	}

	void push_back(T object) {

		if (length == space) {
			space *= 2;

			T* arr2 = new T[space];

			for (int i = 0; i < length; i++) {
				arr2[i] = arr[i];
			}

			delete[] arr;
			arr = arr2;
		}


		arr[length] = object;
		length++;
	}

	T pop_back() {

		if (length == 0) {
			throw "Segmentation Fault";
		}

		length--;
		return arr[length];
	}

	void resize(int size) {
		if (size < 0) {
			throw "Invalid Operation";
		}

		if (size == 0) {
			delete[] arr;
			arr = nullptr;
			length = 0;
			return;
		}

		T* arr2 = new T[size];

		if (size > length) {
			for (int i = 0; i < length; i++) {
				arr2[i] = arr[i];
			}
		}
		else if(size < length) {
			for (int i = 0; i < size; i++) {
				arr2[i] = arr[i];
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				arr2[i] = arr[i];
			}
		}

		delete[] arr;

		arr = arr2;
		space = size;
		length = size;
	}

	void clear() {
		delete[] arr;
		arr = nullptr;
		length = 0;
		space = 1;

		arr = new T[space];
	}

	void shrink_to_fit() {

		if (length == 0) {
			delete[] arr;
			arr = nullptr;

			space = 0;
			return;
		}

		T* arr2 = new T[length];
		space = length;

		for (int i = 0; i < length; i++) {
			arr2[i] = arr[i];
		}

		delete[] arr;
		arr = arr2;
	}

	T* begin() {
		return arr;
	}

	T* end() {
		return arr + length;
	}

	T& front() {
		if (length == 0) {
			throw std::out_of_range("Vector is empty");
		}

		return arr[0];
	}

	T& back() {
		if (length == 0) {
			throw std::out_of_range("Vector is empty");
		}

		return arr[length - 1];
	}

	template<typename... Arguments>
	void emplace_back(Arguments&& args) {
		if (length == space) {
			resize(space * 2);
		}

		new (&arr[length]) T(std::forward<Arguments>(args));
	}

	int size() {
		return length;
	}

	int max_size() {
		return space;
	}

	bool empty() {
		return length == 0;
	}
};