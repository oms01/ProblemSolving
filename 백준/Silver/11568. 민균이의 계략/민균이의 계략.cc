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

int arr[1001], dp[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    rep(i,0,n) cin>>arr[i];

    rep(i,0,n) rep(j,i+1,n){
        if(arr[i]<arr[j]) dp[j] = max(dp[j],dp[i]+1);
    }

    cout<<*max_element(all(dp))+1<<'\n';
}