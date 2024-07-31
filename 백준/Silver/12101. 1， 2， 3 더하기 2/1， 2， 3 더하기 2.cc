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

vector<vector<int>> ans;
int n,m; 
void f(int cur, vector<int> path){
    if(cur>=n){
        if(cur==n) ans.push_back(path);
        return;
    }

    for(int i=1;i<=3;i++){
        path.push_back(i);
        f(cur+i, path);
        path.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<int> tmp;
    f(0,tmp);
    sort(all(ans));
    if(ans.size() < m){
        cout<<-1<<'\n';
        return 0;
    }

    cout<<ans[m-1][0];
    for(int i=1;i<ans[m-1].size();i++){
        cout<<"+"<<ans[m-1][i];
    }
    cout<<'\n';
}