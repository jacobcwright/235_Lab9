#include <iostream>
#include <fstream>
#include <string>
#include "Set.h"
#include "HashMap.h"
#include "BST.cpp"

using namespace std;

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	string command, data, arg1;

	while(in >> command){
		if (command == "") continue;
		else if (command == "Set:") {
			Set<string> set;
			getline(in, data);
			stringstream ss(data);

			while (ss >> arg1) {
				set.insert(arg1);
			}
			out << command << data << endl;
			string result = set.toString();
			result.pop_back();
			out << "  [" << result << "]" << endl << endl;
		}
		else if (command == "") {

		}
		else if (command == "") {

		}
		else if (command == "") {

		}
		else if (command == "") {

		}
	}

	return 0;
}