#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> m;
    m["botswana"] = 0; 
    m["ethiopia"] = 50;
    m["kenya"] = 50;
    m["namibia"] = 140; //남아프리카 사전에 갈 수 있으면 40
    m["south-africa"] = 0;
    m["tanzania"] = 50;
    m["zambia"] = 50; // 잠비아 짐바브웨 연속 방문시 50
    m["zimbabwe"] = 30;

    int n; cin>>n;
    bool sa_nam = 0; //남아프리카 나미비아
    int ans = 0;
    bool zam_zim = 0; //잠비아 짐바브웨
    rep(i,0,n){
        string str; cin>>str;
        if(str=="south-africa") sa_nam = 1;
        if(str=="namibia" && sa_nam) ans-=100;
        if(str=="zambia" || str=="zimbabwe"){
            if(zam_zim) ans-=30;
            zam_zim = 1;
        }
        else zam_zim = 0;
        ans+=m[str];
    }
    cout<<ans<<'\n';

}