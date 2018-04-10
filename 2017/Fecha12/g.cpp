#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1300010;
int criba[N];
std::vector<long long> primos;

int main ( )
{

	for (int i = 2; i < N; ++i) {
		if (criba[i] == 0) {
			primos.push_back(i);
			for (int j = 2 * i; j < N; j += i) {
				criba[j] = 1;
			}
		}
	}

	int a, b;
	while (std::cin >> a >> b) {
		if (a == 0 && b == 0) {
			return 0;
		}
		if (b < a) {
			std::swap(a, b);
		}

		auto ini = std::lower_bound(primos.begin( ), primos.end( ), a);
		auto fin = std::upper_bound(primos.begin( ), primos.end( ), b);
		long long res = INT_MIN;

		for (auto it = ini; it < fin - 1; ++it) {
			long long x = *(it + 1);
			long long y = (*it);
			res = std::max(res, x - y);
		}

		if (res == INT_MIN)
			std::cout << "NULL\n";
		else
			std::cout << res << "\n";
	}
}