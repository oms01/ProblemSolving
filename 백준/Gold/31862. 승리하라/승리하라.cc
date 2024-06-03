#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int score[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k; cin>>n>>m>>k; 
    vector<pii> v;
    rep(i,0,m){
        int a,b,t; cin>>a>>b>>t;
        if(t==0) v.push_back({a,b});
        if(t==1) score[a]++;
        if(t==2) score[b]++;
    }
    int ans = 0;
    rep(i,0,1<<v.size()){ //최대 2^20
        map<int,int> ma;
        int idx = i;
        int mx = 0;
        rep(j,0,v.size()){ // 최대 20
            int tmp = idx%2 ? v[j].X : v[j].Y;
            ma[tmp]++;
            if(tmp==k) continue;
            mx = max(mx, score[tmp] + ma[tmp]);
            idx/=2;
        }
        if(mx < score[k] + ma[k]) ans++;
    }
    cout<<ans<<'\n';

}