#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef pair<string,string> pss;
typedef pair<int,int> pii;
int n;
stack<pss> s;
int x,y; //분자, 분모 
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string in; 
        cin>>in;
        if(in==")"){
            if(s.size()<4){ cout<<-1<<'\n'; return 0; }
            if(s.top().X=="("||s.top().X==")"){ cout<<-1<<'\n'; return 0; }
            pii c = {stoi(s.top().X), stoi(s.top().Y)}; s.pop();

            if(s.top().X=="("||s.top().X==")"){ cout<<-1<<'\n'; return 0; }
            pii b = {stoi(s.top().X), stoi(s.top().Y)}; s.pop();

            if(s.top().X=="("||s.top().X==")"){ cout<<-1<<'\n'; return 0; }
            pii a = {stoi(s.top().X), stoi(s.top().Y)}; s.pop();

            if(s.top().X!="("){ cout<<-1<<'\n'; return 0; }
            s.pop();

            x = a.X*b.Y*c.X + a.Y*b.X*c.Y;
            y = a.Y*b.Y*c.X;
            int g = gcd(x,y);
            x/=g;
            y/=g;
            s.push({to_string(x),to_string(y)});
        }
        else{
            s.push({in,"1"});
        }
    }
    if(s.size()==1) cout<<x<<' '<<y<<'\n';
    else cout<<-1<<'\n';
    return 0;
}