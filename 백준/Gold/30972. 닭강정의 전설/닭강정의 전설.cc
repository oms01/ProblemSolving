#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 5001;
int arr[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    REP(i,1,n) REP(j,1,n){
        cin>>arr[i][j];
        arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
    }

    int m; cin>>m;
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int b = arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
        int a = arr[x2-1][y2-1] - arr[x2-1][y1] - arr[x1][y2-1] + arr[x1][y1];
        cout<<a+a-b<<'\n';
    }
    
}
