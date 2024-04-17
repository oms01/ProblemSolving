#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll sum = 0;
    ll cnt = 0;
    rep(i,0,n){
        int val; cin>>val;
        sum+=val;
        cnt+=val/2;
    }
    cout<<((sum%3 || cnt<sum/3) ? "NO\n": "YES\n" );
}
