/*
ID: alexisk2
PROG: namenum
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>      // std::out_of_range

using namespace std;
string dictData[5000];
int totalData=0;
map<array<char, 13>,bool> map_f;

const string arr[8][3] = {  {"A","B","C"},
                        {"D","E","F"},
                        {"G","H","I"},
                        {"J","K","L"},
                        {"M","N","O"},
                        {"P","R","S"},
                        {"T","U","V"},
                        {"W","X","Y"}};
std::ifstream ifs;
std::ifstream dict;
std::ofstream ofs;
int ndi=0;

int count=0;
bool linear_search(string name){
    string line="";
    int i=ndi;
    bool found =false;
    while((!found) & (i<totalData) ){
        if (dictData[i]==name){
            ofs<<name<<"\n";
            count++;
            ndi=i;
        }
        i++;
    }
}

bool search(string name){
    string line="";
    int i=ndi;
    bool found =false;

    try {
       array<char, 13> fa;
       for(int x=0;x<name.length();++x){ fa[x]=name[x];}
       for(int x=name.length();x<13;x++){fa[x]='\0';}
       int f=map_f[fa];      // vector::at throws an out-of-range

       if(f==1){
            ofs<<name<<"\n";
            count++;
       }
     }
     catch (const std::out_of_range& oor) {
        return false;
     }
}


void permutations( long long num,string perm){
    if(num==0){
        search(perm);
    }else{
        long long n=num%10;
        num=num/10;
        string permb=perm+arr[n-2][0];
        permutations(num,permb);
        permb=perm+arr[ n-2 ][1];
        permutations(num,permb);
        permb= perm+arr[ n-2 ][2];
        permutations(num,permb);
    }

}

int pos=0;
bool c_search(string name){

    if(pos==totalData) return false;
         if( name.length() > dictData[pos].length() ){
         bool found=false;
         found =false;
         while((!found) & (pos<totalData ) ){
                  if(name.length() > dictData[pos].length() ) pos++;
                  else found=true;
         }
         if(pos==totalData) return false;
     }


     if(name.length()>=2) if(int(name[name.length()-2])<int(dictData[pos][name.length()-2]) )return false;

     if( name[name.length()-1]!= dictData[pos][name.length()-1] ){
         if(int(dictData[pos+1][name.length()-1])==0) return false;
         if(int(name[name.length()-1])<int(dictData[pos+1][name.length()-1]) )   return false;
         if(int(name[name.length()-2])<int(dictData[pos+1][name.length()-2]) )   return false;
         pos++;

         bool found=false;
         while((!found) & (pos<totalData ) ){
            if(int(dictData[pos+1][name.length()-1])==0) return true;
                  if(int(name[name.length()-1])>int(dictData[pos][name.length()-1]) ){ pos++;}
                  else{
                      if( name[name.length()-1]!= dictData[pos][name.length()-1] ) return false;
                      else return true;
                  }
         }
         if(pos==totalData) return false;
     }

     if( name[name.length()-1]== dictData[pos][name.length()-1] ) return true;

    return false;
}

void permutations_b( long long num,string perm){
    if(num==0){
        if(perm==dictData[pos]) {
           ofs<<perm<<"\n";
           count++;
        }
    }else{
        long int n=num%10;
        num=num/10;

        string permb=perm+arr[n-2][0];
        if(!(int(permb[permb.length()-2])>int(dictData[pos][permb.length()-2]) )){
            if(c_search(permb)) permutations_b(num,permb);
        }

        permb=perm+arr[n-2][1];
        if(!(int(permb[permb.length()-2])>int(dictData[pos][permb.length()-2])) ){
            if(c_search(permb)) permutations_b(num,permb);
         }

        permb=perm+arr[n-2][2];
        if(!(int(permb[permb.length()-2])>int(dictData[pos][permb.length()-2])) ){
            if(c_search(permb)) permutations_b(num,permb);
        }


    }

}
void fill_up(){
    dict.open("dict.txt");
    string line="";

    int i=0;
    while(!dict.eof()){
        dict>> dictData[i];

        i++;
    }
    totalData=i;

    dict.close();
}

void fill_up_map(){
    dict.open("dict.txt");
    string line="";
    int i=0;
    string s;
    while(!dict.eof()){
        dict>> s;
        array<char, 13> f;
        for(int x=0;x<s.length();++x){ f[x]=s[x];}
        for(int x=s.length();x<13;x++){f[x]='\0';}

        map_f[f]=1;
        i++;
    }
    totalData=i;
    dict.close();


}

int main() {
    ofs.open ("namenum.out");
    ifs.open ("namenum.in");

    string b;
    fill_up();

    ifs>>b;
    string c="";
    for (std::string::reverse_iterator rit=b.rbegin(); rit!=b.rend(); ++rit)
       c=c+*rit;
    long long a =std::stoll(c);
    b="";

    permutations_b(a,b);
    if(count==0) ofs<<"NONE\n";
    return 0;
}
