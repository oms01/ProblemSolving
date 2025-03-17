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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,t; cin>>n>>t;
    vector<int> turn(t);
    rep(i,0,t) cin>>turn[i];
    queue<tuple<int,string,int>> card;
    rep(i,0,t){
        int id,x=-1; string q;
        cin>>id>>q;
        if(q!="next") cin>>x;
        card.push({id,q,x});
    }
    vector<set<int>> filed(n+1);
    set<int> use;

    vector<tuple<int,string,int>> hand(n+1);
    rep(i,0,t){
        int cur = turn[i];

        auto [id,q,x] = hand[cur];
        bool flag = 0;
        if(id==0){ //카드를 필드에서 가져오는 경우
            flag = 1;
            auto query = card.front(); card.pop();
            id = get<0>(query);
            q = get<1>(query);
            x = get<2>(query);
        }

        // cout<<id<<' '<<q<<' '<<x<<'\n';

        cout<<id<<'\n';

        if(q=="next"){
        }
        else if(q=="acquire"){
            // acquire
            if(use.count(x)){
                hand[cur] = {id,q,x};
                continue;
            }
            else{
                use.insert(x);
                filed[cur].insert(x);
            }
        }
        else{
            // release
            filed[cur].erase(x);
            use.erase(x);
        }
        hand[cur] = {0,"",0};
    }

}