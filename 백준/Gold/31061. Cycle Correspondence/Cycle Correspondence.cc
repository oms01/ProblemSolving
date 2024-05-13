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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
vector<int> idx;
int n,k; 
int func(vector<int> v){
    map<int,int> m; //숫자 : 빈도
    rep(i,0,v.size()){
        if(idx[v[i]]==-2e9) continue;
        int x = (i+1-idx[v[i]]+k)%k;
        m[x]++;
    }
    int mx=0;
    for(auto i=m.begin();i!=m.end();i++) mx = max(mx, i->Y);
    return mx;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    idx.resize(n+1,-2e9);
    vector<bool> cnt(n+1,0); //i번 노드의 사용여부
    rep(i,0,k){
        int x; cin>>x;
        idx[x] = i+1;
        cnt[x]=1;
    }

    vector<int> tmp(k);
    rep(i,0,k){
        cin>>tmp[i];
        cnt[tmp[i]]=1;
    }
    int c = 0; //등장하지 않은 노드 수
    rep(i,1,n+1) c+=1-cnt[i];


    //겹치는 노드의 개수
    int x = func(tmp);
    reverse(all(tmp));
    x = max(x,func(tmp));
    
    cout<<x+c<<'\n';

}