#include <iostream>
#include <climits>
#include<string>
#include<map>
#include <set>
using namespace std;

int main(){
    string s;
    int sum=0,c=0;
    map<char,int> mp;
    set<char> settt;
    while(getline(cin,s)){
        settt.clear();
        if(c%3==0) mp.clear();
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(settt.find(ch)==settt.end())
            {
                mp[ch]+=1;
                settt.insert(ch);
                //if(ch=='r') cout<<"r: "<<mp[ch]<<endl;
                if(mp[ch]==3){
                    cout<<ch<<" "<<((ch>'Z')? ch-'a'+1 : ch-'A'+27 )<<endl;
                    sum+= (ch>'Z')? ch-'a'+1 : ch-'A'+27;
                    break;
                }
            }
        }
        c++;
    }

    cout<<sum<<endl;
}