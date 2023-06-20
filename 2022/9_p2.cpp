#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

map<char,pair<int,int>> dir = {{'L',{-1,0}},{'R',{1,0}}
                               ,{'U',{0,1}},{'D',{0,-1}}};

int main(){
    set<pair<int,int>> vis;
    int steps;
    char c;
    int x=0,y=0,i;
    vector<pair<int,int>> rope(10,{0,0});
    vis.insert({0,0});
    int cnt=0;
    while(cin>>c>>steps){
        cnt++;
        while(steps--){

            for(i=0;i<9;i++){
                if(i==0){
                    x=rope[i].fi+dir[c].fi,y = rope[i].se+dir[c].se;
                }

                rope[i].fi = x;
                rope[i].se = y;
                if(abs(y-rope[i+1].se)>=2 && abs(x-rope[i+1].fi)>=2){
                    y = (y+rope[i+1].se)/2;
                    x = (x+rope[i+1].fi)/2;
                }
                else if(abs(y-rope[i+1].se)>=2){
                    y = (y+rope[i+1].se)/2;
                }
                else if(abs(x-rope[i+1].fi)>=2){
                    x = (x+rope[i+1].fi)/2;
                }
                else{
                    x = rope[i+1].fi;
                    y = rope[i+1].se;
                }

                

                if(i==8){
                    rope[i+1].fi = x;
                    rope[i+1].se = y;
                    if(vis.find({x,y})==vis.end()) {
                        vis.insert({x,y});
                        // cout<<"("<<y<<","<<x<<")"<<endl;
                    }
                }
                if(x==rope[i+1].fi && y==rope[i+1].se) break;
            }

        }


        // for(int j=16;j>=-6;j--){
        //     for(int k=-12;k<15;k++){
        //         char ch = '.';
        //         for(int f = 0;f<10;f++){
        //             if(j==rope[f].se && k==rope[f].fi){
        //                 ch = '0'+f;
        //                 if(f==0) ch='H';
        //                 break;
        //             }
        //         }
        //         if(j==0 && k==0) ch = 's';
        //         cout<<ch;
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl<<endl;

    }
    cout<<cnt<<" ";
    cout<<vis.size()<<endl;

    // for(auto pr: vis){
    //     cout<<"("<<pr.second<<","<<pr.first<<")"<<endl;
    // }
}



/*
R 5
U 8
L 8
D 3
R 17
D 10
L 25
U 20
*/

/*
R 5
U 1
U 1
U 1
U 1
U 1
U 1
U 1
U 1
*/