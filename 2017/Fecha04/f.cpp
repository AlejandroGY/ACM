#include <bits/stdc++.h>

int f, n;
std::string cad;
int v[1002];
std::map<std::pair<int, int>, int> memo;

int solve(int i, int p) {
	if (i == n) {
		return 0;
	}

	if (memo[{ i, p }]) {
		return memo[{ i, p }];
	}

	int res = solve(i + 1, p);
	if (v[i] >= p) {
		res = std::max(res, solve(i + 1, (v[i] + f) % 26) + 1);
	}
	return memo[{ i, p }] = res;
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		memo.clear( );
		std::cin >> cad >> f;

		n = cad.size( );
		for (int i = 0; i < n; ++i) {
			v[i] = cad[i] - 'a';
		}
		std::cout << solve(0, 0) << "\n";
	}
}
