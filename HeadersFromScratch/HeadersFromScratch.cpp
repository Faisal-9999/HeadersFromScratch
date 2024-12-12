#include <iostream>
#include "string.h"



int main(){

	string a = "joe Biden";
	string b = "joe Biden";

	if (a == b) {
		std::cout << "Same";
	}
	else {
		std::cout << "Not same";
	}
}