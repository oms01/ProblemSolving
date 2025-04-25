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
    int n,m; cin>>n>>m;
    vector<int> sum(m);
    vector<pair<char,vector<int>>> v(n);
    rep(i,0,n){
        char c; cin>>c;
        string s; cin>>s;
        vector<int> tmp;
        for(auto x: s){
            tmp.push_back(x-'0');
        }
        v[i] = {c,tmp};
        if(c=='R'){
            rep(i,0,m) sum[i]+=tmp[i];
        }
        else{
            rep(i,0,m) sum[i]-=tmp[i];
        }
    }

    int num = -1;
    int ans = 2e9;
    for(int i=0;i<n;i++){
        auto [side,vec] = v[i];
        vector<int> tmp(m);
        if(side=='R'){
            for(int j=0;j<m;j++){
                tmp[j] = sum[j] - vec[j];
            }
        }
        else{
            for(int j=0;j<m;j++){
                tmp[j] = sum[j] + vec[j];
            }
        }

        vector<int> sum(m,0);
        sum[0] = tmp[0];
        for(int j=1;j<m;j++){
            sum[j] = sum[j-1] + tmp[j];
        }
        int mx = -2e9;
        for(auto x: sum){
            mx = max(mx, abs(x));
        }

        if(ans > mx){
            num = i+1;
            ans = mx;
        }
    }
    cout<<num<<'\n'<<ans<<'\n';
}