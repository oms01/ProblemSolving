#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<ll,ll>> v(n);
    ll sum = 0;
    rep(i,0,n){
        cin>>v[i].X>>v[i].Y;
        sum+=v[i].Y;
    }
    sort(v.begin(),v.end());

    ll tmp = 0;
    rep(i,0,n){
        tmp += v[i].Y;
        if(tmp >= (sum+1)/2){
            cout<<v[i].X<<'\n';
            return 0;
        }
    }
}
