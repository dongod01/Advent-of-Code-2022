#include <iostream>
#include <climits>
#include<string>
using namespace std;

int main(){
    int mx=INT_MIN,sm=0;
    string s;
    while(getline(cin,s)){
        // if(s=="\0") break;
        cout<<"*"<<s<<"*"<<endl;

        if(s==""){
            if(sm!=0) mx = max(mx,sm);
            sm=0;
        }
        else {
            sm+=stoi(s);
            cout<<sm<<endl;
        }
    }
    mx = max(mx,sm);
    cout<<"Result: "<<mx<<endl;
}
