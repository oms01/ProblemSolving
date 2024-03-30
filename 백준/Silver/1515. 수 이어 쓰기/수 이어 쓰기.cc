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
    string str; cin>>str;
    int ans = 0;
    int idx = 0;
    while(++ans){
        string tmp = to_string(ans);
        rep(i,0,tmp.length()){
            if(str[idx]==tmp[i]) idx++;
            if(idx==str.length()){
                cout<<ans<<'\n';
                return 0;
            }
        }
    }
}