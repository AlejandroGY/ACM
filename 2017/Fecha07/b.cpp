#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   queue<string> espera;
   queue<pair<string, string>> mejores;

   int n; cin >> n;
   
   string blanco[2];
   string negro[2];
   
   for(int i = 0; i < n; i++) {
      string s; cin >> s;
      if(i == 0) {
         blanco[0] = s; //Off_B
      }
      else if(i == 1) {
         negro[0] = s; //Off_N
      }
      else if(i == 2) {
         blanco[1] = s; //Def_B
      }
      else if(i == 3) {
         negro[1] = s; //Def_N
      }
      else {
         espera.push(s);
      }
   }

   pair<string, string> act_blanco = make_pair(blanco[0], blanco[1]), act_negro = make_pair(negro[0], negro[1]);
   string puntos; cin >> puntos;
   int mejor = 0, mejor_act = 0;
   int cont_blanco = 0, cont_negro = 0;

   for(int i = 0; i < puntos.size(); i++) {
   	//cout << act_blanco.first << " " << act_blanco.second << " vs " << act_negro.first << " " << act_negro.second << "\n";
      if(puntos[i] == 'W') {
         swap(blanco[0], blanco[1]);
         
         string temp = negro[1];
         espera.push(temp);
         negro[1] = negro[0];
         temp = espera.front();
         negro[0] = temp;
         espera.pop();
         
         act_negro = (make_pair(negro[1], negro[0]));
         cont_blanco++;
         cont_negro = 0;
         
         if(cont_blanco == mejor) {
            mejores.push(act_blanco);
         }
         if(cont_blanco > mejor){
            mejor = cont_blanco;
            while(!mejores.empty()) mejores.pop();
            mejores.push(act_blanco);
         }
      }
      else {
         swap(negro[0], negro[1]);
         
         string temp = blanco[1];
         espera.push(temp);
         blanco[1] = blanco[0];
         temp = espera.front();
         blanco[0] = temp;
         espera.pop();
         
         act_blanco = (make_pair(blanco[1], blanco[0]));
         cont_negro++;
         cont_blanco = 0;
         
         if(cont_negro == mejor) {
            mejores.push(act_negro);
         }
         if(cont_negro > mejor){
            mejor = cont_negro;
            while(!mejores.empty()) mejores.pop();
            mejores.push(act_negro);
         }
      }
   }

   while(!mejores.empty()) {
      cout << mejores.front().first << " " << mejores.front().second << "\n";
      mejores.pop();
   }
}
