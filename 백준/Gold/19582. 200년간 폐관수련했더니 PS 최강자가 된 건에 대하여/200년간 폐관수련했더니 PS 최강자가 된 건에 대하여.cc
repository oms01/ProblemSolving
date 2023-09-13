#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    ll sum = 0;
    ll mxp = 0;
    ll cnt = 0;
    vector<ll> v;
    while(t--){
        ll x,p;
        cin>>x>>p;
        if(sum <= x){ //참여 o
            sum+=p;
            mxp = max(mxp,p);
            v.push_back(p);
        }
        else if(mxp >= p && sum-mxp <= x){ //상금 제일 비싼거 참여 안하고 이번꺼 참여
            sum-=mxp;
            sum+=p;
            v.erase(remove(v.begin(),v.end(),mxp),v.end());
            mxp = *max_element(v.begin(),v.end());
            cnt++;
        }
        else{ //참여 x
            cnt++;
        }
    }
    if(cnt>=2){
        cout<<"Zzz";
    }
    else{
        cout<<"Kkeo-eok";
    }
}