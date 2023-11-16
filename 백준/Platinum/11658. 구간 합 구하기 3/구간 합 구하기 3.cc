#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
ll node[1111][1111];
ll tree[1111][1111];
void update(ll i, ll j, ll diff){
    for(int r=i;r<=n;r+=(r&-r)){
        for(int c=j;c<=n;c+=(c&-c)){
            tree[r][c]+=diff;
        }
    }
}
ll query(ll i, ll j){
    ll sum = 0;
    for(int r=i;r>0;r-=(r&-r)){
        for(int c=j;c>0;c-=(c&-c)){
            sum+=tree[r][c];
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>node[i][j];
            update(i,j,node[i][j]);
        }
    }
    while(m--){
        ll a,x1,y1,x2,y2,val;
        cin>>a;
        if(a==0){ //갱신
            cin>>x1>>y1>>val;
            update(x1,y1,val - node[x1][y1]);
            node[x1][y1] = val;
        }
        else{ //계산
            cin>>x1>>y1>>x2>>y2;
            cout<<query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1)<<'\n';
        }
    }
}