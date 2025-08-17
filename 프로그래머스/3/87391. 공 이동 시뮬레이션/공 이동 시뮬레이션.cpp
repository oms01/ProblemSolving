#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

ll solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    pair<ll,ll> mx = {x,y}, mn = {x,y};
    
    reverse(queries.begin(),queries.end());
    for(auto q: queries){
        int dir = q[0];
        int x = q[1];
        if(dir==0){
            if(mn.Y!=0) mn.Y = mn.Y+x;
            mx.Y = min(mx.Y+x,m-1LL);
        }
        else if(dir==1){
            mn.Y = max(mn.Y-x, 0LL);
            if(mx.Y!=m-1) mx.Y = mx.Y-x;
        }
        else if(dir==2){
            if(mn.X!=0) mn.X = mn.X+x;
            mx.X = min(mx.X+x, n-1LL);
        }
        else if(dir==3){
            mn.X = max(mn.X-x,0LL);
            if(mx.X!=n-1) mx.X = mx.X-x;
        }
        
        if(mx.X<mn.X || mx.Y<mn.Y) return 0LL;
    }

    ll r = mx.X-mn.X+1;
    ll c = mx.Y-mn.Y+1;
    return r*c;
}