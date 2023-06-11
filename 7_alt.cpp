#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll=long long;

ll reqd_space,min_val;

// class Directory;

// class File{
//     string name;
//     ll size;
//     Directory* parent;
//     public:
//         File(string s="",ll sz=0,Directory* pr=NULL){
//             this->name = s;
//             this->size = sz;
//             this->parent = pr;
//         }
//         string getname(){
//             return name;
//         }
//         ll getsize(){
//             return size;
//         }

// };

// class Directory{
//     string name;
//     ll size;
//     bool changed;
//     Directory* parent;
//     map<string,Directory*> mp;
//     map<string,File*> mpf;

//     public:
//         Directory(string s="",Directory* pr = NULL){
//             this->name = s;
//             this->parent = pr;
//             //Assignments
//             this->size=0;
//             this->changed = false;
//         }

//         void addDir(string D){
//             Directory* _new = new Directory(D,this);
//             this->mp[D] = _new;

//             changed = true;
//         }

//         void addFile(string F,ll sz){
//             File* _new = new File(F,sz,this);
//             this->mpf[F] = _new;
//             changed = true;
//         }

//         ll calcSize(){
//             if(!changed) return this->size;
//             ll sz=0;
//             for(auto fp: mpf){
//                 sz+=fp.second->getsize();
//             }

//             for(auto dp: mp){
//                 sz+=dp.second->calcSize();
//             }
//             changed = false;
//             return this->size=sz;
//         }

//         string getname(){
//             return name;
//         }

//         Directory* redirect(string s){
//             return mp[s];
//         }

//         File* filedetails(string s){
//             return mpf[s];
//         }

//         Directory* parent_addr(){
//             return parent;
//         }

//         ll count_num_dir();
//         void min_size();
// };

// // Doesnt need to be this complex, just practicing class definitions

// //Part1
// ll Directory::count_num_dir(){
//     ll ans= (this->calcSize() <= 100000)? this->calcSize() : 0;
//     for(auto dp: this->mp){
//         ans+=dp.second->count_num_dir();
//     }
//     return ans;
// };

// void Directory::min_size(){
//     if (this->calcSize()>= reqd_space) min_val = min(min_val, this->calcSize());
//     for(auto dp: this->mp){
//         dp.second->min_size();
//     }
// }


int main(){
    int cnt=0;
    string s;
    stack<string> st;
    map<string,ll> strsize;

    st.push("/");

    while(getline(cin,s)){
        if(s.substr(0,4)=="$ cd"){
            // cur_dir = new Directory(s.substr(5,s.size()-5));
            if(s=="$ cd /"){
                while(st.top()!="/") st.pop();
                continue;
            }
            if(s=="$ cd .."){
                if(st.top()!="/") st.pop();
                continue;
            }

            st.push(st.top() + "_"+s.substr(5,s.size()-5));
        }
        else if(s[0]>='0' && s[0]<='9'){
            int sp_index=0;
            for(;sp_index<s.size();sp_index++)
                if(s[sp_index]==' ') break;
            // cur_dir->addFile(s.substr(sp_index+1,s.size()-sp_index-1), 
                                            // stoll(s.substr(0,sp_index))  );
            strsize[st.top()]+= stoll(s.substr(0,sp_index));
        }
        
    }
    reqd_space = 268565;
    min_val = reqd_space + 40000000;
    for(auto elem: strsize){
        if(elem.second>=reqd_space) min_val = min(min_val,elem.second);
    }
    // home->min_size();
    cout<<"Reqd space is: "<<reqd_space<<"\n";
    cout<<"Answer: "<<min_val;

}