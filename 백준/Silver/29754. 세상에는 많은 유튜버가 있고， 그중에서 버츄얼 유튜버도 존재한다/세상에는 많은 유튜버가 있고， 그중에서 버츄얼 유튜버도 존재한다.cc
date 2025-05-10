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
int conv(string s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,4));
    return h*60+m;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    map<string,map<int,pii>> ma; //이름, 주차, {시간,횟수}
    rep(i,0,n){
        string name, st, en; int day;
        cin>>name>>day>>st>>en;
        ma[name][(day-1)/7].X+=conv(en)-conv(st);
        ma[name][(day-1)/7].Y++;
    }

    set<string> ans;
    for(auto [name,weeks]: ma){
        int cnt = m/7;
        for(auto [week,p]: weeks){
            if(p.Y >= 5 && p.X >= 3600){
                cnt--;
            }
        }
        if(!cnt){
            ans.insert(name);

        }
    
    }

    if(ans.empty()){
        return !(cout<<-1<<'\n');
    }
    for(auto x: ans) cout<<x<<'\n';
    
}