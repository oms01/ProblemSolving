#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v;
    int tmp=1;
    rep(i,0,21){
        v.push_back(tmp);
        tmp*=2;
    }
    int sz = 0;
    while(n > v[sz]) sz++;

    cout<<v[sz]<<' ';
    int ans=0;
    if(n==v[sz]){
        cout<<ans<<' ';
        return 0;    
    }
    int i = sz;
    // cout<<'\n';
    while(n){
        while(n<v[i]){
            i--;
            ans++;
        }
        // cout<<v[i]<<" "<<n<<'\n';
        n%=v[i];
        // ans++;

    }
    cout<<ans<<'\n';
}