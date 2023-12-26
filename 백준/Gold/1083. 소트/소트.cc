#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int t;
    cin>>t;

    for(int i=0;i<n;i++){
        int mx = v[i];
        int idx = i;
        for(int j=i+1;j<n;j++){
            if(t < j-i) break;
            if(mx<v[j]){
                mx = v[j];
                idx = j;
            }
        }
        for(int j=idx;j>i;j--){
            swap(v[j],v[j-1]);
        }
        t-=idx-i;
        if(t<=0) break;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';

}