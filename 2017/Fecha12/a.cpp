#include <iostream>
using namespace std;

int max_com(int u, int v){
	int t;
	while(u>0){
		if(u<v){t=u; u=v; v=t;}
		u=u-v;
	}
	return v;
}

int main(){
	int n;
	while(cin >> n){
		int n1, n2;
		n1=3*n;
		n2=2*n+1;
		if(n1%n2==0){
            cout << n1/n2;
		}else{
            int r=max_com(n1,n2);
            if(r==1){
                cout << n1 << '/' << n2;
            }else{
                cout << n1/r << '/' << n2/r;
            }
		}
		cout << '\n';
    }
}
