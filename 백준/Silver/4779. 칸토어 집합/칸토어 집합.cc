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

vector<int> v;
void func(int st, int en, bool fill){

    if(st==en){
        v[st] = fill;
        return;
    }

    int m1 = (en-st+1)/3 + st;
    int m2 = (en-st+1)/3*2 + st;

    func(st, m1-1, 1&fill);
    func(m1, m2-1, 0&fill);
    func(m2, en, 1&fill);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        int len = pow(3,n);
        v.resize(len+1);
        func(1,len,1);
        rep(i,1,len+1){
            if(v[i]) cout<<"-";
            else cout<<" ";
        }
        cout<<'\n';
    }
}

