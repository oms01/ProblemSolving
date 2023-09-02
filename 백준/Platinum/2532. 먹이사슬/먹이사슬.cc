#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
vector<pair<int,int>> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({b,-c});
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<int> lis;
    for(pair<int,int> val : v){
        if(lis.empty() || lis.back() <= val.Y) lis.push_back(val.Y);
        else *upper_bound(lis.begin(),lis.end(),val.Y) = val.Y;
    }
    cout<<lis.size()<<'\n';
}