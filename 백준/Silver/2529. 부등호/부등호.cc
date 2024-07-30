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
vector<string> ans;
vector<char> v;
int vis[11];
int n; 
void f(int idx, string path){
    if(idx==n){
        ans.push_back(path);
        return;
    }

    for(int i=0;i<10;i++){
        if(vis[i]) continue;
        if((v[idx] == '<' && path.back()-'0' < i) || v[idx] == '>' && path.back()-'0' > i){
            vis[i] = 1;
            f(idx+1, path+(char)(i+'0'));
            vis[i] = 0;
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    v.resize(n);
    rep(i,0,n) cin>>v[i];
    
    rep(i,0,10){
        vis[i] = 1;
        f(0,to_string(i));
        vis[i] = 0;
    }
    sort(all(ans));
    cout<<ans[ans.size()-1]<<'\n';
    cout<<ans[0]<<'\n';

}