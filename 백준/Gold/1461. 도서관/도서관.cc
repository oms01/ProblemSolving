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
    int n,m; cin>>n>>m;
    vector<int> a,b;
    rep(i,0,n){
        int val; cin>>val;
        val>0 ? a.push_back(val) : b.push_back(val);
    }
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    int ans = 0;
    int mx = 0;
    for(int i=0;i<a.size();i+=m){
        ans+=abs(a[i]);
        mx = max(mx,abs(a[i]));
    }
    for(int i=0;i<b.size();i+=m){
        ans+=abs(b[i]);
        mx = max(mx,abs(b[i]));
    }
    cout<<2*ans-mx<<'\n';
}
