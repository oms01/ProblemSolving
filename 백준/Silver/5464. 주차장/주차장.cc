#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int fee[101]; //주차장 요금
int car[2001], loc[2001]; //차량 무게, 차가 주차된 주차장 번호
priority_queue<int,vector<int>,greater<>> pq; //top()에 주차가능한 주차장 번호

int main(){
    ios::sync_with_stdio(0); cin.tie(0);


    int n,m; cin>>n>>m;
    REP(i,1,n) cin>>fee[i];
    REP(i,1,m) cin>>car[i];

    REP(i,1,n) pq.push(i);

    queue<int> waiting; //대기자

    int ans = 0;
    rep(i,0,2*m){
        int x; cin>>x;
        if(x>0){ //입장

            if(!pq.empty()){ //주차 가능
                int t = pq.top(); pq.pop();
                loc[x] = t;
                ans += fee[t]*car[x];
            }
            else{
                waiting.push(x);
            }

        }
        else{ //퇴장
            x*=-1;
            pq.push(loc[x]);
            loc[x] = 0;
            if(!waiting.empty()){
                int c = waiting.front(); waiting.pop();
                int t = pq.top(); pq.pop(); //주차공간
                loc[c] = t;
                ans += fee[t]*car[c];
            }
        }
    }
    cout<<ans<<'\n';


}
