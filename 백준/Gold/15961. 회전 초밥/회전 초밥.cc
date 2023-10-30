#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<double,double> pii;
int n,d,k,c;
vector<int> v;
int ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //접시 수 n, 초밥 종류 d, 
    //연속해서 먹는 접시 수 k, 쿠폰번호 c
    cin>>n>>d>>k>>c; 
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<k-1;i++) v.push_back(v[i]);

    int st = 0;
    int en = k-1;
    unordered_map<int,int> m;
    for(int i=0;i<k;i++){
        m[v[i]]++;
    }
    st++; en++;
    m[c]++;
    // for(auto i = m.begin(); i!=m.end();i++){
    //     cout<<i->X<<' '<<i->Y<<'\n';
    // }
    // cout<<"===============\n";
    ans = m.size();
    // cout<<ans<<'\n';
    while(1){
        if(en == v.size()) break;

        m[v[st-1]]--;
        if(m[v[st-1]]==0){
            // cout<<"!";
            m.erase(v[st-1]);
        }
        m[v[en]]++;

        ans = max(ans,(int)m.size());
        // for(auto i = m.begin(); i!=m.end();i++){
        //     cout<<i->X<<' '<<i->Y<<'\n';
        // }
        // cout<<"===============\n";
        st++;
        en++;
    }
    cout<<ans<<'\n';
}