#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  string cad;
  getline(cin, cad);

  for(int T = 0; T < t; T++) {
    getline(cin, cad);
    stringstream ss(cad);

    int x, maximo = -(1<<30);
    vector<int> postes;
    while(ss>>x) {
      postes.push_back(x);
      maximo = max(maximo, x);
    }

    bool flag = false;
    int r = 0;
    for(int it : postes) {
      if(it == maximo) {
        flag = !flag;
        r++;
      }
      else if(flag) {
        r++;
      }
    }
    cout << r << "\n";
  }
}
