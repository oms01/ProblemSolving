#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    
    stack<pii> s;
    vector<pii> v;
    rep(i,0,str.length()){
        if(str[i]==')'){
            if(!s.empty() && s.top().X=='('){
                v.push_back({s.top().Y,i});
                s.pop();
            }
        }
        else if(str[i]=='('){
            s.push({'(',i});
        }
    }
    
    set<string> ans;
    rep(i,1,1<<(int)v.size()){
        set<int> tmp;
        rep(I,0,v.size()){
            if(i&(1<<I)){
                tmp.insert(v[I].X);
                tmp.insert(v[I].Y);
            }
        }
        string s = "";
        rep(i,0,str.length()){
            if(tmp.count(i)) continue;
            s+=str[i];
        }
        ans.insert(s);

    }
    for(auto x: ans) cout<<x<<'\n';

}