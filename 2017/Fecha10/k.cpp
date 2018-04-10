#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, colores, colores_min;
int tabla[10];
bool usados[10], mat[10][10];

void solve(int i) {
	if(i == n) {
		colores_min = colores;
		return;
	}

	bool usados_local[10] = { };
	for(int j = 0; j < i; j++) {
		if(mat[i][j]) {
			usados_local[tabla[j]] = true;
		}
	}

	for(int j = 0; j < colores; j++) {
		if(!usados_local[j]) {
			tabla[i] = j;
			solve(i+1);
		}
	}

	if(colores + 1 < colores_min) {
		tabla[i] = colores;
		usados[colores] = true;
		colores += 1;
		solve(i+1);
		colores -= 1;
		usados[colores] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n) {
		fill(&mat[0][0], &mat[10][0], false);
		fill(usados, usados + n, false);
		colores = 0, colores_min = n;
		for(int i = 0; i < n; ++i) {
			int m; cin >> m;
			for(int j = 0; j < m; ++j) {
				int act; cin >> act;
				mat[i][act-1] = true;
				//mat[act-1][i] = true;
			}
		}
		solve(0);
		cout << colores_min << "\n";
	}
}