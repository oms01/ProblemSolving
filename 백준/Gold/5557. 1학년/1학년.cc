#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

ll arr[101][21]; //i번째 인덱스까지 j로 만들수 있는 경우의수
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    arr[0][v[0]] = 1;

    rep(i,1,n){
        ll cur = v[i];
        rep(j,0,21){
            if(0<= j+cur && j+cur <= 20) arr[i][j+cur]+=arr[i-1][j];
            if(0<= j-cur && j-cur <= 20) arr[i][j-cur]+=arr[i-1][j];
        }
    }
    cout<<arr[n-2][v[n-1]]<<'\n';
}