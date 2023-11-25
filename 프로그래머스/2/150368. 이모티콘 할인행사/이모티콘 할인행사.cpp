#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> ans(2,0);
    vector<pii> v;
    for(int i=0;i<pow(4,emoticons.size());i++){
        vector<int> sale(emoticons.size()); //할인율
        int cur = i;
        for(int j=0;j<emoticons.size();j++){
            sale[j] = ((cur%4)+1)*10; cur/=4;
        }
        vector<int> pay(users.size(),0); //지불할 금액
        int join=0; //서비스 가입자 수
        for(int j=0;j<users.size();j++){
            for(int k=0;k<emoticons.size();k++){
                if(users[j][0] > sale[k]) continue;
                pay[j] += emoticons[k]/100 * (100-sale[k]);
            }
            if(users[j][1] <= pay[j]){
                join++;
                pay[j] = 0;
            }
        }
        int tmp = 0;
        for(int j=0;j<users.size();j++) tmp+=pay[j];
        v.push_back({join,tmp});
        
    }
    sort(v.begin(),v.end(),greater<>());
    tie(ans[0],ans[1]) = v[0];
    return ans;
}