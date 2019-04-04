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
	string command, data, arg1, arg2;
	HashMap <string, string> Pokemon;
	HashMap <string, string> Moves;
	HashMap<string, Set<string>> effectiveTypes;
	HashMap<string, Set<string>> ineffectiveTypes;


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
			out << "  [" << result << "]" << endl << endl;
		}
		else if (command == "Pokemon:") {
			getline(in, data);
			stringstream ss(data);
			ss >> arg1; //arg1 = Pokemon Name
			ss >> arg2; //arg2 = Pokemon Type
			//create new pokemon input
			Pokemon[arg1] = arg2;
			out << command << data << endl;
		}
		else if (command == "Move:") {
			getline(in, data);
			stringstream ss(data);
			ss >> arg1; //arg1 = Move Name
			ss >> arg2; //arg2 = Move Type
			//create new move input
			Moves[arg1] = arg2;
			out << command << data << endl;
		}
		else if (command == "Pokemon") {
			out << endl << "Pokemon:" << Pokemon.size() << "/" << Pokemon.max_size() << endl;
			out	<< Pokemon.toString() << endl;
		}
		else if (command == "Moves") {
			out << "Moves:" << Moves.size() << "/" << Moves.max_size() << endl;
			out << Moves.toString() << endl;
		}
		else if (command == "Effective:") {
			getline(in, data);
			stringstream ss(data);
			ss >> arg1; //baseType
			out << command << data << endl;
			while (ss >> arg2) { //arg2 = effectiveTypes
				effectiveTypes[arg1].insert(arg2);
			}
			
		}
		else if (command == "Ineffective:") {
			getline(in, data);
			stringstream ss(data);
			ss >> arg1; //baseType
			out << command << data << endl;
			while (ss >> arg2) { //arg2 = ineffectiveTypes
				ineffectiveTypes[arg1].insert(arg2);
			}
		}
		else if (command == "Effectivities") {
			out << endl << "Effectivities:" << effectiveTypes.size() << "/" << effectiveTypes.max_size() << endl;
			string result = effectiveTypes.toString();
			out << result << endl;
		}
		else if (command == "Ineffectivities") {
			out << endl << "Ineffectivities:" << ineffectiveTypes.size() << "/" << ineffectiveTypes.max_size() << endl;
			string result = ineffectiveTypes.toString();
			out << result << endl;
		}
		else if (command == "") {

		}
		else if (command == "") {

		}

	}

	return 0;
}