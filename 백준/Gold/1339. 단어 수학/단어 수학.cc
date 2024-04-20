#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<char,int> m;
    rep(i,0,n){
        string str; cin>>str;
        rep(i,0,str.length()){
            m[str[i]] += pow(10,str.length()-i-1);
        }
    }
    vector<int> v;
    for(auto i=m.begin();i!=m.end();i++) v.push_back(i->Y);
    sort(v.rbegin(),v.rend());

    int ans = 0;
    int tmp = 9;
    for(int i=0;i<v.size();i++){
        ans+=v[i]*tmp--;
    }
    cout<<ans<<'\n';
}
