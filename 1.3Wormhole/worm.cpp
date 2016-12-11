/*
ID: alexisk2
PROG: wormhole
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>

int N;
std::ifstream ifs;
std::ofstream ofs;
using namespace std;
int count_sol=0;
int x_max=0;
int y_max=0;

struct coord{
  int x,y;
  coord(int x_a,int y_a):x(x_a),y(y_a){}
};

struct mypair{
  int p1;
  int p2;
  mypair(int x_a,int y_a):p1(x_a),p2(y_a){}
};

vector<coord*> coords;
vector<mypair*> pairs;

bool acompare(coord* lhs, coord *rhs) {
    if(lhs->x==rhs->x) return lhs->y < rhs->y;
    else return lhs->x < rhs->x;
}

//sort(stalls.begin(),stalls.end(),acompare);
bool if_x(int p1, int &pos){
    for(int i=0;i<coords.size();i++){
        if(coords[i]->x>coords[p1]->x & coords[i]->y==coords[p1]->y  ){
            pos=i;
            return true;
        }
    }
    return false;
}


bool search(int e1,vector<int> pin){

    bool f=false;
    int target=e1;
    while(!f){
        int pos;
        if(if_x(target,pos) ){
            pos = find(pin.begin(), pin.end(), pos) - pin.begin();
            if(pos==pin.size())return false;
            if(pos%2==0){
               target=pin[pos+1];
               if(target==e1)return true;
            }else{
               target=pin[pos-1];
               if(target==e1)return true;

            }
        }else{
            return false;
        }
    }


}


bool check(vector<int> pin){

//cout<<"XXX\n";
/*for(int i=0; i<pin.size();i++){
    cout<<pin[i]<<" ";
}cout<<"\n ";*/



    for(int i=0; i<pin.size();i=i+2){

        if(coords[pin[i]]->y==coords[pin[i+1]]->y ){
                 if(pin[i]<pin[i+1]){
                     if(search(pin[i],pin)){
                        count_sol++;
                        return  true;
                     }
                 }

         }

        if(pin.size()%2==0){
        if(search(pin[i],pin)){
            count_sol++;
            return  true;
        }
        if(search(pin[i+1],pin)){
           count_sol++;
           return  true;
        }
        }

    }
    return false;
}
void perm(vector<int> pin){

    if(pin.size()>=(N)){

        check(pin);
        return;
    }
 if(pin.size()==0) { pin.push_back(0);}
 else{
     pin.push_back(0);
     for(int i=0;i<(N);i++){
         vector<int>::iterator f=find(pin.begin(),pin.end(),i);
         if(f==pin.end()){
             pin[pin.size()-1]=i;
             break;
         }
     }
 }

    pin.push_back(0);
    for(int i=0;i<(N);i++){
        vector<int>::iterator f=find(pin.begin(),pin.end(),i);
        if(f==pin.end()){
            pin[pin.size()-1]=i;
            perm(pin);

        }
    }

}

void fill_up(int m){
    int x,y;
    for(int i=0; i<m; i++){
        ifs>>x>>y;
        if(x>x_max) x_max=x;
        if(y>y_max) y_max=y;
        coords.push_back(new coord(x,y));
    }
}
int main() {

   ofs.open ("wormhole.out");
   ifs.open ("wormhole.in");

   ifs>>N;
   fill_up(N);
   sort(coords.begin(),coords.end(),acompare);
   for(int i=0; i<N; i++){
       cout<<coords[i]->x<<" "<<coords[i]->y<<" \n";
   }
   count_sol=0;
   vector<int> aa;
   //aa.push_back(0);
   perm(aa);

   ofs<<count_sol<<"\n";
   return 0;
}

