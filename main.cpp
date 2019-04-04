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
	string command, data, arg1, arg2, arg3, arg4;
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
			//effectiveTypes[arg1] = Set<string>();
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
		else if (command == "Battle:") {
			getline(in, data);
			stringstream ss(data);
			ss >> arg1; //arg1 = Pokemon 1
			ss >> arg2; //arg2 = Move 1
			ss >> arg3; //arg3 = Pokemon 2
			ss >> arg4; //arg4 = Move 2

			/* Output Battle*/
			out << command << data << endl;
			out << "  " << arg1 << " (" << arg2 << ") vs " << arg3 << " (" << arg4 << ")" << endl;
			out << "  " << arg1 << " is a " << Pokemon[arg1] << " type Pokemon." << endl;
			out << "  " << arg3 << " is a " << Pokemon[arg3] << " type Pokemon." << endl;
			out << "  " << arg2 << " is a " << Moves[arg2] << " type move." << endl;
			out << "  " << arg4 << " is a " << Moves[arg4] << " type move." << endl;
			out << "  " << arg2 << " is super effective against [" << effectiveTypes[Moves[arg2]] << "] type Pokemon." << endl;
			out << "  " << arg2 << " is  ineffective against [" << ineffectiveTypes[Moves[arg2]] << "] type Pokemon." << endl;

			/* Output Move 1 effectivity against pokemon 2*/
			int move1 = 1; //move1 = effectiveness of move 1 (2 = super, 1 = effective, 0 = ineffective)
			/* If Pokemon 2 type is in set of Move 1 effectivities, move1++*/
			if (effectiveTypes[Moves[arg2]].count(Pokemon[arg3])) move1++; 
			else if (ineffectiveTypes[Moves[arg2]].count(Pokemon[arg3])) move1--;

			if (move1 == 2) {
				// *Pokemon1* *move* is super effective against *Pokemon2*
				out << "  " << arg1 << "'s " << arg2 << " is super effective against " << arg3 << endl;
			}
			else if (move1 == 0) {
				out << "  " << arg1 << "'s " << arg2 << " is ineffective against " << arg3 << endl;
			}
			else {
				out << "  " << arg1 << "'s " << arg2 << " is effective against " << arg3 << endl;
			}

			out << "  " << arg4 << " is super effective against [" << effectiveTypes[Moves[arg4]] << "] type Pokemon." << endl;
			out << "  " << arg4 << " is  ineffective against [" << ineffectiveTypes[Moves[arg4]] << "] type Pokemon." << endl;

			/* Output Move 2 effectivity against pokemon 1*/

			int move2 = 1; //move2 = effectiveness of move 2 (2 = super, 1 = effective, 0 = ineffective)
			if (effectiveTypes[Moves[arg4]].count(Pokemon[arg1])) move2++;
			else if (ineffectiveTypes[Moves[arg4]].count(Pokemon[arg1])) move2--;

			if (move2 == 2) {
				// *Pokemon1* *move* is super effective against *Pokemon2*
				out << "  " << arg3 << "'s " << arg4 << " is super effective against " << arg1 << endl;
			}
			else if (move2 == 0) {
				out << "  " << arg3 << "'s " << arg4 << " is ineffective against " << arg1 << endl;
			}
			else {
				out << "  " << arg3 << "'s " << arg4 << " is effective against " << arg1 << endl;
			}

			/* Output winner */
			if (move1 > move2) {
				out << "  In the battle between " << arg1 << " and " << arg3 << ", " << arg1 << " wins!" << endl << endl;
			}
			else if (move1 < move2) {
				out << "  In the battle between " << arg1 << " and " << arg3 << ", " << arg3 << " wins!" << endl << endl;
			}
			else if (move1 == move2) {
				out << "  The battle between " << arg1 << " and " << arg3 << " is a tie." << endl << endl;
			}
		}
		else continue;

	}

	return 0;
}