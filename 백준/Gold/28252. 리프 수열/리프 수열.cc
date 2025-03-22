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

    vector<pii> ans;

    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    reverse(all(v));
    if(v[0]>2) return !(cout<<-1<<'\n');

    if(n==1 && v[0]==2){
        return !(cout<<2<<'\n'<<1<<' '<<2<<'\n');
    }
    
    if(v[0]==1 && v[1]==1) return !(cout<<-1<<'\n');
    
    int cnt = 0;
    //초기 처리
    vector<int> tmp;
    rep(i,0,v[0]) tmp.push_back(++cnt);

    if(v[0]==2){
        ans.push_back({tmp[0],tmp[1]});
    }


    rep(i,1,n){
        if(tmp.size() > v[i]) return !(cout<<-1<<'\n');

        vector<int> node;
        rep(j,0,v[i]) node.push_back(++cnt);
        rep(j,0,node.size()){
            int ch = node[j];
            int pa = tmp[min((int)tmp.size()-1,j)];
            ans.push_back({ch,pa});
        }

        tmp = node;

    }

    cout<<cnt<<'\n';
    for(auto[a,b]:ans) cout<<a<<' '<<b<<'\n';


}

