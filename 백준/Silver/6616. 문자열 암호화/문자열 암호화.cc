#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin>>n){
        if(n==0) break;
        cin.ignore();
        string in;
        getline(cin,in);
        string str="";
        rep(i,0,in.length()){
            if(in[i]!=' ') str+=in[i];
        }
        rep(i,0,str.length()){
            str[i] = toupper(str[i]);
        }

        vector<char> v(str.length(),'-');
        int idx = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<str.size();j+=n){
                // cout<<j<<' ';
                v[j] = str[idx++];
                // v[i+j] = str[i+j];
            }
            // cout<<'\n';
        }

        for(int i=0;i<str.length();i++){
            cout<<v[i];
        }
        cout<<'\n';

        

    }
    
}
