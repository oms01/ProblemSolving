#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n;
set<char> s;
void func(string str, int idx){
    if(idx==-1){
        cout<<str<<'\n';
        return;
    }
    for(int i=0;i<str.length();i++){
        if(i==idx) cout<<'['<<str[i]<<']';
        else cout<<str[i];
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        vector<pair<char,int>> v;
        v.push_back({str[0],0});
        for(int i=1;i<str.length();i++){
            if(str[i]==' ') v.push_back({str[i+1],i+1});
        }
        int idx = -1;
        for(int i=0;i<v.size();i++){
            if(s.find(v[i].X)==s.end()){
                if('A'<=v[i].X && v[i].X<='Z'){
                    s.insert(v[i].X+32);
                }
                else if('a'<=v[i].X && v[i].X<='z'){
                    s.insert(v[i].X-32);
                }
                s.insert(v[i].X);
                idx = v[i].Y;
                break;
            }
        }
        if(idx!=-1){
            func(str,idx);
            continue;
        }
        bool flag = 0;
        for(int i=0;i<str.length();i++){
            if(str[i]!=' ' && s.find(str[i])==s.end() && !flag){
                if('A'<=str[i]&&str[i]<='Z'){
                    s.insert(str[i]+32);
                }
                else if('a'<=str[i] && str[i]<='z'){
                    s.insert(str[i]-32);
                }
                flag = 1;
                s.insert(str[i]);
                cout<<'['<<str[i]<<']';
            }
            else{
                cout<<str[i];
            }
        }
        cout<<'\n';

    }

}