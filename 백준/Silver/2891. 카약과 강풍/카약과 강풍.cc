#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s,r;
    cin>>n>>s>>r;
    vector<int> v(n+2);
    rep(i,0,s){
        int val; cin>>val;
        v[val]--;
    }
    rep(i,0,r){
        int val; cin>>val;
        v[val]++;
        if(v[val]==0) s--;
    }

    rep(i,1,n+1){
        if(v[i]>=0) continue;
        
        if(v[i-1]==1){
            s--;
            v[i]=v[i-1]=0;
        }
        else if(v[i+1]==1){
            s--;
            v[i]=v[i+1]=0;
        }
    }

    cout<<s<<'\n';
}