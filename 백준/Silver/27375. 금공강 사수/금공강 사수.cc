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
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k; //수업, 학점
    vector<tiii> v;
    rep(i,0,n){
        int a,b,c; cin>>a>>b>>c;
        if(a==5) continue;
        v.push_back({a,b,c});
    }
    sort(all(v));
    
    int cnt = 0;
    n = v.size();
    for(int i=0;i<(1<<n);i++){
        vector<tiii> cur;
        int idx = i;
        for(int j=0;j<n;j++){
            if(idx%2) cur.push_back(v[j]);
            idx/=2;
        }

        int sum = 0;
        for(auto [a,b,c] : cur) sum += c-b+1;
        if(sum!=k) continue;
    
        bool flag = 1;
        for(int i=1;i<cur.size();i++){
            auto [a,b,c] = cur[i-1];
            auto [x,y,z] = cur[i];
            if(a==x && y<=c) flag = 0;
        }

        if(flag){
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}
