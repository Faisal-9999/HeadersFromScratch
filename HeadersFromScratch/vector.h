#pragma once

#include <iostream>
#include <iterator>
#include <initializer_list>


template<typename T>
class ConstReverseIterator {
private:
	T* arr;
public:

	static int count;

	ConstReverseIterator(T* arr) : arr(arr) {}

	ConstReverseIterator<T>& operator++() {
		--arr;
		return *this;
	}

	ConstReverseIterator<T> operator++(int) {
		ConstReverseIterator<T> holder = *this;
		--arr;

		return holder;
	}

	ConstReverseIterator<T>& operator--() {
		++arr;
		return *this;
	}

	ConstReverseIterator<T> operator--(int) {
		ConstReverseIterator<T> holder = *this;
		++arr;

		return holder;
	}

	bool operator!= (const ConstReverseIterator<T>& other) {
		return !(arr == other.arr);
	}

	bool operator== (const ConstReverseIterator<T>& other) {
		return arr == other.arr;
	}

	T& operator*() {
		return *arr;
	}
};

template<typename T>
class ConstIterator {
private:

	T* arr;

public:

	ConstIterator(T* arr) : arr(arr) {}

	ConstIterator<T>& operator++() {
		++arr;
		return *this;
	}

	ConstIterator<T> operator++(int) {
		ConstIterator<T> holder = *this;
		++arr;
		return holder;
	}

	ConstIterator<T> operator--() {
		--arr;
		return *this;
	}

	ConstIterator<T> operator--(int) {
		ConstIterator<T> holder = *this;
		
		--arr;

		return holder;
	}

	bool operator==(const ConstIterator<T>& other) {
		return arr == other.arr;
	}

	bool operator!=(const ConstIterator<T>& other) {
		return !(arr == other.arr);
	}

	T& operator*() {
		return *arr;
	}
};

template<typename T>
class vector {
private:

	T* arr;
	size_t length;
	size_t space;

public:
	using ConstReverseIterator = ConstReverseIterator<T>;
	using ConstIterator = ConstIterator<T>;

	vector() : length(0), space(1) {
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

	vector(const vector<T>& Vector) {
		this->length = Vector.length;
		this->space = Vector.length * 2;

		delete[] arr;
		arr = new T[space];

		for (int i = 0; i < length; i++) {
			arr[i] = Vector.arr[i];
		}
	}

	~vector() {
		delete[] arr;
	}

	vector& operator= (vector<T>& Vector) {
		if (this == &Vector){
			return *this;
		}

		this->length = Vector.length;
		this->space = Vector.space;

		delete[] arr;
		arr = new T[space];

		for (int i = 0; i < length; i++) {
			arr[i] = Vector.arr[i];
		}

		return *this;
	}

	vector<T>& operator= (std::initializer_list<T> list) {
		delete[] arr;
		length = list.size();
		space = length * 2;

		arr = new T[space];

		int i = 0;

		for (const T& value : list) {
			arr[i++] = value;
		}

		return *this;
	}

	bool operator==(vector<T>& other) {
		if (other.length != length) {
			return false;
		}


		for (int i = 0; i < length; i++){
			if (arr[i] != other[i]) {
				return false;
			}
		}

		return true;
	}
	
	bool operator!= (vector<T>& other) {
		return !(*this == other);
	}

	T& operator[] (int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Out of bound indexing");
		}


		return arr[index];
	}

	void push_back(const T& object) {

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
			throw std::underflow_error("vector already empty");
		}

		length--;
		return arr[length];
	}

	void resize(int size) {
		if (size <= 0) {
			throw std::invalid_argument("Invalid Operation");
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

	void erase(int index) {

		if (empty()) {
			throw std::invalid_argument("Can't erase elements in an empty vector");
		}

		if (index < 0 || index >= length) {
			throw std::out_of_range("Out of bounds indexing");
		}


		T* holder = new T[length - 1];

		int index1 = 0;
		int index2 = 0;

		while (index1 < length - 1) {
			if (index2 == index) {
				index2++;
			}

			holder[index1++] = arr[index2++];
		}

		delete[] arr;
		arr = holder;

		length--;

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

	void reserve(int amount) {

		if (amount <= space){
			return;
		}

		T* arr = new T[amount];

		for (int i = 0; i < length; i++) {
			arr[i] = this->arr[i];
		}

		delete[] this->arr;

		this->arr = arr;
		space = amount;
	}

	void assign(int lengthOfAssign, T& value) {
		if (lengthOfAssign <= 0) {
			return;
		}

		if (lengthOfAssign > space){
			reserve(lengthOfAssign);
		}

		for (int i = 0; i < lengthOfAssign; i++) {
			arr[i] = value;
		}
	}

	template<typename... Arguments>
	void emplace_back(Arguments&&... args) {
		if (length == space) {
			resize(space * 2);
		}

		new (&arr[length]) T(std::forward<Arguments>(args)...);
	}

	void insert(const T& value, int index) {

		if (index < 0 || index > length) {
			throw std::out_of_range("Out of bounds indexing");
		}

		T* arr = new T[length + 1];

		arr[index] = value;

		int index1 = 0;
		int index2 = 0;

		while (index2 < length) {
			if (index1 == index) {
				index1++;
			}
			else {
				arr[index1++] = this->arr[index2++];
			}
		}

		length++;
		delete[] this->arr;

		this->arr = arr;
	}

	void swap(vector<T>& other) {
		T* temp = other.arr;
		other.arr = arr;
		arr = temp;

		int temp2 = other.length;
		other.length = length;
		length = temp2;

		temp2 = other.space;
		other.space = space;
		space = temp2;
	}

	T& at(int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Out of bounds indexing");
		}

		return arr[index];
	}

	T* data() {
		return arr;
	}

	//solve this shit after waking up

	ConstReverseIterator crbegin() {
		return ConstReverseIterator(arr + length - 1);
	}

	ConstReverseIterator crend() {
		return ConstReverseIterator(arr - 1);
	}

	ConstIterator cbegin() const {
		return ConstIterator(arr);
	}

	ConstIterator cend()  const {
		return ConstIterator(arr + length);
	}

	size_t size() {
		return length;
	}

	size_t max_size() {
		return space;
	}

	bool empty() {
		return length == 0;
	}
};