#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mm;
string arr[1001];
vector<int> adj[1001];
int deg[1001];
set<string> ans[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        mm[str] = i;
        arr[i] = str;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        adj[mm[b]].push_back(mm[a]);
        deg[mm[a]]++;
    }

    queue<int> q;
    int cnt = 0;
    vector<string> v;
    for(int i=0;i<n;i++){
        if(!deg[i]){
            cnt++;
            q.push(i);
            v.push_back(arr[i]);
        }
    }
    sort(v.begin(),v.end());
    
    cout<<cnt<<'\n';
    for(auto x:v) cout<<x<<" ";
    cout<<'\n';

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt:adj[cur]){
            if(--deg[nxt]==0){
                ans[cur].insert(arr[nxt]);
                q.push(nxt);
            }
        }
    }

    for(auto x:mm){
        cout<<x.first<<' '<<ans[x.second].size()<<' ';
        for(auto y:ans[x.second]){
            cout<<y<<' ';
        }
        cout<<'\n';
    }

}