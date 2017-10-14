#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int T, n = 8;
int a[8];
string s1, s2;
stringstream cad1;

void print() {
	for(int i = 0; i < 8; i++) {
		cout << (a[i] == 1 ? "i" : "o");
		if(i < 7) cout << " ";
	}
	cout << "\n";
}

bool solve() {
	char pila[8];
	int id = 0, idx = 0;
	stringstream cad2;
	cad1.clear();
	for(int i = 0; i < 8; i++) {
		if(a[i] == 1) {
			pila[id] = s1[idx++];
			id++;
		}
		else {
			if(id == 0) {
				return false;
			}
			cad2 << pila[id-1];
			id--;
		}
	}
	string aux = cad2.str();
	return (aux == s2);
}

void genera(int i, int u) {
	if(i == n) {
		if(solve()) {
			print();
		}
		return;
	}
	if(n-i-1 >= u) {
		a[i] = 1;
		genera(i+1, u);
	}
	if(u > 0) {
		a[i] = 0;
		genera(i+1, u-1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for(int k = 0; k < T; k++) {
		cin >> s1 >> s2;
		cout << "Output for " << s1 << " " << s2 << "\n[\n";
		genera(0, 4);
		cout << "]\n";
	}
}