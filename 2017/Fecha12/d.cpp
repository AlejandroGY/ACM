#include <iostream>
using namespace std;

unsigned long long int solve(unsigned long long int n) {
	if((n/10) == 0) {
		return n;
	}
	int suma = 0;
	while(n != 0) {
		suma += n%10;
		n /= 10;
	}
	solve(suma);
}

int main() {
	ios_base::sync_with_stdio(0);

	unsigned long long int n;
	while(cin >> n, n) {
		cout << solve(n) << "\n";
	}
}
