#pragma once

#include <iostream>

class string {
private:

	char* data;
	size_t length;

public:

	string() : data(new char[1]), length(0) {
		data[0] = '\0';
	}

	string(const char* word) {

		int length = 0;

		const char* pointer = word;

		while (*pointer != '\0') {
			length++;
			pointer++;
		}

		data = new char[length + 1];

		for (size_t i = 0; i < length; i++) {
			data[i] = word[i];
		}

		this->length = length;
		data[length] = '\0';
	}

	string(const string& word) {
		data = new char[word.length];
		
		for (size_t i = 0; i < word.length; i++) {
			data[i] = word.data[i];
		}

		this->length = word.length;
	}

	string(string&& word) {

		data = word.data;
		length = word.length;

		word.data = nullptr;
		word.length = 0;
	}

	~string() {
		delete[] data;
		data = nullptr;
		length = 0;
	}

	string& operator=(string&& word) {

		delete[] data;

		data = word.data;
		length = word.length;

		word.data = nullptr;
		word.length = 0;

		return *this;
	}

	string& operator=(const string& word) {
		delete[] data;

		data = new char[word.length];

		for (size_t i = 0; i < word.length; i++) {
			data[i] = word.data[i];
		}

		this->length = word.length;

		return *this;
	}

	string& operator=(const char* word) {

		delete[] data;

		int length = 0;

		const char* pointer = word;

		while (*pointer != '\0') {
			length++;
			pointer++;
		}

		data = new char[length + 1];

		for (size_t i = 0; i < length; i++) {
			data[i] = word[i];
		}

		this->length = length;
		data[length] = '\0';

		return *this;
	}

	char& operator[](const size_t& index) {

		if (index < 0 || index > length) {
			throw std::out_of_range("Out of bounds indexing");
		}

		return data[index];
	}

	bool operator==(string& word) {
		if (length != word.length) {
			return false;
		}

		for (size_t i = 0; i < word.length; i++) {
			if ((*this)[i] != word[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!=(string& word) {
		return !(*this == word);
	}


	const size_t size() const {
		return length;
	}


};

