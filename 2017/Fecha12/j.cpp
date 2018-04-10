#include <iostream>
#include <vector>
#include <queue>

bool bfs (int i, std::vector<int> adyacencia[], std::vector<bool>& visitados, int n)
{
	bool flag = false;
	std::queue<int> cola;
	cola.push(i);

	do {
		int actual = cola.front( );
		cola.pop( );
		if (visitados[actual]) {
			continue;
		}

		flag = true;
		visitados[actual] = true;
		for (int vecino : adyacencia[actual]) {
			cola.push(vecino);
		}
	} while (!cola.empty( ));

	return flag;
}

int main ( )
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string op;
	while (std::cin >> op) {
		int n = op[0] - 'A' + 1;
		//std::cout << n << "\n";
		std::vector<int> adyacencia[n + 1];
		std::vector<bool> visitados(n + 1, false);

		std::string componentes;
		std::getline(std::cin, componentes);
		std::getline(std::cin, componentes);
		while (componentes.size( ) != 0) {
			int x = componentes[0] - 'A' + 1;
			int y = componentes[1] - 'A' + 1;
			adyacencia[x].push_back(y);
			adyacencia[y].push_back(x);
			std::getline(std::cin, componentes);
		}

		int res = 0;
		for (int i = 1; i <= n; ++i) {
			/**/
			if (bfs(i, adyacencia, visitados, n)) {
				++res;
			}
			/**/
		}
		std::cout << res << "\n";
	}
}