#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


vector<int> v(500'001);
vector<int> tmp(500'001);
vector<int> ans;
void merge(int p, int q, int r){
    int i=p, j=q+1, t=1;
    while(i<=q && j<=r){
        if(v[i]<=v[j]){
            tmp[t++] = v[i++];
        }
        else{
            tmp[t++] = v[j++];
        }
    }
    while(i<=q){
        tmp[t++] = v[i++];
    }
    while(j<=r){
        tmp[t++] = v[j++];
    }
    i=p;t=1;
    while(i<=r){
        ans.push_back(tmp[t]);
        v[i++] = tmp[t++];
    }
}

void merge_sort(int st, int en){
    if(st<en){
        int mid = (st+en)/2;
        merge_sort(st,mid);
        merge_sort(mid+1,en);
        merge(st,mid,en);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    // v.resize(n);
    rep(i,1,n+1) cin>>v[i];
    ans.push_back(0);
    merge_sort(1,n);
    // rep(i,0,ans.size()) cout<<ans[i]<<' ';
    // cout<<'\n';

    if(ans.size() <= m) cout<<-1<<'\n';
    else cout<<ans[m]<<'\n';
}

