 
/*
ID: alexisk2
PROG: crypt1
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
void fillUp(int m){
    int next=0;
    for(int i=0;i<m;++i){
         ifs>>next;
         if(!ifs.eof()){
            digits.push_back(next);
        }
    }
}

bool isDigitInset(int a){
    for(int i=0;i<digits.size();++i){
        if(digits[i]==a) return true;
    }
    return false;
}
void check(vector<int> inp){
    int prd=0;
    int ex=0;
    vector<int> aa;

    for(int i=2;i>=0;i--){
        prd=(inp[i]*inp[4]+ex)%10;
        int ex2=ex;
        ex=(inp[i]*inp[4]+ex)/10;
        aa.push_back(prd);
        if(!isDigitInset(prd)) return;
    }
    if(ex!=0 & !isDigitInset(ex)) return;
    if(ex!=0) aa.push_back(ex);
    if(aa.size()>3) return;
    vector<int> bb;
    ex=0;
    for(int i=2;i>=0;i--){
        prd=(inp[i]*inp[3]+ex)%10;
        ex=(inp[i]*inp[3]+ex)/10;
        bb.push_back(prd);
        if(!isDigitInset(prd)) return;
    }
    if(ex!=0 & !isDigitInset(ex)) return;
    if(ex!=0) bb.push_back(ex);
    if(bb.size()>3) return;

    ex=0;
    bb.insert(bb.begin(),0);
    vector<int> cc;
    for(int i=0;i<aa.size();i++){
        prd=(aa[i]+bb[i]+ex)%10;
        ex=(aa[i]+bb[i]+ex)/10;
        cc.push_back(prd);
        if(!isDigitInset(prd)) return;
    }
    for(int i=(aa.size());i<(bb.size());i++){
        prd=(bb[i]+ex)%10;
        ex=(bb[i]+ex)/10;
        cc.push_back(prd);
        if(!isDigitInset(prd)) return;
    }
    if(ex!=0 & !isDigitInset(ex)) return;
    if(ex!=0) cc.push_back(ex);
    count_sol++;
    int a;
}
void perm(vector<int> inp,int pos){
    if(pos==5){
        check(inp);
    }else{
        inp.push_back(0);
        for(int i=0; i<digits.size(); ++i){
            inp[pos]=digits[i];
            perm(inp,pos+1);
        }
    }

}

int main() {

    ofs.open ("crypt1.out");
    ifs.open ("crypt1.in");

    count_sol=0;

    int m;
    ifs>>m;
    fillUp(m);
    sort (digits.begin(), digits.end());
    vector<int> inp;
    perm(inp,0);

    ofs<<count_sol<<"\n";
    return 0;
}
