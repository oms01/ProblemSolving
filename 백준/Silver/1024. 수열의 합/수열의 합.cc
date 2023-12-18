#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,l;
    cin>>n>>l;
    int a=0,b=0;
    do{
        a = n - ((l*(l-1))/2);
        b = l;
        if(a%b==0) break;
        l++;
        if(l>100){
            cout<<-1<<'\n';
            return 0;
        }
    }while(1);
    int a1 = a/b;
    if(a1<0){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=0;i<l;i++){
        cout<<a1+i<<' ';
    }
}