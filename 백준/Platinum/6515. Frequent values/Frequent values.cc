#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
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
int cur;
int board[MX];


void mi(int x){
    board[cnt[x]]--;
    if(cur==cnt[x] && !board[cnt[x]]) cur--;
    cnt[x]--;
    board[cnt[x]]++;
}

void pl(int x){
    if(board[cnt[x]]!=0) board[cnt[x]]--;
    cnt[x]++;
    board[cnt[x]]++;
    cur = max(cur, cnt[x]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0) return 0;
        fill(cnt,cnt+MX,0);
        fill(ans,ans+MX,0);
        fill(v,v+MX,0);
        fill(board,board+MX,0);
        cur = 0;
        int m; cin>>m;
        rep(i,1,n+1) cin>>v[i];
        rep(i,1,n+1) v[i]+=100'000;

        vector<tiii> q;
        rep(i,0,m){
            int s,e; cin>>s>>e;
            q.push_back({i,s,e});
        }
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
            ans[idx] = cur;
        }

        rep(i,0,m) cout<<ans[i]<<'\n';
    }
    
}