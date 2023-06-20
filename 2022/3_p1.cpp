#include <iostream>
#include <climits>
#include<string>
#include<map>
#include <set>
using namespace std;

int main(){
    string s;
    int sum=0;
    set<char> sett;
    while(getline(cin,s)){
        sett.clear();
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(i<s.size()/2){
                if(sett.find(ch)==sett.end()) sett.insert(ch);
                continue;
            }
            if(sett.find(ch)!=sett.end())
            {
                cout<<ch<<" "<<((ch>'Z')? ch-'a'+1 : ch-'A'+27 )<<endl;
                sum+= (ch>'Z')? ch-'a'+1 : ch-'A'+27;
                break;
            }
        }
    }

    cout<<sum<<endl;
}