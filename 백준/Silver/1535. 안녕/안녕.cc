#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int hp[21];
int val[21];
int cache[101][101];
int n;
int pack(int a,int b){
    if(b==n) return 0;
    int& ret = cache[a][b];
    if(ret!=-1) return ret;
    ret = pack(a,b+1);
    if(a>hp[b]){
        ret = max(ret, pack(a-hp[b], b+1) + val[b]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    rep(0,n) cin>>hp[i];
    rep(0,n) cin>>val[i];

    cout<<pack(100, 0)<<'\n';
}