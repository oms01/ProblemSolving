#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    vector<pii> v(n);
    rep(i,0,n){
        cin>>v[i].Y>>v[i].X;
    }
    sort(v.rbegin(),v.rend());
    //뒤에서부터
    int cur = v[0].X;
    for(int i=0;i<v.size();i++){
        if(cur < v[i].X){
            cur-=v[i].Y;
        }
        else{
            cur = v[i].X - v[i].Y;
            if(cur<0){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }    
    cout<<cur<<'\n';
}

