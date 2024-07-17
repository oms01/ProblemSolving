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
int f(tuple<int,int,int,int> a, tuple<int,int,int,int> b){
    int ax,aa,ab,ac;
    tie(aa,ab,ac,ax) = a;
    int bx,ba,bb,bc;
    tie(ba,bb,bc,bx) = b;
    if(aa==ba && ab==bb && ac==bc){
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<tuple<int,int,int,int>> v(n);
    rep(i,0,n){
        int x,a,b,c; cin>>x>>a>>b>>c;
        v[i] = {a,b,c,x==m};
    }

    sort(rall(v));
    int idx = -1;
    rep(i,0,n){
        if(get<3>(v[i])==1){
            idx = i;
            break;
        }
    }
    cout<<idx+1<<'\n';
    // int cnt = 0;
    // rep(i,0,n){
    //     cnt+=f(v[i],v[m]);
    //     if(get<3>(v[i])==1){
    //         cout<<i<<" "<<cnt<<'\n';
    //         cout<<i-cnt<<'\n';
    //         return 0;
    //     }
    // }

}
