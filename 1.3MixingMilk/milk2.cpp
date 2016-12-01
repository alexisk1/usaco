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
vector <int> sums;
bool f=false;

int best=(1<<30);
int milk,farmers;

std::ifstream ifs;
std::ofstream ofs;

void search(int qty,int pos,int sum){

    if(sum>best) return;

    if(qty==milk){
        if(sum<best ){ best=sum;}
    }else{
        if(pos==(units.size()))return;
        int qty_n=qty+units[pos];
        if (qty_n<=milk  )search(qty_n,pos+1,sum+units[pos]*prices[pos]);
        if (qty_n>milk ){
           if(qty<milk){
              int c=milk-qty;
              qty_n=c+qty;
              search(qty_n,pos+1,sum+c*prices[pos]);
           }
        }
    }
}
int min_p=(1<<30);
void fillUp(){
     int sum=0;
     while(!ifs.eof()){
            int a,b;
            ifs>>a>>b;
            if(!ifs.eof()){
               int i=0;
               bool found=false;
               while(i<prices.size() & found==false){
                   if(a<prices[i]){
                       f=true;
                       prices.insert(prices.begin()+i,a);
                       units.insert(units.begin()+i,b);
                       break;
                   }
                   if(a>=prices[i]) i++;

               }
               if(i==prices.size()){
               prices.push_back(a);
               units.push_back(b);
               }
               sum+=b;

                if( (b<=milk) & (min_p>a)){
                    min_p=a;
                    f=true;
                }else{
                    if(!(min_p==a)) f=false;
                }
                qty.push_back(0);
           }
     }

      sums.push_back(sum);
     for(int i=1;i<units.size();i++){
         sum-=units[i-1];
         sums.push_back(sum);
     }
}

int main() {
    ofs.open ("milk.out");
    ifs.open ("milk.in");


    ifs>>milk>>farmers;

    fillUp();
if(!f){

     search(0,0,0);
}else{best=min_p*milk; }
    ofs<<best<<"\n";

    return 0;
}
