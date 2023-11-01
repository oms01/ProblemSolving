#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<double,double> pii;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<tuple<int,int,int>> s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            s.push_back({v[i]+v[j], i, j});
        }
    }

    sort(s.begin(),s.end());
    int ans = 2e9;
    for(int i=0;i<s.size()-1;i++){
        int x1,x2,x3;
        int y1,y2,y3;
        tie(x1,x2,x3) = s[i];
        tie(y1,y2,y3) = s[i+1];

        if((x2==y2)||(x2==y3)||(x3==y2)||(x3==y3)) continue;
        ans = min(ans, y1-x1);
    }
    cout<<ans<<'\n';
}