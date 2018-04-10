#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

int main ( )
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string linea;
	std::getline(std::cin, linea);

	while (linea.size( ) != 1) {
		//std::cout << linea << std::endl;

		std::stringstream cad(linea);
		std::vector<bool> pos;
		pos.clear( );
		std::vector<int> numeros;
		std::vector<std::string> palabras;

		std::string temp;
		while (cad >> temp) {
			if (temp[0] == '-' || isdigit(temp[0])) {
				pos.push_back(true);
				int tam = temp.size( ) - 1;
				temp[tam] = '\0';
				int num = stoi(temp);
				numeros.push_back(num);
			} else {
				pos.push_back(false);
				int tam = temp.size( ) - 1;
				//temp[tam] = '\0';
				temp.resize(temp.size( ) - 1);
				palabras.push_back(temp);
			}
			//std::cout << temp;
		}

		std::sort(numeros.begin( ), numeros.end( ));
		//std::sort(palabras.begin( ), palabras.end( ));

		std::sort(palabras.begin( ), palabras.end( ), [](const std::string& s1, const std::string& s2) {
		   return lexicographical_compare(s1.begin( ), s1.end( ), s2.begin( ), s2.end( ), [](char c1, char c2) {
		      return tolower(c1) < tolower(c2);
		   });
		});

		for (auto it = pos.begin( ); it != pos.end( ); ++it) {
			if (*it) {
				std::cout << numeros.front( );
				numeros.erase(numeros.begin( ));
				if (it == pos.end( ) - 1) {
					std::cout << ".";
				} else {
					std::cout << ", ";
				}
			} else {
				std::cout << palabras.front( );
				palabras.erase(palabras.begin( ));
				if (it == pos.end( ) - 1) {
					std::cout << ".";
				} else {
					std::cout << ", ";
				}
			}
		}
		std::cout << "\n";
		std::getline(std::cin, linea);		
	}
}