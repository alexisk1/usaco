/*
ID: alexisk2
PROG: barn1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>

std::ifstream ifs;
std::ofstream ofs;
using namespace std;

struct stall{
    int a;
    int b;
    stall( int a,int b){
      this->a=a;
      this->b=b;
    }
};

vector<stall *> stalls;
vector<int> positions;

int m,s,c;
int cows=0,empty=0;
int length=0;

void fillUp(){
    int next;

    int pos=next;
    cows=1;
    length=0;
    while(!ifs.eof()){
         ifs>>next;
         if(!ifs.eof()){
            positions.push_back(next);

        }
    }
}
int bd=0;

//bool acompare(stall* lhs, stall *rhs) { return lhs->a < rhs->a; }
//sort(stalls.begin(),stalls.end(),acompare);


void opt_new(){
    int min=positions[positions.size()-1]-positions[0];
    int min_p=0;

    int pp_max=0;
    int ppa_max=0;
    int ppp_max=0;

    for(int c=0;c<stalls.size();c++){
        int max=0;
        int p_max=0;
        int empty=0;
        if(stalls[c]->a<stalls[c]->b){
            for(int x=stalls[c]->a;x<stalls[c]->b;x++){
                int p1=x;
                int p2=x+1;
                if( (positions[p2]-positions[p1])>max){
                    max=(positions[p2]-positions[p1])-1;
                    p_max=x;
                }
            }
            if(max>pp_max){
                pp_max=max;
                ppa_max=p_max;
                ppp_max=c;
            }
        }
    }

    int ccc=stalls[ppp_max]->b;
    stalls[ppp_max]->b=ppa_max;
    stalls.insert(stalls.begin()+ppp_max+1,new stall(ppa_max+1,ccc) );

}
int main() {

    ofs.open ("barn1.out");
    ifs.open ("barn1.in");

    ifs>>m>>s>>c;
    bd=m;
    fillUp();
    sort (positions.begin(), positions.end());
    if(m==1){
        ofs<<positions[positions.size()-1]-positions[0]+1<<"\n";
        return 0;
    }
    if(m>c){
         ofs<<c<<"\n";
         return 0;
    }


    stall *jj=new stall(0,positions.size()-1);
    stalls.push_back(jj);

    for(int i=1;i<(m);++i){
        opt_new();
    }

    for(int i=0;i<(stalls.size());++i){
            length+= positions[stalls[i]->b]-positions[stalls[i]->a]+1;
    }

    ofs<<length<<"\n";
    return 0;
}
