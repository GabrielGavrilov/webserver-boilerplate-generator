#include <iostream>
#include <fstream>
#include <direct.h>
#include <string>

using namespace std;

class FlaskBoilerplate {
	public:

		void createFlaskBoilerplateFiles(string boilerplateLocation) {

			string appFileLocationString, staticFolderLocationString, templatesFolderLocationString;
			const char* staticFolderLocation;
			const char* templatesFolderLocation;
			fstream fs;

			appFileLocationString = boilerplateLocation + "/app.py";
			staticFolderLocationString = boilerplateLocation + "/static/";
			templatesFolderLocationString = boilerplateLocation + "/templates/";

			staticFolderLocation = staticFolderLocationString.c_str();
			templatesFolderLocation = templatesFolderLocationString.c_str();

			if (_mkdir(staticFolderLocation) == -1) {
				std::cout << "There has been an issue creating the static folder." << endl;
			}
			else {
				std::cout << "-- Static folder created..." << endl;
			}
			
			if (_mkdir(templatesFolderLocation) == -1) {
				std::cout << "There has been an issue creating the templates folder." << endl;
			}
			else {
				std::cout << "-- Templates folder created..." << endl;
			}

			fs.open(appFileLocationString, std::fstream::in | std::fstream::out | std::fstream::trunc);
			fs << "\n";
			fs.close();

			std::cout << "-- App file created..." << endl;

		}

		void updateFlaskBoilerplateFiles(string boilerplateLocation) {

			string appFileLocationString, textFileLocationString, line;
			fstream textStream;
			fstream appStream;

			appFileLocationString = boilerplateLocation + "/app.py";
			textFileLocationString = "flask.txt";

			textStream.open(textFileLocationString, std::fstream::in | std::fstream::out | std::fstream::app);
			appStream.open(appFileLocationString, std::fstream::in | std::fstream::out | std::fstream::app);

			while (getline(textStream, line)) {
				appStream << line << endl;
			}

			std::cout << "-- App file updated..." << endl;

		}

};