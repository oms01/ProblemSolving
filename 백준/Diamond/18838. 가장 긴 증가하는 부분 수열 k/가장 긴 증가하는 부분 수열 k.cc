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


template<typename NodeType, typename F_Merge>
struct SegTree { // 1-indexed
public:
    using A = NodeType;
    SegTree() : SegTree(0, A()) {}
    explicit SegTree(int n, const A& e) : n(n), lg(Log2(n)), sz(1 << lg), e(e), tree(sz << 1, e) {}
    void update(int i, const A& val) {
        tree[--i |= sz] = val;
        while (i >>= 1) tree[i] = M(tree[i << 1], tree[i << 1 | 1]);
    }
    A query(int l, int r) const {
        A L = e, R = e;
        for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) L = M(L, tree[l++]);
            if (~r & 1) R = M(tree[r--], R);
        }
        return M(L, R);
    }
private:
    const int n, lg, sz; const A e; vector<A> tree; F_Merge M;
    static int Log2(int n) { int ret = 0; while (n > 1 << ret) ret++; return ret; }
};

constexpr ll INF = ll(1e18) + 7;

void Add(ll& a, ll b) { a += b; if (a > INF) a = INF; }

struct Merge {
	pll operator() (pll a, pll b) const {
		if (a.first < b.first) swap(a, b);
		if (a.first == b.first) Add(a.second, b.second);
		return a;
	}
};
    
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,k; cin>>n>>k;
    vector<int> v(n+1,0);
    REP(i,1,n) cin>>v[i];

    SegTree<pll,Merge> seg(n,{0,0});
    vector<ll> lis(n+1), dp(n+1);
    for(int i=n;i>=1;i--){
        auto [a,b] = seg.query(v[i],n);
        lis[i] = a + 1;
        dp[i] = b + !b;
        seg.update(v[i],{lis[i],dp[i]});
    }

    int mx = seg.query(1,n).X; //lis 길이
    vector<vector<int>> idx(mx+1,vector<int>(0)); //길이별 시작 인덱스
    REP(i,1,n) idx[lis[i]].push_back(i);
    REP(i,1,mx){
        sort(all(idx[i]),[&](int a,int b){ return v[a]<v[b]; });
    }

    ll sum = 0;
    for(int j:idx[mx]) Add(sum,dp[j]);
    if(sum<k) return !(cout<<-1<<'\n');

    for(int i=mx, prv = 0; i; i--){
        for(int j:idx[i]){
            if(prv<j && v[prv]<v[j]){
                if(k>dp[j]) k-=dp[j];
                else{
                    cout<<v[prv=j]<<' ';
                    break;
                }
            }
        }
    }
    cout<<'\n';
}