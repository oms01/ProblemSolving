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
ll cal(string str){
    ll ret = 1;
    rep(i,0,str.length()){
        if(i==0 && str[i]=='0') continue;
        ret*= str[i]-'0';
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str; cin>>str;
    ll ans = cal(str);

    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='9') continue;

        if(i==0 && str[i]!='9') break;
        str[i]='9';
        int idx = i-1;
        while(idx>=0 && str[idx]=='0'){
            str[idx--] = '9';
        }

        if(idx>=0 && str[idx]!='0'){
            str[idx]--;
        }
        ans = max(ans, cal(str));
    }
    cout<<ans<<'\n';
}