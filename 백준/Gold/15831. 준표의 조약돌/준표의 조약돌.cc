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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,b,w; cin>>n>>b>>w;
    string str; cin>>str;

    int s=0,e=0;
    int cnt[2] = {0,0}; //b,w
    cnt[str[0]=='W']++;

    int ans = 0;
    while(e<n){
        if(cnt[0]<=b && cnt[1]>=w){
            ans = max(ans,e-s+1);
        }

        if(cnt[0]>b){
            cnt[str[s++]=='W']--;
        }
        else{
            cnt[str[++e]=='W']++;
        }

    }
    cout<<ans<<'\n';


}