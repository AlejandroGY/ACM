#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while(T--) {
		int r, c;
		cin >> r >> c;

		char mat[30][30];
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				cin >> mat[i][j];
			}
		}

		int res = 0;
		bool memo[30][30] = {};
		auto busqueda = [&](int x, int y) {
			memo[x][y] = true, ++res;
			vector<pair<int, int>> v = { {x, y} };
			do {
				auto actual = v.back();
				v.pop_back();
				pair<int, int> vecinos[] = {
					{actual.first-1, actual.second},
					{actual.first+1, actual.second},
					{actual.first, actual.second-1},
					{actual.first, actual.second+1}
				};
				for(auto current : vecinos) {
					if(0 <= current.first && current.first < r && 0 <= current.second && current.second < c && mat[current.first][current.second] == '0' && !memo[current.first][current.second]) {
						memo[current.first][current.second] = true, ++res;
						v.push_back(current);
					}
				}
			}while(!v.empty());
		};
		
		for(int i = 0; i < r; ++i){
			if(mat[i][0] == '0' && !memo[i][0]) {
				busqueda(i, 0);
			}
			if(mat[i][c-1] == '0' && !memo[i][c-1]) {
				busqueda(i, c-1);
			}
		}
		for(int j = 0; j < c; ++j){
			if(mat[0][j] == '0' && !memo[0][j]) {
				busqueda(0, j);
			}
			if(mat[r-1][j] == '0' && !memo[r-1][j]) {
				busqueda(r-1, j);
			}
		}

		cout << res << "\n";
	}
}
