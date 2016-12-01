/*
ID: alexisk2
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

#include <string>

using namespace std;

vector <int> prices;
vector <int> units;
vector <int> qty;

int best=0;
int milk,farmers;

std::ifstream ifs;
std::ofstream ofs;


void search(vector <int> qty,int pos,int sum_b){

     if(sum_b>milk)return;

        if  (sum_b==milk){
           int sum=0;
           for (int i=0;i<pos;i++) sum+=qty[i]*prices[i];
           if(best==0 & sum!=0){ best=sum;}
           if(sum<best & sum!=0 ) best=sum;

     }else{
             if(pos==(units.size()-1))return;
         for (int i=0;i<=units[pos];i++){
             qty[pos]=i;
             int c=sum_b+i;
             if ( (c)<=milk) {
                search(qty,pos+1,c);
             }
         }
     }
}

void fillUp(){
     while(!ifs.eof()){
            int a,b;
            ifs>>a>>b;
            prices.push_back(a);
            units.push_back(b);
            qty.push_back(0);
     }
}

int main() {
    ofs.open ("milk.out");
    ifs.open ("milk.in");


    ifs>>milk>>farmers;


    fillUp();
/*
    for(int i=0;i<units.size();i++){
       for(int j=0;j<units.size();j++){

           if (prices[i]>prices[j] ){
              int k=prices[j];
              int l=units[j];
              units[j]=units[i];
              prices[j]=prices[i];
              units[i]=l;
              prices[i]=k;
           }
       }
    }
       for(int i=0;i<units.size();i++){
          for(int j=0;j<units.size();j++){

              if (prices[i]>prices[j] ){
                 int k=prices[j];
                 int l=units[j];
                 units[j]=units[i];
                 prices[j]=prices[i];
                 units[i]=l;
                 prices[i]=k;
              }
          }
       }*/
    search(qty,0,0);
    ofs<<best<<"\n";

    return 0;
}
