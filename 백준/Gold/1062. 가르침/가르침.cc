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

int n,k; 
int words[50];
int chk;
int ans = -1;
void f(int cnt, int idx){
    if(cnt==k){
        int tmp = 0;
        for(int i=0;i<n;i++){
            tmp += (words[i]&chk)==words[i];
        }
        ans = max(ans, tmp);
        return;
    }
    
    for(int i=idx;i<26;i++){
        if(chk&(1<<i)) continue;
        chk |= 1<<i;
        f(cnt+1, i+1);
        chk ^= 1<<i;
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i,0,n){
        string s; cin>>s;
        int tmp = 0;
        for(auto x: s){
            tmp |= 1<<(x-'a');
        }
        words[i] = tmp;
    }
    if(k<5){
        return !(cout<<0<<'\n');
    }

    string s = "acint";
    for(auto x: s) chk|= (1<<x-'a');
    k-=5;
    

    f(0,0);
    cout<<ans<<'\n';

}