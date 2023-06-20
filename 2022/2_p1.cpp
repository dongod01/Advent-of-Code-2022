#include <iostream>
#include <climits>
#include<string>
#include<map>
using namespace std;

int main(){
    int score=0;
    string s;
    map<pair<char,char>,int> sc;
    sc[{'A','X'}]=3;
    sc[{'A','Y'}]=6;
    sc[{'A','Z'}]=0;
    sc[{'B','X'}]=0;
    sc[{'B','Y'}]=3;
    sc[{'B','Z'}]=6;
    sc[{'C','X'}]=6;
    sc[{'C','Y'}]=0;
    sc[{'C','Z'}]=3;

    while(getline(cin,s)){
        score+=s[2]-'W' + sc[{s[0],s[2]}];
    }

    cout<<score<<endl;
}