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

// Input file can be modified, nut trying to keep this pure

int main(){
    ll sum=0;
    string s,ans="";
    vector<deque<char>> vc{{'N','W','B'},{'B','M','D','T','P','S','Z','L'},{'R','W','Z','H','Q'}, {'R','Z','J','V','D','W'},
                     {'B','M','H','S'} , {'B','P','V','H','J','N','G','L'}, {'S','L','D','H','F','Z','Q','J'}
                         ,{'B','Q','G','J','F','S','W'}, {'J','D','C','S','M','W','Z'}    };

    vector<stack<char,deque<char>>> v;
    stack<char> free_stack;
    for(auto vcd: vc){
        reverse(vcd.begin(),vcd.end());
        v.push_back(stack<char>(vcd));
    }
    
    
    while(getline(cin,s) && s!=""){
    }
    int num,from,to,c=0;
    // char ch;
    while(getline(cin,s)){
        // cout<<s<<" "<<"char "<<s[6]<<endl;
        c=0;
        if(s[6]>='0' && s[6]<='9') c++;
        num = stoi(s.substr(5,c+1));
        // cout<<num<<endl;
        // num=1;
        from = (int)(s[12+c]-'0')-1;
        to = (int)(s[17+c]-'0')-1;
        // cout<<"From; "<<from<<" To: "<<to<<endl;
        while(num--){
            // cout<<v[from].top()<<" \n";
            free_stack.push(v[from].top());
            v[from].pop();
        }
        while(!free_stack.empty()){
            // cout<<v[from].top()<<" \n";
            v[to].push(free_stack.top());
            free_stack.pop();
        }

    }
    for(int i=0;i<9;i++){
        if(!v[i].empty())ans.push_back(v[i].top());
    }

    cout<<endl<<ans;
}