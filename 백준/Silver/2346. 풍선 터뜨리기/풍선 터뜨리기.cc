#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    deque<pii> d;
    rep(i,1,n+1){
        int val; cin>>val;
        d.push_back({val,i});
    }
    while(!d.empty()){
        auto cur = d.front();
        cout<<cur.Y<<' ';
        d.pop_front();
        if(cur.X>0){
            rep(i,0,cur.X-1){
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else{
            rep(i,cur.X,0){
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

}

