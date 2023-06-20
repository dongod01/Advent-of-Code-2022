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

int comparesquarebrackets(string s1,string s2){
    if(s1=="[]" && s2!="[]") return 1;
    if(s1!="[]" && s2=="[]") return -1;
    if(s1==s2) return 0;
    queue<string> q1,q2;
    int cur=0;
    string s;
    for(int i=0;i<s1.size();i++){
        if(s[i]==',') continue;
        if(s1[i]=='[') cur++;
        if(s1[i]==']') cur--;
        if(cur>1 || (cur==1 && s=="")) s.push_back(s1[i]);
        if(cur==1 && s!=""){
            q1.push(s);
            s="";
        }
    }
    swap(s1,s2);
    for(int i=0;i<s1.size();i++){
        if(s[i]==',') continue;
        if(s1[i]=='[') cur++;
        if(s1[i]==']') cur--;
        if(cur>1 || (cur==1 && s=="")) s.push_back(s1[i]);
        if(cur==1 && s!=""){
            q2.push(s);
            s="";
        }
    }
    swap(s1,s2);
    while(!q1.empty() && !q2.empty()){
        int x = compare(q1.front(),q2.front());
        if(x==0){
            q1.pop();
            q2.pop();
            continue;
        }
        return x;
        break;
    }

    if(q1.empty() && q2.empty()) return 0;
    else if(q1.empty()) {
        return 1;
    }
    else return -1;
    
    return 123456;

}

int main(){
    string s1,s2,s3;
    int pairIndex=0,ans=0;
    while(cin>>s1>>s2){
        // IMPORTANT COMMENT
        // Previous attempt, where i just added all-
        // numbers to queues q1 and q2
        // Special case of two empty queues, checked by comparesqbrackets
        // Incorrect, this eg:
        // [[[[8,9,3,6,4],[9,10,3],[],6],[4,1,[0,2,3]],4,[[9,6],10,9,0]],[[[9,8,1,0],[8,9,5,4,6]]],[[]],[[3],6,[2,6,8,[2,1,3,3,6],[4,7,5,1]]],[2]]
        // [[],[10],[[4],10,[8]]]
        // Acc to me s1<s2 bcoz 8 < 10
        // But there its vs [[[8,9,3,6,4],[9,10,3],....
        // vs an empty []. So s1>s2

        // queue<int> q1,q2;
        // for(int i=0;i<s1.size();i++){
        //     if(s1[i]<'0' || s1[i]>'9') continue;
        //     int st=i;
        //     while(s1[i]>='0' && s1[i]<='9'){
        //         i++;
        //     }
        //     q1.push(stoi(s1.substr(st,i-st)));
        // }
        // swap(s1,s2);
        // for(int i=0;i<s1.size();i++){
        //     if(s1[i]<'0' || s1[i]>'9') continue;
        //     int st=i;
        //     while(s1[i]>='0' && s1[i]<='9'){
        //         i++;
        //     }
        //     q2.push(stoi(s1.substr(st,i-st)));
        // }
        // swap(s1,s2);
        
        // if(q1.empty() && q2.empty()){
        //     cout<<comparesquarebrackets(s1,s2)<<endl;
        //     if(comparesquarebrackets(s1,s2)>=0){
        //         cout<<"(Empty queues)Adding "<<pairIndex+1<<endl;
        //         ans+=pairIndex+1;
        //     }
        //     continue;
        // }

        // while(!q1.empty() && !q2.empty()){
        //     if(q1.front()==q2.front()){
        //         q1.pop();
        //         q2.pop();
        //         continue;
        //     }
        //     if(q1.front()<q2.front()) {
        //         cout<<pairIndex<<" "<<q1.front()<<" "<<q2.front()<<endl;
        //         cout<<"Adding "<<pairIndex+1<<endl;
        //         ans+=pairIndex+1;
        //     }
        //     break;
        // }
        // if(q1.empty()) {
        //     ans+=pairIndex+1;
        //     cout<<"Adding "<<pairIndex+1<<endl;
        //     cout<<pairIndex<<endl;
        // }
        
        // while(!q1.empty()) {
        //     // cout<<q1.front()<<" ";
        //     q1.pop();
        // }
        // // cout<<endl;
        // while(!q2.empty()){
        //     // cout<<q2.front()<<" ";
        //     q2.pop();
        // } 
        // cout<<endl<<"Index: "<<pairIndex+1<<endl;
        if(compare(s1,s2)>=0){
            ans+=pairIndex+1;
            cout<<"Added pair "<<pairIndex+1<<"\n";
        }
        
        pairIndex++;  
        cout<<"\n\n\n";  
    }
    // string s1 = "abcdef";
    
    cout<<"Answer: "<<ans<<"\n\n\n\n\n\n\n\n";  

    s1 = "[1,1,3,1,1]";
    s2 = "[1,1,5,1,1]";

    cout<<compare(s1,s2)<<endl;
}