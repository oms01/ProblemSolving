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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

bool chk(char c){
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    string str; cin>>str;
    while(chk(str.back())){
        str.pop_back();
    }

    int cnt = 0;
    string ans = ""; ans+=str.back();
    for(int i=str.length()-2;i>=0 && ans.size()<m;i--){
        if(str[i]=='A'){
            ans += str[i];
            cnt++;
            continue;
        }
        if(cnt>=2){
            ans += str[i];
        }
    }

    reverse(all(ans));
    if(ans.size()!=m || cnt<2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n"<<ans<<'\n';
    }

}