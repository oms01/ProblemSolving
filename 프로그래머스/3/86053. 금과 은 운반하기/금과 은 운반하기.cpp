#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll val, int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t){
    ll gg = 0;
    ll ss = 0;
    ll tot = 0;
    for(int i=0;i<g.size();i++){
        ll tt = t[i];
        ll mv = val/(tt*2);
        if(val%(tt*2)>=tt) mv++;
        
        gg += min((ll)g[i], mv*w[i]);
        ss += min((ll)s[i], mv*w[i]);
        tot += min((ll)g[i]+s[i], mv*w[i]);
    }
    
    return (a<=gg && b<=ss && a+b<=tot);
}
ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll ans = -1;
    
    ll st = 0, en = 2e15;
    while(st<=en){
        ll mid = (st+en)/2;
        
        if(f(mid,a,b,g,s,w,t)){
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return st;
}