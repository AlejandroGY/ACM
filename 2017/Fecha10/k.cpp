#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool mat[10][10], usados[10];

void solve(int i) {
	if(i == n) {
		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	while(cin >> n) {
		colores = 0, colores_min = 0;
		fill(&mat[0][0], &mat[10][0], false);
		fill(usados, usados + n, false);
		for(int i = 1; i <= n; ++i) {
			int m; cin >> m;
			for(int j = 1; j <= m; ++j) {
				int k; cin >> k;
				mat[m][k] = true;
			}
		}
		solve(0);
		cout << colores_min << "\n";
	}
}
