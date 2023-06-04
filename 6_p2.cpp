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
    int i=0,cur_len=0;
    string s;
    map<char,int> mp;
    for(char c='a';c<='z';c++){
        mp[c] = -14;
    }
    cin>>s;
    for(;i<s.size();i++){
        if(mp[s[i]]+cur_len<i){
            cur_len++;
            mp[s[i]]=i;
            if(cur_len==14) {
                cout<<s.substr(i-13,14);
                break;
            }
        }
        else{
            cur_len = i - mp[s[i]];
            mp[s[i]]=i;
        }
    }
    cout<<endl<<i+1;
}