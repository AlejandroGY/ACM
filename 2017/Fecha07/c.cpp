#include <bits/stdc++.h>
using namespace std;

pair<int, char> arr[] = {
	{0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'},
	{5, 'F'}, {6, 'G'}, {7, 'H'}, {8, 'I'}, {9, 'J'}, 
	{10,'K'}, {11,'L'}, {12,'M'}, {13,'N'}, {14,'O'},
	{15,'P'}, {16,'Q'}, {17,'R'}, {18,'S'}, {19,'T'},
	{20,'U'}, {21,'V'}, {22,'W'}, {23,'X'}, {24,'Y'}, 
	{25, 'Z'}
};

int main() {
	int idx = 0;
	string cad, llave;
	cin >> cad >> llave;
	
	for(int i = 0; i < cad.size(); ++i) {
		int m = int(cad[i]) - int(llave[i]);
		m += (m < 0 ? 26 : 0);
		char c = arr[m].second;
		llave += c;
		cout << c;
	}
	cout << "\n";
}
