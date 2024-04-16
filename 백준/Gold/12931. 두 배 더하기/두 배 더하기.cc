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


bool chk(vector<int> v){
    bool ret = 0;
    rep(i,0,v.size()) ret+=(v[i]!=0);
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    int ans = 0;
    while(chk(v)){
        
        bool tmp = 0;
        for(int i=0;i<n;i++){
            tmp+=v[i]%2;
        }
        if(tmp==0){
            for(int i=0;i<n;i++){
                v[i]/=2;
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(v[i]%2){
                    v[i]--;
                    break;
                } 
            }
        }
        ans++;
    }
    cout<<ans<<'\n';

}
