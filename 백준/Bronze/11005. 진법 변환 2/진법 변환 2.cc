#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    string str="";
    while(n){
        int t = n%m;
        if(t>=10){
            str+=(char)('A'+t-10);
        }
        else{
            str+=t+'0';
        }
        n/=m;
    }
    reverse(str.begin(),str.end());
    cout<<str<<'\n';
}