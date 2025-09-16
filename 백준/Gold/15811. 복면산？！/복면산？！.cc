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

int vis[10];
int leading[30];
int w[30];
vector<char> vec;
int cnt;
void f(int idx, int sum){
    if(idx==vec.size()){
        cnt += sum==0;
        return;
    }
    for(int i=0;i<10;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        f(idx+1, sum + w[vec[idx]-'A']*i);
        vis[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> chk(30,0);
    rep(i,0,3){
        string s; cin>>s;
        ll tmp = (i==2 ? -1 : 1);
        for(int j=s.size()-1;j>=0;j--){
            w[s[j]-'A']+= tmp;
            chk[s[j]-'A'] = 1;
            tmp*=10;
        }
    }
    for(int i=0;i<30;i++) if(chk[i]) vec.push_back(i+'A');
    f(0,0);
    cout<<(cnt ? "YES\n" : "NO\n")<<'\n';
}