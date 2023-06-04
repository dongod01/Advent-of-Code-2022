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
    int i=0;
    string s;
    cin>>s;
    for(;i<s.size()-3;i++){
        if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i]!=s[i+3] && s[i+2]!=s[i+1] && s[i+3]!=s[i+1] && s[i+3]!=s[i+2])
            {
                cout<<s.substr(i,4)<<endl;
                break;
            }
    }
    cout<<endl<<i+4;
}