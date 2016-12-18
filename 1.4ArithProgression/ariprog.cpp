 
/*
ID: alexisk2
PROG: ariprog
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>

int N,M;
std::ifstream ifs;
std::ofstream ofs;
using namespace std;


int cnt=0;
vector<int> states;
struct mpair{
  int pos,dif;
};

bool acompare(mpair* lhs, mpair *rhs) {
    if(lhs->dif==rhs->dif) return lhs->pos < rhs->pos;
    else return lhs->dif < rhs->dif;
}

vector<int> solutions;
vector<int> solutions_b;
vector<mpair*> solutions_c;

void fill_up(int m){
    for(int i=0; i<=m; i++){
        for(int x=i; x<=m; x++){
            states.push_back(pow(i,2)+pow(x,2));
        }
    }
}

int count_length(int pos,int dif){
    int cc=0;
    bool f=true;
    while(f){
          int x=states[pos];
          int d=states.size();
          int aa=states.size();
          for(int i=pos;i<aa;i++){

              if(states[i]==x+dif){
                  d=i;
                  i=aa;
              }
              if(states[i]>x+dif){
                  d=aa;

                  i=aa;
              }
          }
          //if cc > N!!
          if(d!=aa){
              cc++;
              pos=d;
           //   cout<<pos;
          }else{
              f=false;
          }
    }

    return cc;
}
int last_state=0;
int last_len=0;
int last_dif=0;

int find_next(int pos, int diff){
   for(int i=pos+1;i<states.size();i++){
//       cout<<"aasds/// "<<i<<"  "<<states.size()<<" "<<(states[pos]+diff)<< "  "<<"" <<"\n";
      //  if(i>=states.size()) return 0;

   		if(states[i]==(states[pos]+diff)){

           return i;
        }
        if(states[i]>(states[pos]+diff)){

           return 0;
        }
   }
   return 0;
}
void check(int dif){

    for(int i=0;i<states.size()-N;i++){
           if(states[i]>(states[states.size()-1]-2*dif)) break;
           if(states[i+1]-states[i]<=dif){

           int len=count_length(i,dif);
           // cout<<dif<<" "<<i<<" "<<states[i]<<" "<<len<<"\n";

           if(len>=(N-1)) {
         //      cout<<"AAA:"<<i<<" "<< states[i]<<" "<<len<<" "<<dif<<" " << last_state<<" "<< last_len <<"\n";
               bool f=false;
               if(last_state==0 & last_len==0){
                 f=true;
               }else{
                   if(last_state!=states[i]){
                       f=true;

                    }else{
                     if(last_dif!=dif){
                               f=true;

                           }
                       }
                   }



               if(f){
                last_state=states[i];
                last_len=len;
                last_dif=dif;
                ofs<<states[i]<<" "<<dif<<"\n";
             
                cnt++;
                 
                }
               }

           }
    }

}


//WORKS
void check_1(int dif){
    vector <int> next;


    for(int i=0;i<states.size()-1;i++){

       next.push_back(find_next(i,dif));

    }

	for(int i=0;i<states.size();i++){

        while( i<next.size() & next[i]==0) i++;

    	bool f=false;
        int t=i;
		int len=0;
    	while(!f){

			if(next[t]!=0 & len<(N-1) & t <next.size()){
				len++;
                t=next[t];

			}else{
             f=true;
            }
		}

        if(len>=(N-1)) {
               if(last_state!=states[i] | last_len!=len |  last_dif!=dif){
                last_state=states[i];
                last_len=len;
                last_dif=dif;
                cnt++;
                mpair* a=new mpair();
                a->dif=dif;
                a->pos=states[i];
                solutions_c.push_back(a);
                }
               }
          
       
    }
    
}
//Works with sorting in the end
void check_2(){
    int max=states[states.size()-1]-states[0];
    max=(max>>1)+1;
	for(int i=0;i<states.size();i++){
        for (int dif=1;dif<=max;dif++){   
           int pos=find_next(i, dif);
           int len=0;
           while(pos!=0){
           		len++;
			    pos=find_next(pos, dif);
              //  if(pos>=states.size())pos=0;
           }
          //  cout<<"p\n";
           if(len>=N-1){
		          bool f=false;
               if(last_state==0 & last_len==0){
                 f=true;
               }else{
                   if(last_state!=states[i]){
                       f=true;

                    }else{
                     if(last_dif!=dif){
                               f=true;

                           }
                       }
                   }



               if(f){
                last_state=states[i];
                last_len=len;
                last_dif=dif;
 			 //    ofs<<states[i]<<" "<<dif<<"\n";
                 cnt++;
  			    mpair* a=new mpair();
                a->dif=dif;
                a->pos=states[i];
                solutions_c.push_back(a);
                }
           }
        }
		int len=0;
    
    }
    
}
int main() {

   ofs.open ("ariprog.out");
   ifs.open ("ariprog.in");

   ifs>>N;
   ifs>>M;
   cout<<N<<" "<<M<<"\n";
   fill_up(M);
   sort(states.begin(),states.end());

   int i=1;
   int last=states[0];
   cout<<states.size();
   while(i<states.size()){
      if(states[i]==last) states.erase(states.begin()+i);
      else{ if(i<states.size()){last=states[i]; i++;}
       }
   }
;
   int d_max=0;

int c=3*(states[states.size()-1]-states[0])/(log2(states.size()/N))/4;

if(states.size()>3000){
   c=1*(states[states.size()-1]-states[0])/(log2(states.size()/N))/5+180;
}
if(states.size()>6000){
    c=1*(states[states.size()-1]-states[0])/(log2(states.size()/N))/7;
}
int min=1;
if(states.size()>20000){
    c=2800;//1*(states[states.size()-1]-states[0])/(log2(states.size()/N))/20;
   min=2700;
}
    for(int x=min;x<c;x++){
       check_1(x);
   }
sort(solutions_c.begin(),solutions_c.end(),acompare);
for(int i=0;i<solutions_c.size();++i){
//cout<<"AA"<<solutions_c[i]->pos<<" "<<solutions_c[i]->dif<<"\n";
	ofs<<solutions_c[i]->pos<<" "<<solutions_c[i]->dif<<"\n";
}
 
   if(cnt==0) ofs<<"NONE\n";
   return 0;
}

