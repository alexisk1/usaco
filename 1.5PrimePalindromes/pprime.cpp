
/*
ID: alexisk2
PROG: pprime
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
        if(a/primes[i]!=0 & a%primes[i]==0)return false;
    }

  /*  if(a>10000){

       for(int i=10000;i<a;a++){
          if(a/i!=0 & a%i==0){
              cout<<"asd:"<<a<<"/"<< i<<"= "<<a/i<< " % " <<a%i<<"\n";
              isPrime(i);
              return false;
          }
       }
    }
    if(a<=10000) primes.push_back(a);
    if(a>10000 )   */
        primes.push_back(a);


    return true;
}


int main() {

   ofs.open ("pprime.out");
   ifs.open ("pprime.in");

   ifs>>A>>B;
   primes.push_back(2);

   if(A<1000){for(int a=1;a<A;a++)isPrime(a);}
   else {
       for(int a=1;a<10000;a++)isPrime(a);
   }
 if(B>10000){
   for(int a=A;a<10000;a++){
       if(isPrime(a)) if(isPalindromic(a)) ofs<<a<<"\n";
   }
}else{
     for(int a=A;a<B;a++){
         if(isPrime(a)) if(isPalindromic(a)) ofs<<a<<"\n";
     }
 }
if(B>10000 & A<99999){
   for (int d1 = 1; d1 <= 9; d1+=2) {
       for (int d2 = 0; d2 <= 9; d2++) {
           for (int d3 = 0; d3 <= 9; d3++) {
           unsigned int palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
        //   cout<<palindrome<<isPrime(palindrome) <<"\n";
          if(palindrome>B)return 0;
         if(palindrome>=A) if( isPrime(palindrome) )ofs<<palindrome<<"\n";;

       }
       }
   }
 }
if(B>1000000){
   for (int d1 = 1; d1 <= 9; d1+=2) {
       for (int d2 = 0; d2 <= 9; d2++) {
           for (int d3 = 0; d3 <= 9; d3++) {
               for (int d4 = 0; d4 <= 9; d4++) {

                    unsigned int palindrome = 1000000*d1 + 100000*d2+10000*d3+1000*d4+100*d3 + 10*d2 + d1;
                     if(palindrome>B)return 0;
                    if(palindrome>=A)  if( isPrime(palindrome) )ofs<<palindrome<<"\n";

                }
       }
       }
   }

}

   return 0;
}


