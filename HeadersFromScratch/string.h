#pragma once

#include <iostream>

class string {
private:
	char* data;
	size_t length;
public:

	string(const char* word) {
		
		data = new char[strlen(word)];
		
		int index = 0;
		while (true) {
			data[index++] = *word;
			if (*word == '\0') {
				break;
			}
			word++;
		}

		length = strlen(word);
	}

	string(const char* word, size_t length) {

		data = new char[length + 1];
		this->length = length + 1;

		data[length] = '\0';

		for (size_t i = 0; i < length; i++) {
			data[i] = word[i];
		}

	}

	string(const string& String) {
		data = String.data;
		length = String.length;
	}

	string& operator=(const char* word) {
		delete[] data;

		data = new char[strlen(word) + 1];

		return *this;
	}

	char& operator[] (int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Out of bounds indexing");
		}

		return data[index];
	}

	bool operator==(const string& word) {
		if (length != word.length) {
			return false;
		}

		for (size_t i = 0; i < word.size(); i++) {
			if (data[i] != word.data[i]) {
				return false;
			}
		}

		return true;
	}

	void print() {
		char* current = data;

		while (*current != '\0') {
			std::cout << *current;
			current++;
		}
	}

	size_t size() const {
		return length;
	}
};

