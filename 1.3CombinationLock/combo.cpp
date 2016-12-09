 /*
ID: alexisk2
PROG: combo
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

vector<int> digits;
int count_sol=0;
int lock1[3]={0,0,0};
int lock2[3]={0,0,0};

int N=0;


bool check_a(int inp[3]){
    int distance=0;
    for(int i=0;i<3;i++){
        distance=abs(lock1[i]-inp[i]);
        if(distance>(N>>1)) distance=N-distance;
        if(distance>2) return false;
    }

    count_sol++;
    return true;
}

void check_b(int inp[3]){
    int distance=0;
    for(int i=0;i<3;i++){
        distance=abs(lock2[i]-inp[i]);
        if(distance>(N>>1)) distance=N-distance;
        if(distance>2) return;
    }
    count_sol++;
}
void perm(int inp[3],int pos){
    if(pos==3){
       if(!check_a(inp)) check_b(inp);
    }else{
        for(int i=1;i<=N;i++){
            inp[pos]=i;
            perm(inp,pos+1);
        }
    }
}

int main() {

    ofs.open ("combo.out");
    ifs.open ("combo.in");

    count_sol=0;

    ifs>>N;
    ifs>>lock1[0]>>lock1[1]>>lock1[2];
    ifs>>lock2[0]>>lock2[1]>>lock2[2];
    int a[3]={0,0,0};
    perm(a,0);
    cout<<count_sol<<"\n";

    ofs<<count_sol<<"\n";
    return 0;
}
