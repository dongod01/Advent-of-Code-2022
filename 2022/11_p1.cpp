#include <iostream>
#include <climits>
#include <cstdlib>
#include<string>
#include<map>
#include <set>
#include <vector>
#include<stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

using ll=long long;


int throw_to(int old,int num, bool test = false){
    if(num==0){
        if(test) return (old%23==0)? 2 : 3;
        return (old%2==0)? 5 : 2;
    }
    else if(num==1){
        if(test) return (old%19==0)? 2 : 0;
        return (old%13==0)? 4 : 3;
    }
    else if(num==2){
        if(test) return (old%13==0)? 1 : 3;
        return (old%5==0)? 5 : 1;
    }
    else if(num==3){
        if(test) return (old%17==0)? 0 : 1;
        return (old%3==0)? 6 : 7;
    }
    else if(num==4){
        return (old%11==0)? 7 : 3;
    }
    else if(num==5){
        return (old%17==0)? 4 : 1;
    }
    else if(num==6){
        return (old%7==0)? 0 : 2;
    }
    else{
        return (old%19==0)? 6 : 0;
    }
}


int change(int old,int num, bool test = false){
    if(num==0){
        if(test) return old * 19;
        return old * 13;
    }
    else if(num==1){
        if(test) return old + 6;
        return old + 7;
    }
    else if(num==2){
        if(test) return (int)(1ll*old * old % (1ll*13*17*19*23));
        return old + 2;
    }
    else if(num==3){
        if(test) return old + 3;
        return old * 2;
    }
    else if(num==4){
        return (int)(1ll*old * old % (1ll*2*3*5*11*7*13*17*19));
    }
    else if(num==5){
        return old + 6;
    }
    else if(num==6){
        return old + 1;
    }
    else{
        return old + 8;
    }
}

int main(){
    vector<vector<int>> dq1{{79,98},{54, 65, 75, 74},{79, 60, 97},{74}},
        dq{{91, 54, 70, 61, 64, 64, 60, 85},{82},{84,93,70},{78, 56, 85, 93}
        ,{64, 57, 81, 95, 52, 71, 58},{58, 71, 96, 58, 68, 90},{56, 99, 89, 97, 81}
        ,{68,72}};
    
    string s;
    int cnt=0;
    bool flg = true;

    while(getline(cin,s)){
        cnt++;
    }
    if(cnt<30) flg = true;
    else flg = false;

    if(flg) {
        dq = dq1;
    }
    
    int mx1=-1,mx2=-2;
    vector<queue<int>> v;
    for(auto vq: dq){
        queue<int> q;
        for(auto elem: vq) q.push(elem);
        v.push_back(q);
    }
    vector<int> counts(v.size(),0);
    cout<<"Counts\n";
    for(int j=0;j<20;j++){
        for(int i=0;i<v.size();i++){
            counts[i]+=v[i].size();
            if(counts[i]>mx1) {
                mx2 = mx1;
                mx1 = counts[i];
            }
            else if(counts[i]>mx2) mx2 = counts[i];


            while(!v[i].empty()){
                int n = v[i].front();

                n = change(n,i,flg)/3;
                v[throw_to(n,i,flg)].push(n);
                
                v[i].pop();
            }
        }
        if(j==0 || j==18 || j==19 || j==9999 || j==999 || j==1999){
            cout<<"Values after round "<<j+1<<":";
            for(auto el: counts) cout<<el<<" ";
            cout<<endl;
        }
    }

    
    
    // cout<<"\n\nAnswers\n"<<mx1<<"x"<<mx2<<"="<<1ll*mx1*mx2<<endl;
    sort(counts.begin(),counts.end(),greater<int>());
    cout<<counts[0]<<"x"<<counts[1]<<"="<<1ll*counts[0]*counts[1]<<endl;

    
}