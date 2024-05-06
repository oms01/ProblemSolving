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
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k; //n마리 소, m개 탑, 무게차이 k
    vector<pii> v(n);
    rep(i,0,n){
        cin>>v[i].X>>v[i].Y; //무게 x가 y마리
        v[i].Y = min(v[i].Y,m);
    }
    sort(rall(v));
    //무대의 맨 윗 칸만 추적
    priority_queue<pii> pq;
    pq.push({2e9,m}); //BASE

    ll ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 0; //v[i]가 들어갈 수 있는 칸의 개수
        while(!pq.empty() && cnt <= v[i].Y && pq.top().X-v[i].X >= k){
            auto cur = pq.top(); pq.pop();
            cnt+=cur.Y;
            if(cnt>v[i].Y){
                pq.push({cur.X, cnt-v[i].Y});
            }
        }
        pq.push({v[i].X,min(cnt,v[i].Y)});
        ans+=min(cnt,v[i].Y);
    }
    cout<<ans<<'\n';

}
