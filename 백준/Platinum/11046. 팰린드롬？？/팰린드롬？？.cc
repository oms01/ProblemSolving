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
int input[5'000'001];
int A[5'000'001];
int len;
void manachers(){
    int r = 0, c = 0;
    rep(i,0,len){

        A[i] = (i<=r ? min(A[2*c-i],r-i) : 0);

        while(i-A[i]-1>=0 && i+A[i]+1<len && input[i-A[i]-1]==input[i+A[i]+1]){
            A[i]++;
        }

        if(r<i+A[i]){
            r = i + A[i];
            c = i;
        }
    }
}   
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    
    rep(i,0,n){
        input[2*i] = 0;
        cin>>input[2*i+1];
    }
    len = 2*n+1;

    manachers();

    int m; cin>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        cout<<(A[e+s-1]>=(e-s+1))<<'\n';
    }
}