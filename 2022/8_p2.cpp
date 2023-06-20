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
    
    int max_score = -1,cur=1,len=0;

    cout<<"Visited\n";

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            cur=1;

            len=0;
            for(int k=i-1;k>=0;k--){
                len++;
                if(arr[k][j]>=arr[i][j]) break;
            }
            cur*=len;
            if(i==55 && j==50) cout<<"Len values:"<<len<<",";
            if(i==3 && j==2) cout<<"Len values:"<<len<<",";

            len=0;
            for(int k=i+1;k<rows;k++){
                len++;
                if(arr[k][j]>=arr[i][j]) break;
            }
            cur*=len;
            if(i==55 && j==50) cout<<len<<",";
            if(i==3 && j==2) cout<<len<<",";


            len=0;
            for(int k=j-1;k>=0;k--){
                // cout<<"Stuck in "<<k<<" "<<i<<" "<<j<<endl;
                len++;
                if(arr[i][k]>=arr[i][j]) break;
            }
            cur*=len;
            if(i==55 && j==50) cout<<len<<",";
            if(i==3 && j==2) cout<<len<<",";

            len=0;
            for(int k=j+1;k<cols;k++){
                len++;
                if(arr[i][k]>=arr[i][j]) break;
            }
            cur*=len;
            if(i==55 && j==50) cout<<len<<"\n";
            if(i==3 && j==2) cout<<len<<"\n";

            if(cur >= max_score){
                max_score = cur;
                cout<<i<<" "<<j<<" "<<cur<<endl;
            }
            
        }
        // std::cout<<"i check value : "<<i<<endl;
    }

    cout<<max_score;
    
}