#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

class ExpressBoilerplate {
	public:

		void createExpressBoilerplateFiles(string boilerplateLocation) {

			string appFileLocationString, viewsFolderLocationString, publicFolderLocationString;
			const char* viewsFolderLocation;
			const char* publicFolderLocation;
			fstream fs;

			appFileLocationString = boilerplateLocation + "/app.js";
			viewsFolderLocationString = boilerplateLocation + "/views/";
			publicFolderLocationString = boilerplateLocation + "/public/";

			viewsFolderLocation = viewsFolderLocationString.c_str();
			publicFolderLocation = publicFolderLocationString.c_str();

			if (_mkdir(viewsFolderLocation) == -1) {
				std::cout << "There has been an issue creating the views folder." << endl;
			}
			else {
				std::cout << "-- Views folder created..." << endl;
			}

			if (_mkdir(publicFolderLocation) == -1) {
				std::cout << "There has been an issue creating the public folder." << endl;
			}
			else {
				std::cout << "-- Public folder created..." << endl;
			}

			fs.open(appFileLocationString, std::fstream::in | std::fstream::out | std::fstream::trunc);
			fs << "\n";
			fs.close();
			std::cout << "-- App file created..." << endl;

		}

		void updateExpressBoilerplateFiles(string boilerplateLocation) {
 
			string appFileLocationString, textFileLocationString, line;
			fstream textStream;
			fstream appStream;

			appFileLocationString = boilerplateLocation + "/app.js";
			textFileLocationString = "express.txt";

			textStream.open(textFileLocationString, std::fstream::in | std::fstream::out | std::fstream::app);
			appStream.open(appFileLocationString, std::fstream::in | std::fstream::out | std::fstream::app);

			while (getline(textStream, line)) {
				appStream << line << endl;
			}

			std::cout << "-- App file updated..." << endl;

		}

};