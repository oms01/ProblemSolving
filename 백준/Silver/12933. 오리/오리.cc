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

char quack[] = {'q','u','a','c','k'};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;

    int cnt = 0;
    int ans=0;
    bool flag = 1;
    while(flag){
        int idx = 0;
        flag = 0;
        rep(i,0,str.length()){
            if(str[i]==quack[idx]){
                if(idx==4) flag = 1;
                idx = (idx+1)%5;
                str[i]='-';
                cnt++;
            }
        }
        if(flag) ans++;
    }
    if(cnt!=str.length() || str.length()%5!=0) ans=-1;
    cout<<ans<<'\n';

}
