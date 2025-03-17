#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 10'000;
int n;
int arr[MX+1];
int vis[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v;
    for(int i=1;i<=2*MX;i*=2) v.push_back(i);
    
    for(int i=n;i>0;i--){
        if(arr[i]) continue;
        int target = *lower_bound(v.begin(),v.end(),i);
        // cout<<i<<' '<<target<<'\n';
        if(target==i){
            arr[i] = i;
            continue;
        }
        int j = target-i;
        arr[i] = j;
        arr[j] = i;
    }
    REP(i,1,n) cout<<arr[i]<<'\n';

}