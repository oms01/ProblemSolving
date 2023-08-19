#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll num[20];
int op[4]; //+,-,x,/
ll mx = -2e9;
ll mn = 2e9;
void func(ll cur, int d){
    if(d==n){
        // cout<<cur<<' ';
        mn = min(mn,cur);
        mx = max(mx,cur);
        return;
    }

    for(int i=0;i<4;i++){
        if(!op[i]) continue;

        op[i]-=1;
        if(i==0){
            func(cur+num[d],d+1);
        }
        else if(i==1){
            func(cur-num[d],d+1);
        }
        else if(i==2){
            func(cur*num[d],d+1);
        }
        else{
            func(cur/num[d],d+1);
        }
        op[i]+=1;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    for(int i=0;i<4;i++) cin>>op[i];

    func(num[0],1);

    cout<<mx<<'\n'<<mn<<'\n';

}