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

bool vis[501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    int zero=0;
    int one=0;
    int len = str.length();
    rep(i,0,len){
        str[i]=='1' ? one++ : zero++;
    }
    one/=2;
    zero/=2;

    rep(i,0,len){
        if(str[i]=='1'){
            vis[i] = 1;
            one--;
            if(!one) break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(str[i]=='0'){
            vis[i] = 1;
            zero--;
            if(!zero) break;
        }
    }
    // rep(i,0,len) cout<<vis[i];
    // cout<<'\n';

    rep(i,0,len){
        if(vis[i]) continue;
        cout<<str[i];
    }
}
