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
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

using ll=long long;

/*

Start from end
Find 'a' with least distance.
Modify neighbour condition
*/

vector<vector<int>> dist;
vector<string> mat;

vector<pii> dir{{1,0},{0,1},{-1,0},{0,-1}};

bool issafe(pii sq,int n,int m){
    return (sq.fi < n && sq.fi>=0 && sq.se < m && sq.se>=0);
}

void BFS(pii st){
    queue<pii> q;
    q.push(st);
    while(!q.empty()){
        pii cur = q.front();
        // cout<<"{"<<cur.fi<<","<<cur.se<<"}\n";
        for(int i=0;i<4;i++){
            int x = cur.fi+dir[i].fi, y = cur.se + dir[i].se;
            // if(cur==st) cout<<mat[0][0]<<" "<<mat[1][0]<<endl;
            if(issafe({x,y},mat.size(),mat[0].size()) &&
                                (mat[cur.fi][cur.se]<=mat[x][y]+1)){
                
                if(dist[x][y]==-1) {
                    dist[x][y] = dist[cur.fi][cur.se]+1;
                    q.push({x,y});
                }
                else if(dist[x][y] > dist[cur.fi][cur.se]+1){
                    dist[x][y] = dist[cur.fi][cur.se]+1;
                    q.push({x,y});
                }
            }
        }
        q.pop();
    }
    int min_dist = INT_MAX;
    for(int i=0;i<dist.size();i++){
        for(int j=0;j<dist[0].size();j++){
            if(mat[i][j]=='a' && dist[i][j]>0) min_dist = min(dist[i][j],min_dist);
        }
    }

    cout<<"Min distance from nearest 'a': "<<min_dist<<endl;
}


int main(){

    string s;
    // mat.clear();
    pii start,end;
    int i=0;
    mat.resize(0);
    while(cin>>s){
        int j=0;
        for(auto &ch: s){
            if(ch=='S') {
                start = {i,j};
                ch='a';
            }
            else if(ch=='E') {
                end = {i,j}; 
                ch='z';
            }
            j++;
        }
        mat.push_back(s);
        i++;
    }

    dist.assign(mat.size(),vector<int>(mat[0].size(),-1));
    dist[end.fi][end.se] = 0;

    BFS(end);

    for(auto vec: dist){
        for(auto elem: vec){
            cout<<elem<<" ";
        }
        cout<<endl;
    }


}