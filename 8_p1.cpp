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

// Solution idea: Visit matrix from all directions, brute force

int main(){
    string s;
    int rows=0,cols;
    int cnt=0;
    vector<string> arr;
    while(getline(cin,s)){
        cols=s.size();
        arr.push_back(s);
        rows++;
    }
    cout<<rows<<"x"<<cols<<endl;
    cout<<"Input taken\n";
    vector<vector<int>> vis(rows,vector<int>(cols,0));
    
    for(int i=0;i<rows;i++){
        int last_max = -1;
        for(int j=0;j<cols;j++){
            if((int)(arr[i][j] - '0') > last_max){
                last_max = (int)(arr[i][j]-'0');
                if(vis[i][j]==0){
                    cnt++;
                    vis[i][j]++;
                }
            }
        }
        // cout<<cnt<<": cnt"<<endl;
        last_max = -1;
        for(int j=cols-1;j>=0;j--){
            if(arr[i][j] - '0' > last_max){
                last_max = (arr[i][j]-'0');
                if(vis[i][j]==0){
                    cnt++;
                    vis[i][j]++;
                }
            }
        }
    }

    for(int j=0;j<cols;j++){
        int last_max = -1;
        for(int i=0;i<rows;i++){
            if((int)(arr[i][j] - '0') > last_max){
                last_max = (int)(arr[i][j]-'0');
                if(vis[i][j]==0){
                    cnt++;
                    vis[i][j]++;
                }
            }
        }
        // cout<<cnt<<": cnt"<<endl;
        last_max = -1;
        for(int i=rows-1;i>=0;i--){
            if(arr[i][j] - '0' > last_max){
                last_max = (arr[i][j]-'0');
                if(vis[i][j]==0){
                    cnt++;
                    vis[i][j]++;
                }
            }
        }
    }

    cout<<cnt;
    
}