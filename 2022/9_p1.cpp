#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char,pair<int,int>> dir = {{'L',{-1,0}},{'R',{1,0}}
                               ,{'U',{0,1}},{'D',{0,-1}}};

int main(){
    set<pair<int,int>> vis;
    int steps;
    char c;
    int t[2],h[2],x=0,y=0;
    t[0] = t[1] = 0;
    h[0] = h[1] = 0;
    vis.insert({0,0});
    int cnt=0;
    while(cin>>c>>steps){
        cnt++;
        while(steps--){
            x+=dir[c].first;
            y+=dir[c].second;
            if(abs(x-t[0])>=2 || abs(y-t[1])>=2){
                t[0] = h[0];
                t[1] = h[1];
                if(vis.find({t[0],t[1]})==vis.end()){
                    // cout<<t[0]<<" "<<
                    vis.insert({t[0],t[1]});
                }
            }
            h[0] = x; h[1] = y;
        }

    }
    cout<<cnt<<" ";
    cout<<vis.size()<<endl;

    // for(auto pr: vis){
    //     cout<<"("<<pr.second<<","<<pr.first<<")"<<endl;
    // }
}