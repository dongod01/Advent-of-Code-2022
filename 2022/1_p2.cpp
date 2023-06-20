#include <iostream>
#include <climits>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int mx=INT_MIN,sm=0;
    string s;
    vector<int> v;
    while(getline(cin,s)){
        // if(s=="\0") break;
        cout<<"*"<<s<<"*"<<endl;

        if(s==""){
            if(sm!=0) {
                v.push_back(sm);
            }
            sm=0;
        }
        else {
            sm+=stoi(s);
            cout<<sm<<endl;
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<"Result: "<<v[0] + v[1]+v[2]<<endl;
}
