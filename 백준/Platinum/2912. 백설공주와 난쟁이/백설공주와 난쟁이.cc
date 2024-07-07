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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const int MX = 1'000'001;
int cnt[MX], ans[MX], v[MX];
int mx[MX];

void mi(int x){
    cnt[x]--;
}
void pl(int x){
    cnt[x]++;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,c; cin>>n>>c;
    rep(i,1,n+1) cin>>v[i];

    int m; cin>>m;
    vector<tiii> q;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        q.push_back({i,s,e});
    }

    memset(ans,-1,sizeof(ans));
    int sqn = sqrt(n);
    sort(all(q),[&sqn](tiii a, tiii b){
        if(get<1>(a)/sqn!= get<1>(b)/sqn) return get<1>(a) < get<1>(b);
        return get<2>(a) < get<2>(b);
    });

    int l = 0, r = 0;

    rep(i,0,m){
        int idx,s,e;
        tie(idx,s,e) = q[i];
        while(l<s) mi(v[l++]);
        while(l>s) pl(v[--l]);
        while(r<e) pl(v[++r]);
        while(r>e) mi(v[r--]);
        
        rep(j,1,c+1){
            if(cnt[j]*2 > e-s+1){
                ans[idx] = j; break;
            }
        }
    }

    rep(i,0,m){
        if(ans[i]!=-1) cout<<"yes "<<ans[i]<<'\n';
        else cout<<"no\n";
    }
    
}