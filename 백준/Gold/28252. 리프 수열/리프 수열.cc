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

    int n; cin>>n;

    int cnt = 0;
    vector<int> tmp;

    vector<pii> ans;
    //초기 처리
    int x; cin>>x;
    if(n==1 && x>2) return !(cout<<-1<<'\n');
    if(n==1 && x==2) ans.push_back({1,2});
    rep(i,0,x) tmp.push_back(++cnt);
    

    rep(i,1,n){
        int x; cin>>x;
        if(tmp.size() < x) return !(cout<<-1<<'\n');

        vector<int> node;
        rep(j,0,x) node.push_back(++cnt);
        rep(j,0,tmp.size()){
            int ch = tmp[j];
            int pa = node[min((int)node.size()-1,j)];
            ans.push_back({ch,pa});
        }

        if(i==n-1){
            if(x>2) return !(cout<<-1<<'\n'); //마지막에 없어지는건 1개 또는 2개만
            if(x==1 && tmp.size()==1){ //루트의 자식이 하나인 경우
                return !(cout<<-1<<'\n');
            }
            if(x==2){
                ans.push_back({node[0],node[1]});
            }
        }

        tmp = node;
    }

    cout<<cnt<<'\n';
    for(auto[a,b]:ans) cout<<a<<' '<<b<<'\n';


}

