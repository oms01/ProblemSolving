#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x1=0,y1=0,x2=0,y2=0; //각 점들의 합
    for(int i=0;i<4;i++){
        ll x,y;
        cin>>x>>y;
        x1+=x; 
        y1+=y;
    }
    for(int i=0;i<4;i++){
        ll x,y;
        cin>>x>>y;
        x2+=x; 
        y2+=y;
    }
    ll a1 = y2-y1, a2 = x2-x1; //분자,분모
    ll tmp = gcd(a1,a2);
    a1/=tmp; a2/=tmp; //기울기

    ll b1 = y1*a2 - x1*a1, b2 = 4*a2; //분자,분모
    tmp = gcd(b1,b2);
    b1/=tmp; b2/=tmp; //y절편

    if(a2<0){
        a2*=-1;
        a1*=-1;
    }
    if(b2<0){
        b2*=-1;
        b1*=-1;
    }


    cout<<a1;
    if(a2!=1){
        cout<<'/'<<a2;
    }
    cout<<' ';

    cout<<b1;
    if(b2!=1){
        cout<<'/'<<b2;
    }
    cout<<'\n';
    // cout<<a1<<'/'<<a2<<' '<<b1<<'/'<<b2;
}
