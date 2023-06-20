#include <iostream>
#include <climits>
#include<string>
#include<map>
#include <set>
#include <vector>
using namespace std;
using ll=long long;

int main(){
    ll sum=0;
    string s;
    vector<ll> v(4,0);
    while(cin>>s){
        v.assign(4,0);
        // cout<<s<<endl;
        int j=0,i=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==','||s[i]=='-'){
                j++;
            }
            else{
                v[j] = 10*v[j]+(s[i]-'0');
            }
        }
        // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" ";
        if(max(v[2],v[0])<=min(v[3],v[1])) {
            // cout<<"This"<<endl;
            sum++;
        }
    }

    cout<<sum;
}