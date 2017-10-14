#include <iostream>
#include <climits>
using namespace std;

template<typename A>
bool factible(A* ai, A* af, int k, int c) {
	int* p = ai;
	while(p != af && k != 0) {
		int suma = 0;
		while(p != af && suma + *p <= c) {
			suma += *p++;
		}
		--k;
	}
	return p == af;
}

template<typename A>
int busqueda(int ti, int tf, int k, A* ai, A* af) {
	if(ti == tf) {
		return INT_MAX;
	}

	int mitad = ti + (tf - ti) / 2;
	if(factible(ai, af, k, mitad)) {
		return min(mitad, busqueda(ti, mitad, k, ai, af));
	}
	else {
		return busqueda(mitad + 1, tf, k, ai, af);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	while(cin >> n >> k) {
		int arboles[n];
		for(int i = 0; i < n; ++i) {
			cin >> arboles[i];
		}

		int res = busqueda(1, 1000000002, k, arboles, arboles + n);
		cout << res << "\n";
	}
}
