#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        vector<int> v(n);
        while(cin>>v[0]){
            if(!v[0]) break;
            rep(i,1,n) cin>>v[i];
            int tmp=n,idx=n-1;
            stack<int> s;
            rep(i,0,n){
                s.push(v[idx--]);
                while(!s.empty() && s.top()==tmp){tmp--;s.pop();}
            }
            cout<<(s.empty()? "Yes\n":"No\n");
        }
        cout<<'\n';
    }

}