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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int cnt = 0;
    rep(i,0,n){
        string s; cin>>s;
        bool flag = 0;
        for(auto x: s){
            if(x=='/' || x=='\\'){
                flag=1-flag;
                cnt++;
            }
            else if(flag){
                cnt+=2;
            }

        }
    }
    cout<<cnt/2<<'\n';

}