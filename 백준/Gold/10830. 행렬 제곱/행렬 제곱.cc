#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

ll n,m;
map<ll,vector<vector<int>>> ma;
vector<vector<int>> cal(ll a, ll b){
    vector<vector<int>> ret(n,vector<int>(n));
    vector<vector<int>> x = ma[a];
    vector<vector<int>> y = ma[b];
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                ret[i][j]+=x[i][k]*y[k][j];
            }
            ret[i][j]%=1000;
        }
    }
    // cout<<a+b<<'\n';
    ma[a+b] = ret;
    return ret;
}
vector<vector<int>> func(ll t){
    auto iter = ma.find(t);
    if(iter!=ma.end()){
        return iter->second;
    }
    auto ret = func(t/2);
    cal(t/2,t/2);
    if(t%2){
        return cal(t-1,1);
    }
    else{
        return ret;
    }


}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,0,n) rep(j,0,n) cin>>a[i][j];

    rep(i,0,n) rep(j,0,n) a[i][j]%=1000;
    ma[1] = a;

    func(m);
    auto ans = ma[m];
    rep(i,0,n){
        rep(j,0,n){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

}