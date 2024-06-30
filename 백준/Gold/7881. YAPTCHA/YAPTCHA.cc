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

int prime[4'000'001];
int s[4'000'001];

int sn(int n){
    int t = 3*n+7;
    return (prime[t]==0);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    rep(i,2,4'000'001){
        if(prime[i]==0){
            for(int j=i+i;j<4'000'001;j+=i){
                prime[j]=1;
            }
        }
    }

    rep(i,2,1'000'001){
        s[i] = s[i-1] + (prime[3*i+7]==0);
    }

    while(n--){
        int k; cin>>k;
        cout<<s[k]<<'\n';
    }




}