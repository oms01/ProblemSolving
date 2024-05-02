#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

bool vis[500'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    string str; cin>>str;
    stack<int> s;
    int cnt = 0;
    rep(i,0,n){
        while(!s.empty() && str[s.top()] < str[i] && k){
            vis[s.top()]=1;
            s.pop();
            k--;
        }
        s.push(i);
    }
    while(k){
        vis[s.top()]=1;
        s.pop();
        k--;
    }
    rep(i,0,n){
        if(!vis[i]) cout<<str[i];
    }


}