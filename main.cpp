#include <iostream>
#include <string>
#include <vector>
#include "boolean.h"

int main() {

	
	std::string input = "(A^!Z)>!(D*Z+N)";

	std::vector <std::vector<bool>> table = Boolean::truth_table(input);

	std::cout << "Truth table: " << '\n' << "A D N Z F" << '\n';

	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++)
			std::cout << table[i][j] << " ";
		std::cout << '\n';
	}
	// Return the truth table in the vector type

	std::vector <std::vector<std::string>> karnaugh_map = Boolean::karnaugh(input);
	std::cout << '\n' << "Karnaugh map: " << '\n';

	for (int i = 0; i < karnaugh_map.size(); i++) {
		for (int j = 0; j < karnaugh_map[0].size(); j++) {

			if (j != 0 && i != 0) {
				for (int k = 0; k < karnaugh_map[0][1].size() - 1; k++)
					std::cout << " ";
			}

			if (j == 1 && i != 0) {
				for (int k = 0; k < karnaugh_map[0][1].size() + 1; k++)
					std::cout << " ";
			}

			std::cout << karnaugh_map[i][j] << " ";
		}

		std::cout << '\n';
	}

	// Return the karnaugh map in the vector type

	std::cout << '\n' << "Simplify: " << Boolean::simplify(input) << '\n';
	// Return simplified DNF expression

	std::cout << '\n' << "Zhegalkin polynomial: " << Boolean::polynom(input) << '\n';
	// Return Zhegalkin polynomial

	std::cout << '\n' << "PDNF: " << Boolean::pdnf(input) << '\n';
	// Return DNF

	std::cout << '\n' << "PCNF: " << Boolean::pcnf(input) << '\n';
	// Return CNF

	Boolean::Post cl(input);
	std::cout << '\n' << "T0:" << cl.get_T0() << " T1:" << cl.get_T1() << " M:" << cl.get_M() << " L:" << cl.get_L() << " S:" << cl.get_S();
	// Return Post's Classification
}
