#include <bits/stdc++.h>

template<typename FI>
std::size_t lis_size(FI ini, FI fin) {
	std::vector<typename std::iterator_traits<FI>::value_type> valores;
	for (auto i = ini; i != fin; ++i) {
		auto cambiar = std::upper_bound(valores.begin( ), valores.end( ), *i);
		if (cambiar == valores.end( )) {
			valores.push_back(*i);
		} else {
			*cambiar = *i;
		}
	}
	return valores.size( );
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;
	std::cin >> t;
	
	while (t--) {
		int n;
		std::cin >> n;
		
		int arr[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
		}
		
		int a[n], b[n];
		std::fill(a, a + n, 1);
		std::fill(b, b + n, 1);
		for (int i = 0; i < n; ++i) {
			a[i] = std::max(a[i], int(lis_size(arr, arr + i)));
		}
		
		std::reverse(arr, arr + n);
		for (int i = 0; i < n; ++i) {
			b[n - i - 1] = std::max(b[n - i - 1], int(lis_size(arr, arr + i)));
		}
		
		int res = 0;
		for (int i = 0; i < n; ++i) {
			res = std::max(res, a[i] + b[i]);
		}
		std::cout << res << "\n";
	}
}
