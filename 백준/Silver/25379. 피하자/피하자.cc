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
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n){
        cin>>v[i]; v[i]%=2;
    }
    int idx=0;
    ll s1=0,s2=0;
    rep(i,0,n){
        if(v[i]) s1+=(i-idx++);
    }
    idx=0;
    rep(i,0,n){
        if(!v[i]) s2+=(i-idx++);
    }
    cout<<min(s1,s2);

}