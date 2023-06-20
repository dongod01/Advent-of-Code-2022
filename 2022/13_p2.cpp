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

bool isdig(char ch){
    return ch>='0' && ch<='9';
}

int compare(string s1="[]",string s2="[]"){
    if(s1==s2) return 0;
    if(isdig(s1[0]) && isdig(s2[0])){
        int a1 = stoi(s1),a2 = stoi(s2);
        if(a1==a2) return 0;
        else if(a1<a2) return 1;
        return -1;
    }
    else if(isdig(s1[0])){
        return compare("["+s1+"]",s2);
    }
    else if(isdig(s2[0])){
        return compare(s1,"["+s2+"]");
    }
    else if(s1[0]=='[' && s2[0]=='['){
        if(s1=="[]" && s2!="[]") return 1;
        if(s1!="[]" && s2=="[]") return -1;

        queue<string> q1,q2;
        int cur=0;

        string s="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='[') {
                cur++;
                if(cur==1) continue;
            }
            if(s1[i]==']') {
                cur--;
                if(cur==0){
                    q1.push(s);
                    cout<<"Pushing at end "<<s<<endl;
                    s="";
                    continue;
                }
            }
            if(s1[i]==','){
                if(cur==1){
                    q1.push(s);
                    cout<<"Pushing "<<s<<endl;
                    s="";
                }
                else s.push_back(',');
                continue;
            }
            s.push_back(s1[i]);
            
        }
        swap(s1,s2);
        s="";
        cout<<"Q2:\n";
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='[') {
                cur++;
                if(cur==1) continue;
            }
            if(s1[i]==']') {
                cur--;
                if(cur==0){
                    q2.push(s);
                    cout<<"Pushing at end "<<s<<endl;
                    s="";
                    continue;
                }
            }
            if(s1[i]==','){
                if(cur==1){
                    q2.push(s);
                    cout<<"Pushing "<<s<<endl;
                    s="";
                }
                else s.push_back(',');
                continue;
            }
            s.push_back(s1[i]);
            
        }
        swap(s1,s2);

        cout<<"Sizes: "<<q1.size()<<" "<<q2.size()<<endl;

        while(!q1.empty() && !q2.empty()){
            cout<<"Front elems: "<<q1.front()<<" and "<<q2.front()<<endl;
            int x = compare(q1.front(),q2.front());
            if(x==0){
                q1.pop();
                q2.pop();
                continue;
            }
            return x;
        }

        if(q1.empty() && q2.empty()) return 0;
        else if(q1.empty()) {
            return 1;
        }
        else return -1;
    }
    
    
    
    return 123456;

}

int main(){
    string s1;
    int a2=0,a6=0;
    int pairIndex=0,ans=0;
    while(cin>>s1){
        if(compare(s1,"[[2]]")>=0){
            a2++;
        }
        if(compare(s1,"[[6]]")>=0){
            a6++;
        }
        
        pairIndex++;  
        cout<<"\n\n\n";  
    }
    // string s1 = "abcdef";
    a6+=1;
    cout<<"Answer: "<<(a2+1)<<" "<<a6+1<<" prod = "<<a2*a6+a2+a6+1;
}