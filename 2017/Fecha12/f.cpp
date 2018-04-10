#include <algorithm>
#include <climits>
#include <iostream>
#include <functional>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <utility>
#include <tuple>
#include <vector>

int main( )
{
   int c;
   std::cin >> c;

   for (int ci = 1; ci <= c; ++ci) {
      int v, t;
      std::cin >> v >> t;
      std::cin.ignore(INT_MAX, '\n');
      std::vector<std::pair<int, int>> adyacencia[v];

      for (int i = 0; i < v; ++i) {
         std::string linea;
         std::getline(std::cin, linea);
         std::istringstream iss(linea);
         int planeta1, planeta2, costo;

         iss >> planeta1;
         while (iss >> planeta2 >> costo) {
            adyacencia[planeta1].emplace_back(costo, planeta2);
         }
      }

      if (t != 0) {
         std::string linea;
         std::getline(std::cin, linea);
         std::istringstream iss(linea);
         int planeta1, planeta2;
         while (iss >> planeta1 >> planeta2) {
            adyacencia[planeta1].emplace_back(0, planeta2);
            adyacencia[planeta2].emplace_back(0, planeta1);
         }
      }

      int origen, destino;
      std::cin >> origen >> destino;

      // metodo
      int dummy = 0;

      std::vector<std::pair<int, int>> datos(v, { INT_MAX, -1 });
      std::priority_queue<std::tuple<int, int, int, int>, std::vector<std::tuple<int, int, int, int>>, std::greater<std::tuple<int, int, int, int>>> cola;
      cola.emplace(0, origen, dummy++, -1);

      do {
         auto actual = cola.top( );
         cola.pop( );
         if (datos[std::get<1>(actual)].first == INT_MAX) {
            datos[std::get<1>(actual)] = { std::get<0>(actual), std::get<3>(actual) };
            for (const auto& e : adyacencia[std::get<1>(actual)]) {
               cola.emplace(std::get<0>(actual) + e.first, e.second, dummy++, std::get<1>(actual));
            }
         }
      } while (!cola.empty( ));

      std::vector<int> saltos;
      for (int actual = destino; actual != -1; actual = datos[actual].second) {
         saltos.push_back(actual);
      }
      std::reverse(saltos.begin( ), saltos.end( ));

      // resultado
      auto res = std::make_pair(datos[destino].first, std::move(saltos));

      std::cout << "Case #" << ci << ": ";
      if (res.first == INT_MAX) {
         std::cout << "Path does not exist\n";
      } else {
         std::cout << res.first << "\n";
         for (int i = 0; i < res.second.size( ); ++i) {
            std::cout << res.second[i] << (i + 1 < res.second.size( ) ? " " : "\n");
         }
      }
   }
}
