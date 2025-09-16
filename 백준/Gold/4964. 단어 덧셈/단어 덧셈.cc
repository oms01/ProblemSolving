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
int ma[30];
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
        if(i==0 && leading[vec[idx]-'A']) continue;
        vis[i] = 1;
        ma[vec[idx]-'A'] = i;
        f(idx+1, sum + w[vec[idx]-'A']*i);
        vis[i] = 0;
        ma[vec[idx]-'A'] = -1;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0) break;
        vec.clear(); cnt = 0;
        for(int i=0;i<30;i++) ma[i] = leading[i] = w[i] = 0;
        rep(i,0,n){
            string s; cin>>s;
            if(s.size()!=1) leading[s[0]-'A'] = 1;
            ll tmp = (i==n-1 ? -1 : 1);
            for(int j=s.size()-1;j>=0;j--){
                w[s[j]-'A']+= tmp;
                ma[s[j]-'A'] = 1;
                tmp*=10;
            }
        }
        for(int i=0;i<30;i++) if(ma[i]) vec.push_back(i+'A');
        f(0,0);
        cout<<cnt<<'\n';
    }
}