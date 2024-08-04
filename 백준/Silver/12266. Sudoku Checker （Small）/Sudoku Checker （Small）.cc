#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

/*----------------------*/
int n; 
bool col(vector<vector<int>> v){
    rep(i,0,n){
        vector<int> cnt(10,0);
        rep(j,0,n){
            if(v[i][j]<=0 || v[i][j]>10 || cnt[v[i][j]]) return 0;
            cnt[v[i][j]]++;
        }
    }
    return 1;
}
bool row(vector<vector<int>> v){
    rep(i,0,n){
        vector<int> cnt(10,0);
        rep(j,0,n){
            if(v[j][i]<=0 || v[j][i]>10 || cnt[v[j][i]] ) return 0;
            cnt[v[j][i]]++;
        }
    }
    return 1;
}
bool square(vector<vector<int>> v){
    for(int i=0;i<n;i+=3){
        for(int j=0;j<n;j+=3){
            vector<int> cnt(10,0);
            rep(x,0,3) rep(y,0,3){
                if(v[i+x][i+y]<=0 || v[i+x][i+y]>10 || cnt[v[i+x][i+y]]) return 0;
                cnt[v[i+x][i+y]]++;
            }
        }
    }
    return 1;
}
bool chk(vector<vector<int>> v){
    return (row(v) && col(v) && square(v));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        n*=n;
        vector<vector<int>> v(n,vector<int>(n));
        rep(i,0,n) rep(j,0,n) cin>>v[i][j];

        cout<<"Case #"<<i<<": ";
        if(chk(v)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}