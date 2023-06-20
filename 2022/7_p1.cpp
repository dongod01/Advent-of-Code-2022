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

class Directory;

class File{
    string name;
    ll size;
    Directory* parent;
    public:
        File(string s="",ll sz=0,Directory* pr=NULL){
            this->name = s;
            this->size = sz;
            this->parent = pr;
        }
        string getname(){
            return name;
        }
        ll getsize(){
            return size;
        }

};

class Directory{
    string name;
    ll size;
    bool changed;
    Directory* parent;
    map<string,Directory*> mp;
    map<string,File*> mpf;

    public:
        Directory(string s="",Directory* pr = NULL){
            this->name = s;
            this->parent = pr;
            //Assignments
            this->size=0;
            this->changed = false;
        }

        void addDir(string D){
            Directory* _new = new Directory(D,this);
            this->mp[D] = _new;

            changed = true;
        }

        void addFile(string F,ll sz){
            File* _new = new File(F,sz,this);
            this->mpf[F] = _new;
            changed = true;
        }

        ll calcSize(){
            if(!changed) return this->size;
            ll sz=0;
            for(auto fp: mpf){
                sz+=fp.second->getsize();
            }

            for(auto dp: mp){
                sz+=dp.second->calcSize();
            }
            changed = false;
            return this->size=sz;
        }

        string getname(){
            return name;
        }

        Directory* redirect(string s){
            return mp[s];
        }

        File* filedetails(string s){
            return mpf[s];
        }

        Directory* parent_addr(){
            return parent;
        }

        ll count_num_dir();
};

// Doesnt need to be this complex, just practicing class definitions



ll Directory::count_num_dir(){
    ll ans= (this->calcSize() <= 100000)? this->calcSize() : 0;
    for(auto dp: this->mp){
        ans+=dp.second->count_num_dir();
    }
    return ans;
};


int main(){
    int cnt=0;
    string s;
    Directory *home,*cur_dir;
    cur_dir = home = new Directory("/");
    while(getline(cin,s)){
        if(s.substr(0,4)=="$ cd"){
            // cur_dir = new Directory(s.substr(5,s.size()-5));
            if(s=="$ cd /"){
                cur_dir = home;
                continue;
            }
            if(s=="$ cd .."){
                cur_dir = cur_dir->parent_addr();
                continue;
            }

            if(s=="$ cd /"){
                cur_dir = home;
                continue;
            }

            cur_dir = cur_dir->redirect(s.substr(5,s.size()-5));
        }
        else if(s.substr(0,4)=="$ ls"){

        }
        else if(s.substr(0,4)=="dir "){
            cur_dir->addDir(s.substr(4,s.size()-4));
        }
        else if(s[0]>='0' && s[0]<='9'){
            int sp_index=0;
            for(;sp_index<s.size();sp_index++)
                if(s[sp_index]==' ') break;
            cur_dir->addFile(s.substr(sp_index+1,s.size()-sp_index-1), 
                                            stoll(s.substr(0,sp_index))  );
            
        }
        
    }
    // ;
    cout<<"Size of entire space: "<<home->calcSize()<<"Answer: "<<home->count_num_dir();

}