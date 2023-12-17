#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int t;
string str;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        cin>>str;
        int len = str.length();
        if(len==1 || len==3 || str[len-1]=='0'){
            cout<<"NO\n";
            continue;
        }
        else if(len==2){
            cout<<(str=="01" ? "YES\n":"NO\n");
            continue;
        }
        bool ans = 1;
        for(int i=0;i<len;i++){
            // cout<<i;
            if(str[i]=='0'&&str[i+1]=='1') i++;
            else if(str[i]=='1'){
                if(i>len-4||str[i+1]!='0'||str[i+2]!='0'){
                    ans = 0; break;
                }
                while(str[++i]=='0');
                while(str[++i]=='1' && i<len);
                if(i==len) break;
                if(str[i+1]=='0'){
                    if(str[i-2]!='1') ans = 0;
                    else i-=2;
                }
                else i++;
            }
            else{
                ans = 0; break;
            }
        }
        cout<<(ans ? "YES\n":"NO\n");
    }


    return 0;
}