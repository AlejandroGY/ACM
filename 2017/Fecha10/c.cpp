#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, p;
	while(cin >> n >> p) {
		int pot = (1<<n)-1;
		stringstream cad;
		int aux = pot - p;
		while(aux != 0) {
			if(aux % 2 == 0) {
				cad << 'R';
				aux /= 2;
				aux -= 1;
			}
			else {
				cad << 'L';
				aux /= 2;
			}
		}
		string s = cad.str();
		cout << "Instructions: ";
		for(int i = s.size()-1; i >= 0; i--) cout << s[i];
		cout << "\n";
	}
}