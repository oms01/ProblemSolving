#include<bits/stdc++.h>
using namespace std;
int s;
int vis[10'001][10'001];
tuple<int,int,int> first(int a,int b,int c){
    return {a,b,b};
}
tuple<int,int,int> second(int a,int b,int c){
    return {a,b+c,c};
}
tuple<int,int,int> third(int a,int b,int c){
    return {a,b-1,c};
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    queue<tuple<int,int,int>> q;
    q.push({0,1,0});//횟수, 임티개수, 클립보드임티개수
    vis[1][0] = 1;
    while(!q.empty()){
        int a,b,c;
        tie(a,b,c) = q.front(); q.pop();
        for(auto nxt:{first(a,b,c), second(a,b,c), third(a,b,c)}){
            int na,nb,nc;
            tie(na,nb,nc) = nxt;
            if(nb==s){
                cout<<na+1;
                return 0;
            }
            if(nb<0 || nb+nc > 1000) continue;
            if(vis[nb][nc]) continue;
            vis[nb][nc] = true;
            
            q.push({na+1,nb,nc});
        }
        // cout<<'\n';
    }
}