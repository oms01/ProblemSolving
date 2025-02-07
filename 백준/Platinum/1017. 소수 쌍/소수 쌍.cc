#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

const int MX = 2'001;
vector<int> LL[MX];
int RR[MX];
bool vis[MX];

bool state[MX+1];
void sieve(){
    memset(state,1,sizeof(state));
    state[0] = state[1] = 0;
    for(int i=2;i*i<=MX;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=MX;j+=i){
            state[j] = 0;
        }
    }
}


bool dfs(int x){
    for(auto nxt : LL[x]){
        if(vis[nxt]) continue;

        vis[nxt] = 1;
        if(RR[nxt]==-1 || dfs(RR[nxt])){
            RR[nxt] = x;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    sieve();

    int n; cin>>n;
    vector<int> a,b;

    bool tmp = 0;
    rep(i,0,n){
        int x; cin>>x;
        if(i==0){
            a.push_back(x);
            if(x%2) tmp = 1;
        }
        else{
            if(tmp){
                if(x%2) a.push_back(x);
                else b.push_back(x);
            }
            else{
                if(x%2) b.push_back(x);
                else a.push_back(x);
            }
        }
    }

    if(a.size()!=b.size()){
        cout<<-1<<'\n';
        return 0;
    }

    rep(i,0,a.size()) rep(j,0,b.size()){
        if(state[a[i]+b[j]]){
            LL[i].push_back(j);
        }
    }

    set<int> ans;
    for(auto nxt : LL[0]){
        memset(RR,-1,sizeof(RR));
        
        int tmp = nxt;
        RR[nxt] = 0;
        int cnt = 1;
        for(int i=1;i<a.size();i++){
            memset(vis,0,sizeof(vis));
            vis[nxt] = 1;
            cnt+=dfs(i);
        }
        // cout<<cnt<<'\n';
        if(cnt==n/2){
            ans.insert(b[nxt]);
        }

    }


    if(ans.empty()){
        cout<<-1<<'\n';
    }
    else{
        for(auto x: ans) cout<<x<<' '; cout<<'\n';
    }


}