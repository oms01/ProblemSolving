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

int chk[101]; //선발한 선수
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;

    //점수, 참가번호
    vector<pair<double,int>> v;
    rep(i,0,m*n){
        int a; double b;
        cin>>a>>b;
        v.push_back({b,a});
    }

    sort(rall(v));

    double ans = 0;
    int cnt = 0;
    for(auto cur : v){
        if(chk[cur.Y]) continue;
        chk[cur.Y] = 1;
        ans += cur.X;
        if(++cnt==k) break;
    }

    cout<<fixed;
    cout.precision(1);
    cout<<(double)ans<<'\n';

}
