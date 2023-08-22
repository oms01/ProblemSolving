#include <bits/stdc++.h>
using namespace std;
int mx[3];
int mn[3];
int input[3];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[0]>>input[1]>>input[2];

        if(i==0){
            for(int j=0;j<3;j++) mx[j] = mn[j] = input[j];
            continue;
        }
        int tmp[3];
        tmp[0] = max(mx[0],mx[1]) + input[0];
        tmp[1] = max(mx[0],max(mx[1],mx[2])) + input[1];
        tmp[2] = max(mx[1],mx[2]) + input[2];
        for(int i=0;i<3;i++) mx[i]=tmp[i];


        tmp[0] = min(mn[0],mn[1]) + input[0];
        tmp[1] = min(mn[0],min(mn[1],mn[2])) + input[1];
        tmp[2] = min(mn[1],mn[2]) + input[2];

        for(int i=0;i<3;i++) mn[i]=tmp[i];
    }

    cout<<max(mx[0],max(mx[1],mx[2]))<<' '<<min(mn[0],min(mn[1],mn[2]))<<'\n';
}