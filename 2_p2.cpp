#include <iostream>
#include <climits>
#include<string>
#include<map>
using namespace std;

int main(){
    int score=0;
    string s;

    while(getline(cin,s)){
        score+=3*(s[2]-'X') + (s[0]-'A'+3+s[2]-'Y')%3 + 1;
        // cout<<s[2]<<" "<<score<<endl;
    }

    cout<<score<<endl;

}
//    X   Y   Z
// X  Z   X   Y
// Y  X   Y   Z
// Z  Y   Z   X