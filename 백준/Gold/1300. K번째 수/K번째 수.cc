#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


ll n,k;

ll cnt(ll val){
    ll ret=0;
    rep(i,1,n+1){
        ret+=min(val/i,n);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    ll st=1, en=n*n;
    while(st<=en){
        ll mid = (st+en)/2;

        if(cnt(mid)>=k){
            en=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    cout<<st<<'\n';
}