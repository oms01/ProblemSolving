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
/*----------------------*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,l1,l2,s1,s2;
        cin>>n>>l1>>l2>>s1>>s2;
        vector<int> d1(n),p1(n);
        rep(i,0,n-1) cin>>p1[i];
        rep(i,0,n-1) cin>>d1[i];

        vector<int> d2(n),p2(n);
        rep(i,0,n-1) cin>>p2[i];
        rep(i,0,n-1) cin>>d2[i];

        vector<int> dist1(n+1), dist2(n+1);
        dist1[0] = l1;
        dist2[0] = l2;
        rep(i,1,n){
            dist1[i] = min(dist1[i-1] + d1[i-1], dist2[i-1] + p2[i-1]);
            dist2[i] = min(dist2[i-1] + d2[i-1], dist1[i-1] + p1[i-1]);
        }
        cout<<min(dist1[n-1]+s1, dist2[n-1]+s2)<<'\n';
    }
}