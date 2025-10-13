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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/
string f(string cur){
    vector<int> cnt(10,0);
    for(auto x: cur) cnt[x-'0']++;
    string ret = "";
    rep(i,0,10){
        if(cnt[i]>0) ret += to_string(cnt[i]) + to_string(i);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string st, target; cin>>st>>target;

    set<string> s;
    REP(i,0,100){
        if(st==target){
            return !(cout<<s.size()+1<<'\n');
        }
        s.insert(st);
        st = f(st);
    }
    cout<<"Does not appear\n";

}
