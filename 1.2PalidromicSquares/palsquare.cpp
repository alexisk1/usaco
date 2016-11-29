/*
ID: alexisk2
PROG: palsquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
std::ifstream ifs;
std::ofstream ofs;

bool isPalindromic(string num){
    int len=num.length();
    if(len%2!=0) len=len-1;
    len=len>>1;

    for(int i=0;i<=len;i++){
        if(num[i]!=num[num.length()-1-i]) return false;
    }
    return true;
}

string remainder(int n ,int base){
      char c=n%base+48;
      if(n<10) return string(1,c);
      n=n%base;
      //65<-10
      c=n+55;
      return string(1,c);
}

string base(int n,int base){
       string num="";

       while(n>0){
           num=remainder(n%base,base)+num;
           n=n/base;
       }
       return num;
}

int main() {
    ofs.open ("palsquare.out");
    ifs.open ("palsquare.in");

    string b;
    ifs>>b;
    int bs=stoi(b);
    for(int x=1;x<301;x++){
        b=base(x*x,bs);
        if(isPalindromic(b) ) ofs<<base(x,bs)<<" "<<b<<"\n";
    }


    return 0;
}
