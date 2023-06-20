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
    string s;
    while(getline(cin,s)){
        cnt++;
        if(cycle%40==19){
            // cout<<cnt<<endl;
            cout<<"Cycle "<<cycle+1<<": "<<cur<<endl;
            if(cycle<=220)sum+=cur*(cycle+1);
        }
        if(s.size()>4){
            if(cycle%40==18){
                // cout<<cnt<<endl;
                cout<<"Cycle(addx) "<<cycle+2<<": "<<cur<<endl;
                if(cycle<=220)sum+=cur*(cycle+2);
            }
            cycle+=2;
            if(s[5]=='-') cur-=stoi(s.substr(6,s.size()-6));
            else cur+=stoi(s.substr(5,s.size()-5));
        }
        else{
            cycle+=1;
        }
        // if(cnt>=131) cout<<endl<<s<<endl<<cycle<<" "<<cur<<endl;
    }

    cout<<"Sum: "<<sum;
    
}