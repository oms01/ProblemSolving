#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

multiset<int> dp[51]; //i원으로 살 수 있는 가장 큰 숫자
string func(multiset<int> s){
    string str="";
    for(auto x:s) str+=x+'0';
    sort(str.rbegin(),str.rend());
    return str;
}
bool cmp(multiset<int> a, multiset<int> b){ // a<b : 1
    string aa = func(a);
    string bb = func(b);
    if(aa[0]=='0' && aa.length() > 1) return 1;
    if(bb[0]=='0' && bb.length() > 1) return 0;
    if(aa.length() < bb.length()) return 1;
    if(aa.length() > bb.length()) return 0;
    for(int i=0;i<aa.length();i++){
        if(aa[i] > bb[i]) return 0;
        if(aa[i] < bb[i]) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    int m; cin>>m;

    rep(i,0,n){
        multiset<int> tmp; tmp.insert(i);
        if(!cmp(dp[v[i]],tmp)) continue;
        dp[v[i]] = tmp;
    }

    rep(i,1,51){
        if(dp[i].size()==0) continue;
        rep(j,0,n){
            if(i+v[j] > 50) continue;
            multiset<int> a = dp[i+v[j]];
            multiset<int> b = dp[i];
            b.insert(j);
            if(!cmp(a,b)) continue;
            dp[i+v[j]].clear();
            for(auto x:b) dp[i+v[j]].insert(x);
        }
    }
    multiset<int> ans;
    rep(i,1,m+1){
        if(cmp(ans,dp[i])) ans = dp[i];
    }
    cout<<func(ans)<<'\n';

}