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
    ll n,m; cin>>n>>m;
    set<pll> item;
    set<pll> st; //시작점 1템 : N
    set<pll> st_1w; //시작점 1템 1걷 : N*4
    set<pll> en; //도착점 -1템 : N
    rep(i,0,n){
        ll a,b; cin>>a>>b;
        item.insert({a,b});
    }
    pll t; cin>>t.X>>t.Y;
    for(pll x : item){
        st.insert(x);
        en.insert({t.X-x.X, t.Y-x.Y});
    }
    
    for(pll x: st){
        for(int dir=0;dir<4;dir++){
            st_1w.insert({x.X + dx[dir],x.Y + dy[dir]});
        }
    }

    ll onlywalk = abs(t.X)+abs(t.Y); //걷기만했을때 소요 기력

    //기력1: 1걷
    if(onlywalk == 1 && m>=1){
        cout<<"1\n";
        return 0;
    }
    //기력2 : 2걷 , 1템
    if((onlywalk == 2 || st.find(t)!=st.end()) && m>=2){
        cout<<2<<'\n';
        return 0;
    }

    //기력3 : 3걷, 1템+1걷
    bool flag = 0;
    for(auto x: st){ 
        if(abs(t.X-x.X) + abs(t.Y-x.Y) == 1) flag=1;
    }
    if((onlywalk == 3 || flag) && m>=3){
        cout<<3<<'\n';
        return 0;
    }

    //기력4 : 4걷, 1템+2걷, 2템
    flag = 0;
    for(auto x : st){
        if(abs(t.X-x.X) + abs(t.Y-x.Y) <= 2) flag=1;
        if(en.find(x)!=en.end()) flag=1;
    }
    if((onlywalk == 4 ||flag) && m>=4){
        cout<<4<<'\n';
        return 0;
    }

    //기력 5
    // 5걷, 1템+3걷, 2템+1걷
    flag = 0;
    for(auto x: st){ 
        if(abs(t.X-x.X) + abs(t.Y-x.Y) <= 3) flag = 1;
    }
    for(auto x : st_1w){
        if(en.find(x)!=en.end()) flag = 1;
    }
    if((onlywalk == 5 || flag) && m>=5){
        cout<<5<<'\n';
        return 0;
    }

    cout<<-1<<'\n';


}