#include <iostream>
#include <array>
#include <string>
#include <algorithm>

int indice(char c) {
	return (c == 'A' ? 0 : (c == 'C' ? 1 : (c == 'G' ? 2 : 3)));
}

std::array<int, 4> calcula(std::string temp, int ini, int fin) {
	std::array<int, 4> res = { };
	for (int i = ini; i < fin; ++i) {
		res[indice(temp[i])] += 1;
	}
	return res;
}

int main( ) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		std::cin >> n >> k;
		n += 1;

		std::string temp;
		std::array<int, 4> prefijo[n], sufijo[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> temp;
			prefijo[i] = calcula(temp, 0, k);
			sufijo[i] = calcula(temp, temp.size( ) - k, temp.size( ));
		}

		int memo[2][n];
		auto act = memo[0], ant = memo[1];
		for (int i = n; i >= 1; --i, std::swap(act, ant)) {
			for (int p = 0; p < i; ++p) {
				if (i == n) {
					act[p] = 0;
				} else {
					int res = ant[p];
					if (sufijo[p] == prefijo[i]) {
						res = std::max(res, 1 + ant[i]);
					}
					act[p] = res;
				}
			}
		}

		std::cout << ant[0] << std::endl;
	}
}