#include <iostream>
#include "string.h"


int main(){

	string a = "hello";
	string b = "hello";


	if (a == b) {
		std::cout << "Same";
	}
	else {
		std::cout << "Not same";
	}

}