#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n, n){
    int aux = 0;
        for(long long k = 1; k <= n; k++){
            for(long long i = 1; i <= k; i++) {
                for(long long j = 1; j <= i; j++){
                    if(((i*i) + (j*j)) == k*k) aux++;

                }
            }
        }
        cout << aux <<"\n";
	}
}
