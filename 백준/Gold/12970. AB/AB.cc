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
    int n,k; cin>>n>>k;
    if((n/2)*(n-(n/2))<k){
        cout<<-1<<'\n';
        return 0;
    }

    string ans = "";
    rep(i,0,n) ans+='B';

    if(n>k){
        ans[n-k-1] = 'A';
        cout<<ans<<'\n';
        return 0;
    }

    vector<int> v;
    int mx = n%2 ? n/2+1 : n/2;
    while(mx>0){
        while(k-mx >= 0){
            k-=mx;
            v.push_back(mx);
        }
        mx--;
    }
    reverse(v.begin(),v.end());
    int cnt=0;
    rep(i,0,v.size()){
        ans[n-1-v[i]-cnt] = 'A';
        cnt++;
    }
    cout<<ans<<'\n';


}