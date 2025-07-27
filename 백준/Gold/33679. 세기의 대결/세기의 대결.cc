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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int lissz(vector<int> v){
    vector<int> dp(v.size(),0);
    int cnt = 0;
    vector<int> tmp;
    tmp.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        if(tmp.back() < v[i]){
            tmp.push_back(v[i]);
            dp[i] = ++cnt;
        }
        else{
            int idx = lower_bound(all(tmp),v[i])-tmp.begin();
            tmp[idx] = v[i];
            dp[i] = idx;
        }
    }
    return *max_element(all(dp));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<int> a(n), b(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];

    int A = 0;
    rep(i,0,n){
        vector<int> tmp;
        rep(j,i,i+n){
            tmp.push_back(a[j%n]);
        }
        A = max(A, lissz(tmp));
    }
    int B = 0;
    rep(i,0,n){
        vector<int> tmp;
        rep(j,i,i+n){
            tmp.push_back(b[j%n]);
        }
        B = max(B, lissz(tmp));
    }

    if(A<B){
        cout<<"HG Win!\n";
    }
    else if(A>B){
        cout<<"YJ Win!\n";
    }
    else{
        cout<<"Both Win!\n";
    }
    
    
}