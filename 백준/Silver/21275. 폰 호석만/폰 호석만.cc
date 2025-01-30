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
ll conv(string a, int n){

    ll ret = 0;
    ll tmp = 1;
    reverse(all(a));
    for(auto x : a){
        ll cur = ('a'<=x&&x<='z' ? x-'a'+10 : x-'0');
        if(cur >= n) return -1;
        ret += tmp*cur;
        tmp*=n;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a,b; cin>>a>>b;
    vector<tuple<ll,ll,ll>> ans;
    for(int i=2;i<=36;i++){
        for(int j=2;j<=36;j++){
            if(i==j) continue;
            ll x = conv(a,i);
            ll y = conv(b,j);
            if(x==-1 || y==-1) continue;
            if(x==y){
                ans.push_back({x,i,j});
                // cout<<x<<' '<<i<<' '<<j<<'\n';
            }
        }
    }

    if(ans.size()>=2){
        cout<<"Multiple\n";
    }
    else if(ans.size()==0){
        cout<<"Impossible\n";
    }
    else{
        ll a,b,c;
        tie(a,b,c) = ans.back();
        cout<<a<<' '<<b<<' '<<c<<'\n';
    }
}