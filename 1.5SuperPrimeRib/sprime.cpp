
/*
ID: alexisk2
PROG: sprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>
std::ifstream ifs;
std::ofstream ofs;
int A,B,C;
using namespace std;
vector <int> sol;
vector<int> primes;
vector<int> primeTree[9];


bool isPalindromic(int a){
    string num=to_string(a);
    int len=num.length();
    if(len%2!=0) len=len-1;
    len=len>>1;

    for(int i=0;i<=len;i++){
        if(num[i]!=num[num.length()-1-i]) return false;
    }

    return true;
}



bool isPrime(int a){
    if(a==1) return true;

    bool f=true;
    for(int i=0;i<primes.size();i++){
        if(a/primes[i]!=0 & a%primes[i]==0 & a!=primes[i])return false;
    }

    primes.push_back(a);


    return true;
}

bool OK(int n,int lvl){
    for(int i=0;i<primeTree[lvl-1].size();i++){
        if(int(n/10)==primeTree[lvl-1][i])return true;
    }
    return false;
}

int main() {

   ofs.open ("sprime.out");
   ifs.open ("sprime.in");

   ifs>>A;

if(A>=1){
    for(int a=2;a<=9;a++){
     if(isPrime(a))primeTree[0].push_back(a);
    }
}
if(A>=2){
    for(int a=11;a<=99;a=a+2)if(isPrime(a) & OK(a,1)) primeTree[1].push_back(a);

}
if(A>=3){
    for(int a=101;a<=999;a=a+2)if(isPrime(a) & OK(a,2)) primeTree[2].push_back(a);

}

if(A>=4){
    for(int a=1001;a<=9999;a=a+2)if(isPrime(a) & OK(a,3)) primeTree[3].push_back(a);

}

if(A>=5){
 for(int lvl=3;lvl<A-1;lvl++)
   for(int x=0;x<primeTree[lvl].size();x++)
        for(int a=1;a<=9;a=a+2){
       //   cout<<primeTree[lvl][x]*10+a<<"  "<<lvl<<"\n ";
           if(isPrime(primeTree[lvl][x]*10+a)) primeTree[lvl+1].push_back(primeTree[lvl][x]*10+a);
        }
}
cout<<"hh \n";

for(int i=0;i<primeTree[A-1].size();i++){
    ofs<<primeTree[A-1][i]<<"\n";
   // cout<<primeTree[A-1][i]<<" ";

}
cout<<" \n";

   return 0;
}



