#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> p;

int find(int a) {
	return (p[a] == a ? a : p[a] = find(p[a]));
}

void Union(int a, int b) {
	p[find(a)] = find(b);
}

bool sameSet(int a, int b) {
	return (find(a) == find(b));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for(int i = 1; i <= T; ++i) {
		int n, m; cin >> n >> m;
		p.resize(n);
		for(int j = 0; j < n; j++) p[j] = j;
		vector<pair<int, pair<int, int>>> aristas;
		for(int j = 0; j < m; j++) {
			int u, v, c;
			cin >> u >> v >> c;
			aristas.push_back(make_pair(c, make_pair(u, v)));
		}
		int res = 0;
		sort(aristas.begin(), aristas.end(), greater<pair<int,pair<int,int>>>());//[](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {return a.first > b.first;});
		for(auto actual : aristas) {
			if(!sameSet(actual.second.first, actual.second.second)) {
				Union(actual.second.first, actual.second.second);
				res = actual.first;
			}
		}
		cout << "Case #" << i << ": " << res << "\n";
	}
}