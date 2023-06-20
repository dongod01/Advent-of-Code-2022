#include <iostream>
#include <climits>
#include <cstdlib>
#include<string>
#include<map>
#include <set>
#include <vector>
#include<stack>
#include <algorithm>

using namespace std;

using ll=long long;

int main(){
    int sum=0,cur = 1,cycle=0,cnt=0;
    string s,t(240,'.');
    while(getline(cin,s)){

        if(s.size()>4){
            if(abs(cycle%40-cur)<=1) t[cycle]='#';
            cycle+=1;
            if(abs(cycle%40-cur)<=1) t[cycle]='#';
            cycle+=1;

            if(s[5]=='-') cur-=stoi(s.substr(6,s.size()-6));
            else cur+=stoi(s.substr(5,s.size()-5));
        }
        else{
            if(abs(cycle%40-cur)<=1) t[cycle]='#';
            cycle+=1;
        }
        if(t[cycle]=='#' && cycle>=41) cout<<"x\n";
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<40;j++){
            printf("%c",t[40*i+j]);
        }
        printf("\n");
    }

    // cout<<"Sum: "<<sum;
    
}