#include <bits/stdc++.h>
using namespace std;
int n,m;
struct s{
    int st,en,idx;
};
bool cmp(s &a, s &b){
    if(a.st == b.st) return a.en > b.en;
    return a.st < b.st;
}
bool cmp2(s &a, s&b){
    return a.idx < b.idx;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int mx = 0;
    vector<s> v;
    for(int i=0;i<m;i++){
        int st,en;
        cin>>st>>en;
        if(st>en){
            mx = max(mx,en);
            en+=n;
        }
        v.push_back({st,en,i+1});
    }
    sort(v.begin(),v.end(),cmp);
    vector<s> ans;
    for(int i=0;i<m;i++){
        if(v[i].en <= mx) continue;
        if(ans.empty() || (ans.size() && ans.back().en < v[i].en)){
            ans.push_back(v[i]);
        }
    }

    sort(ans.begin(),ans.end(),cmp2);
    for(auto x:ans){
        cout<<x.idx<<' ';
    }

}