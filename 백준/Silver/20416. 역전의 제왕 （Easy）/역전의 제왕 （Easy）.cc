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

int parse(string str){ return stoi(str.substr(0,2))*60+stoi(str.substr(3,5)); }
int sol[51],pan[51],point[51],idx[51];
vector<int> tmp;
vector<tuple<int,int,int>> aft_frz[51];

int rank_cmp(int a,int b){
    if(sol[a]!=sol[b]) return sol[a]>sol[b];
    return pan[a]<pan[b];
};

int find_last(){
    for(int i=tmp.size()-1;i>=0;i--){
        if(idx[tmp[i]] < aft_frz[tmp[i]].size()){
            return tmp[i];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;

    rep(i,1,n+1) tmp.push_back(i);

    while(m--){
        string str; cin>>str;
        int id,p,s; cin>>id>>p>>s; 
        int t = parse(str);
        if(t<=180){ 
            pan[id]+=t+((s-1)*20);
            sol[id]++;
        }
        else aft_frz[id].push_back({t,p,s});
    }

    rep(i,0,51){
        sort(all(aft_frz[i]), [](tuple<int,int,int> a, tuple<int,int,int> b){
            return get<1>(a) < get<1>(b);
        });
    }

    vector<int> rank(51,0);
    sort(all(tmp), rank_cmp);
    rep(i,0,n) rank[tmp[i]]=i;

    while(1){
        int id = find_last();
        if(id==-1) break;
        
        int t,p,s; tie(t,p,s)=aft_frz[id][idx[id]++];
        int cur_rank=rank[id];
        pan[id]+=t+((s-1)*20);
        sol[id]++;

        sort(all(tmp), rank_cmp);
        rep(i,0,n) rank[tmp[i]] = i;

        point[id] += cur_rank - rank[id];

    }

    int ans = -1;
    int mx = -1;
    rep(i,1,n+1){
        if(mx<point[i] || (mx==point[i] && rank[ans] > rank[i])){
            mx = point[i];
            ans = i;
        }
    }
    cout<<ans<<'\n';

}