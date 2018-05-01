#include <bits/stdc++.h>

struct tile {
	int a, b, c, d, p;
	
	tile( ) {
	}
	
	tile(int a1, int b1, int c1, int d1, int p1)
	: a(a1), b(b1), c(c1), d(d1), p(p1) {
	}
	
	bool operator<(tile t) const {
		if (a != t.a) return a < t.a;
		else if (b != t.b) return b < t.b;
		else if (c != t.c) return c < t.c;
		else if (d != t.d) return d < t.d;
		return p > t.p;
	}
};

tile rotar(tile t) {
	return tile(t.b, t.c, t.d, t.a, t.p);
}

tile menor(tile t) {
	tile temp = t;
	for (int i = 0; i < 3; ++i) {
		temp = rotar(temp);
		t = std::min(t, temp);
	}
	return t;
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, k;
	while (std::cin >> n >> k, n && k) {
		tile act;
		std::multiset<tile> ms;
		
		for (int i = 0; i < k; ++i) {
			std::cin >> act.a >> act.b >> act.d >> act.c >> act.p;
			act = menor(act);
			ms.insert(act);
		}
		
		int mat[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cin >> mat[i][j];
			}
		}
		
		int res = 0;
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				act = tile(mat[i][j], mat[i][ j + 1], mat[i + 1][j + 1], mat[i + 1][j], INT_MAX);
				act = menor(act);
				
				auto it = ms.lower_bound(act);
				if (it == ms.end( ) || it->a != act.a || it->b != act.b || it->c != act.c || it->d != act.d) {
					res = -1;
					i = n;
					break;
				}
				res += it->p;
				ms.erase(it);
			}
		}
		std::cout << res << "\n";
	}
}
