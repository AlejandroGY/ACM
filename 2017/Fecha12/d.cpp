#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
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
	//cin >> num;
	//int n = stoi(num);
	while(cin >> n, n) {
		//cout << num[1] -'0';
		cout << solve(n) << "\n";
	}
/*
cout << num.size();
	
	while(num != "0") {
		while(num.size() > 1) {
			string res = "";
			for(int i = 0; i < num.size(); i++) {
				res += num[i]-'0';
				cout << res << '\n';
			}
			num;
			num = res;
			cout << num << " : num\n";
		}
		cout << num << "\n";
		cin >> num;
	}
*/
}
