#include <iostream>
#include <string>
#include <direct.h>
#include "ExpressBoilerplate.cpp"
#include "FlaskBoilerplate.cpp"

using namespace std;

void chooseExpressOption() {

	ExpressBoilerplate e;

	string folderLocationString;
	const char* folderLocation;

	std::cout << "\nEnter location where express boilerplate is to be created: ";
	std::cin >> folderLocationString;

	folderLocation = folderLocationString.c_str();
	
	if (_mkdir(folderLocation) == -1) {
		std::cout << "There has been an issue creating the express boilerplate folder." << endl;
	}
	else {
		std::cout << "\n-- Express boilerplate folder created..." << endl;
		e.createExpressBoilerplateFiles(folderLocationString);
		e.updateExpressBoilerplateFiles(folderLocationString);
	}

}

void chooseFlaskOption() {

	FlaskBoilerplate f;

	string folderLocationString;
	const char* folderLocation;

	std::cout << "\nEnter location where flask boilerplate is to be created: ";
	std::cin >> folderLocationString;

	folderLocation = folderLocationString.c_str();

	if (_mkdir(folderLocation) == -1) {
		std::cout << "There has been an issue creatng the flask boilerplate folder." << endl;
	}
	else {
		std::cout << "\n-- Flask boilerplate folder created..." << endl;
		f.createFlaskBoilerplateFiles(folderLocationString);
		f.updateFlaskBoilerplateFiles(folderLocationString);
	}

}

int main() {

	string inputString;
	int inputInt;

	std::cout << "\nWeb-server boilerplate generator\n\n" <<
		"  [1] : Node.js (with Express.js)\n" <<
		"  [2] : Python Flask\n\n"
		<< "Choose language: ";
	std::cin >> inputString;

	inputInt = std::stoi(inputString);

	switch (inputInt) {
		case 1:
			chooseExpressOption();
			break;
		case 2:
			chooseFlaskOption();
			break;
		default:
			std::cout << "\nPlease choose the right option." << endl;
			break;
	}

	return 0;
}