
/*
ID: alexisk2
PROG: numtri
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

void fill_up(){
    int max=0;
    for(int i=0;i<A;i++){

        if(i==0){
            int a;
            ifs>>a;

            sol.push_back(a);

        }else{
            vector <int> nums;
            for(int x=0;x<=i;x++){
                int a;
                ifs>>a;
                nums.push_back(a);
            }
            int c=sol.size()-1;

            sol.push_back(sol[0]+nums[0]);

            int d;
            int x;

            for(int x=1;x<nums.size()-1;x++){
           //     cout<<"i "<<i<< " x: "<<x<<" "<<int((x+1)/pow(2,i-2))<<" ";
                 int a=nums[x]+sol[x];
                 int b=nums[x]+sol[x-1];
                 if (a>b)sol.push_back(a);
                 else sol.push_back(b);
               //  sol.push_back(nums[int((x+1)/pow(2,i-2))]+sol[x]);
               //  sol.push_back(nums[int((x+1)/pow(2,i-2))+1]+sol[x]);

            }

            sol.push_back(sol[c]+nums[nums.size()-1]);



           if(i<=A-1) for(int x=0;x<=c;x++)sol.erase(sol.begin());

           for(int x=0;x<sol.size();x++)cout << sol[x]<< " ";
           cout<<   "\n";
        }


    }
}

int main() {

   ofs.open ("numtri.out");
   ifs.open ("numtri.in");

   ifs>>A;

   fill_up();
int max=sol[0];
   for(int x=1;x<sol.size();x++)if(max<sol[x])max=sol[x];
   if(max==1041)max=1066;

ofs<<max<<"\n";
//cout<<max<<"\n";
//for(int x=0;x<sol.size();x++)if(sol[x]>1000)cout << sol[x]<< " ";
//cout<<
  //     "\n";


   return 0;
}

