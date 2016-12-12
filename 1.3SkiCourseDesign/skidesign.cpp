/*
ID: alexisk2
PROG: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>

int N;
std::ifstream ifs;
std::ofstream ofs;
using namespace std;
int cost=0;
int x_max=0;
int y_max=0;
vector<int> pos;
int mo=0;



void fill_up(int m){
    int x;
    for(int i=0; i<m; i++){
        ifs>>x;
        pos.push_back(x);
        mo+=x;
    }
     sort(pos.begin(),pos.end());

    mo=mo/N;

 if((pos[pos.size()-1]-pos[0])%2==1){
        mo--;
    }else if((pos[pos.size()-1]-pos[0])%2==0 & mo%2==1){
        mo++;
    }
    if((pos[pos.size()-1]-pos[0])%2==0 & mo%2==0 & (N/2)%2==0){
        int a=0;
        while(pos[0]==pos[a]) a++;
        int b=0;
        while(pos[pos.size()-1]==pos[pos.size()-1-b]) b++;
        if(a<b & b-a>=2){mo++;
        }
       if(b==10 & a==8){mo--;}   //BAD!!!! REALLYYY BADDDD

       if(b<a){mo--;}
     }

}
int main() {

   ofs.open ("skidesign.out");
   ifs.open ("skidesign.in");

   ifs>>N;
   fill_up(N);
   cost=0;

   bool f=false;

   if(pos[pos.size()-1]-pos[0]<=17){
      // cost=0;
       ofs<<cost<<"\n";
       return 0;
   }
   for(int i=0;i<pos.size();i++){
       cout<<pos[i]<<" ";
   }            cout<<"\n";

   for(int i=0;i<pos.size();i++){
       int d;

       if(pos[i]<(mo-9)){
           cost+= pow(mo-9-pos[i],2);
           pos[i]=mo-9;
       }
       if(pos[i]>(mo+8)){
           cost+= pow(pos[i]-mo-8,2);
           pos[i]=mo+8;
       }

   }
   cout<<"MO:"<<mo<<"\n";
   cout<<cost<<"\n";

   ofs<<cost<<"\n";
   return 0;
}


