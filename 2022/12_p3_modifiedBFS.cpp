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

This is a complete but .... wrong implementation of part 2. I understood that all
positions at the same alphabets have the same level, thus generated this o/p for this I/p

Sabqponm        0 0 1 16 15 14 13 12 
abcryxxl        0 1 2 17 24 23 23 11        (Note the 23s for the xs)
accszExk        0 2 2 18 25 25 23 10 
acctuvwj        0 2 2 19 20 21 22  9
abdefghi        0 1 3  4  5  6  7  8 

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
        cout<<"{"<<cur.fi<<","<<cur.se<<"}\n";
        for(int i=0;i<4;i++){
            int x = cur.fi+dir[i].fi, y = cur.se + dir[i].se;
            // if(cur==st) cout<<mat[0][0]<<" "<<mat[1][0]<<endl;
            if(issafe({x,y},mat.size(),mat[0].size()) &&
                                (mat[cur.fi][cur.se]>=mat[x][y]-1)){
                
                if(dist[x][y]==-1) {
                    if (mat[cur.fi][cur.se]==mat[x][y]) dist[x][y] = dist[cur.fi][cur.se];
                    else dist[x][y] = dist[cur.fi][cur.se]+1;
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
    dist[start.fi][start.se] = 0;

    BFS(start);

    cout<<"Min distance: "<<dist[end.fi][end.se]<<endl;
    for(auto vec: dist){
        for(auto elem: vec){
            cout<<elem<<" ";
        }
        cout<<endl;
    }


}