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
/*------------------------------*/

int parent[100'001];
int Find(int n){
    if(parent[n]==n) return n;
    return parent[n] = Find(parent[n]);
}
void Union(int a, int b){
    a = Find(a); b = Find(b);
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,0,100'001) parent[i] = i;

    int n,m; cin>>n>>m;
    vector<tuple<int,int,int>> v;
    rep(i,0,n){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        v.push_back({x1,x2,i});
    }
    sort(all(v));

    int cur = get<1>(v[0]);
    rep(i,1,n){
        int a,b,c; tie(a,b,c) = v[i];
        if(a<=cur){
            Union(c,get<2>(v[i-1]));
            // cur = max(cur,b);
        }
        cur = max(cur,b);
        // else cur = b;
    }


    rep(i,0,m){
        int st,en; cin>>st>>en;
        cout<<(Find(st-1)==Find(en-1))<<'\n';
    }
}