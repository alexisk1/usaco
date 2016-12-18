/*
ID: alexisk2
PROG: milk3
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
vector <int> solutions;

struct mypair{
    int a,b,c;
    mypair(int a,int b, int c):a(a),b(b),c(c){}
};
vector <mypair*> solu;

bool find_a(int a, int b,int c){
    bool f=false;
    for(int i=0; i<solu.size();i++){
        if(solu[i]->a==a & solu[i]->b==b & solu[i]->c==c  ){
            return true;
        }
    }
    return false;
}

void perm(int a, int b,int c){
    solu.push_back(new mypair(a,b,c));
     if(a==0 ){
          solutions.push_back(c);
     }

     if(a<=A){
         if(b>=(A-a)){
             int ba=b-A+a;
             if(!find_a(A,ba,c)) perm (A,ba,c);
         }
         if(c>=(A-a) ){
             int ca=c-A+a;
             if(!find_a(A,b,ca))perm (A,b,ca);
         }
         if(b<=A-a ) if(!find_a(b+a,0,c))perm(b+a,0,c);
         if(b>A-a) if(!find_a(A,b-A+a,c))perm(A,b-A+a,c);
         if(c<=A-a) if(!find_a(a+c,b,0))perm(a+c,b,0);
         if(c>A-a) if(!find_a(A,b,c-A+a))perm(A,b,c-A+a);
     }
     if(b<=B){
         if(a>=(B-b)){
             int ab=a-(B-b);
             if(!find_a(ab,B,c)) perm (ab,B,c);
         }
         if(c>=(B-b)){
             int cb=c-B+b;
             if(!find_a(a,B,cb)) perm (a,B,cb);
         }
         if(a<=B-b ) if(!find_a(0,b+a,c))perm(0,b+a,c);
         if(a>B-b) if(!find_a(a-B+b,B,c))perm(a-B+b,B,c);
         if(c<=B-b) if(!find_a(a,b+c,0))perm(a,b+c,0);
         if(c>B-b) if(!find_a(a,B,c-B+b))perm(a,B,c-B+b);
     }
     if(c<=C ){

         if(a>=(C-c)){
             int aa=a-(C-c);
             if(!find_a(aa,b,C))perm (aa,b,C);
         }
         if(a<=C-c ) if(!find_a(0,b,c+a))perm(0,b,c+a);
         if(a>C-c) if(!find_a(a-C+c,b,C))perm(a-C+c,b,C);
         if(b<=C-c) if(!find_a(a,0,b+c))perm(a,0,b+c);
         if(b>C-c) if(!find_a(a,b-C+c,C))perm(a,b-C+c,C);
         if(b>=(C-c)){
             int bc=b-C+c;
             if(!find_a(a,bc,C))perm (a,bc,C);
         }
     }


}
int main() {

   ofs.open ("milk3.out");
   ifs.open ("milk3.in");

   ifs>>A>>B>>C;
   solu.push_back(new mypair(A,B,C));
   perm(0,0,C);



   sort(solutions.begin(),solutions.end());
   int i=1;
   int last=solutions[0];
   while(i<solutions.size()){
      if(solutions[i]==last) solutions.erase(solutions.begin()+i);
      else{ if(i<solutions.size()){last=solutions[i]; i++;}
       }
   }
    for(int i=0; i<solutions.size()-1;i++){
         ofs<<solutions[i]<<" ";
    }
    ofs<<solutions[solutions.size()-1]<<"\n";

   return 0;
}

