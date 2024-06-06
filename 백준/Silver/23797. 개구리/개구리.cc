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
    string str; cin>>str;
    int ans = 0;
    int p=0, k=0; //앞으로 p,k를 외칠 개구리 수
    rep(i,0,str.length()){
        if(str[i]=='P'){
            k++;
            if(p) p--;
        }
        else{
            p++;
            if(k) k--;
        }
        ans = max({ans,p,k});
    }
    cout<<ans<<'\n';
}