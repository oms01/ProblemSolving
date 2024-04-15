#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin>>a>>b;
    while(a.length() < b.length()){
        if(b.back()=='B'){
            b = b.substr(0,b.length()-1);
            reverse(b.begin(),b.end());
        }
        else{
            b = b.substr(0,b.length()-1);
        }
    }
    cout<<(a==b)<<'\n';

}