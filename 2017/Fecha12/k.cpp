#include <iostream>
#include <string>
#include <vector>

void genera(std::vector<char> matriz[15 + 1][15 + 1], int i, int j, std::string& s) {
   auto& eventos = matriz[i][j];
   if (eventos.front( ) == 'b') {
      for (int xi = i; xi < s.size( ); ++xi) {
         s[xi] = 'f';
      }
      std::cout << s << "\n";
   } else {
      for (auto e : eventos) {
         s[i] = e;
         genera(matriz, i + 1, j + (e != 'f') * (1 + (e == 'l' || e == 'r')), s);
      }
   }
}

int main( ) {
   std::string lineas[] = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
   std::pair<int, int> tabla[128];
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < lineas[i].size( ); ++j) {
         tabla[lineas[i][j]] = { i, j };
      }
   }

   auto adyacente = [&](char c1, char c2) {
      auto dx = std::abs(tabla[c1].first - tabla[c2].first);
      auto dy = std::abs(tabla[c1].second - tabla[c2].second);
      return dx <= 1 && dy <= 1 && dx + dy != 0;
   };

   int t;
   std::cin >> t;
   std::cin.ignore( );

   for (int ti = 0; ti < t; ++ti) {
      std::string e, w;
      std::getline(std::cin, e);
      std::getline(std::cin, w);

      std::vector<char> matriz[15 + 1][15 + 1];
      for (int i = e.size( ); i >= 0; --i) {
         for (int j = w.size( ); j >= 0; --j) {
            if (i == e.size( ) || j == w.size( )) {
               if (j == w.size( )) {
                  matriz[i][j].push_back('b');
               }
            } else {
               if (!matriz[i + 1][j].empty( )) {
                  matriz[i][j].push_back('f');
               }
               if (e[i] == w[j]) {
                  if (!matriz[i + 1][j + 1].empty( )) {
                     matriz[i][j].push_back('o');
                  }
                  if (!matriz[i + 1][j + 2].empty( ) && adyacente(w[j], w[j + 1])) {
                     matriz[i][j].push_back('r');
                  }
               } else {
                  if (!matriz[i + 1][j + 2].empty( ) && adyacente(w[j], w[j + 1]) && e[i] == w[j + 1]) {
                     matriz[i][j].push_back('l');
                  }
                  if (!matriz[i + 1][j + 1].empty( ) && adyacente(w[j], e[i])) {
                     matriz[i][j].push_back('w');
                  }
               }
            }
         }
      }

      std::cout << e << " " << w << ":\n";
      genera(matriz, 0, 0, e);
      std::cout << "\n";
   }
}
