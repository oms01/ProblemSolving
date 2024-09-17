#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m; //부서의 수, 건물의 수
    vector<pii> s(n);
    rep(i,0,n) { //부서 학생 수 , 인덱스
        cin>>s[i].X; 
        s[i].Y = i;
    }
    sort(all(s));
    priority_queue<pii, vector<pii>, greater<>> pq[1002]; //인원 i, {금액, 인덱스}

    vector<pii> p(m); //{수용인원, 대여료}
    rep(i,0,m) cin>>p[i].X;
    rep(i,0,m) cin>>p[i].Y;
    rep(i,0,m){
        pq[p[i].X].push({p[i].Y,i});
    }

    vector<tiii> v(m);
    rep(i,0,m) v[i] = {p[i].X,p[i].Y,i};
    sort(rall(s)); sort(all(v));

    //인원이 많은 부서부터 배치.
    //해당 부서 인원을 모두 포함할 수 있는 부서 중 싼 건물찾기

    vector<int> ans(n);
    rep(i,0,n){
        int mn_idx = -1;
        int mn_cost = 2e9;
        rep(j,s[i].X,1001){
            if(pq[j].empty()) continue;
            // cout<<j<<'/'<<pq[j].top().X<<' ';
            if(mn_cost > pq[j].top().X){
                mn_idx = j;
                mn_cost = pq[j].top().X;
            }
        }
        // cout<<'\n';
        if(mn_idx==-1){
            cout<<"impossible\n";
            return 0;
        }

        //pq[cnt].top() : i부서의 학생수(s[i].X)을 수용할 수 있는 건물의 {금액,인덱스}

        int cost, idx;
        tie(cost, idx) = pq[mn_idx].top(); pq[mn_idx].pop();
        // cout<<s[i].X<<','<<s[i].Y<<" : "<<mn_idx<<' '<<cost<<' '<<idx<<'\n';
        ans[s[i].Y] = idx;

    }

    rep(i,0,n) cout<<ans[i]+1<<" "; cout<<'\n';

}