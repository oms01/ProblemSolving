#include <bits/stdc++.h>
using namespace std;

const int MX = 500;
int six[10];
vector<int> solution(vector<vector<int>> dice) {

    six[0] = 1;
    for(int i=1;i<=5;i++) six[i] = six[i-1]*6;
    
    int n = dice.size();
    vector<int> p(n,1);
    for(int i=0;i<n/2;i++) p[i] = 0;
    
    vector<int> ans;
    int mx = 0;
    do{
        vector<vector<int>> A,B;
        for(int i=0;i<n;i++){
            if(p[i]) A.push_back(dice[i]);
            else B.push_back(dice[i]);
        }
        
        int cnt[MX+1] = {0,};
        
        for(int _=0;_<six[B.size()];_++){
            int sum = 0;
            int tmp = _;
            for(int i=0;i<B.size();i++){
                sum += B[i][tmp%6];
                tmp/=6;
            }
            cnt[sum]++;
        }
        for(int i=1;i<=MX;i++) cnt[i] += cnt[i-1];
        
        // A가 승리할 확률이 높은???
        int vic = 0;
        int def = 0;
        int mu = 0;
        for(int _=0;_<six[A.size()];_++){
            int sum = 0;
            int tmp = _;
            for(int i=0;i<A.size();i++){
                sum += A[i][tmp%6];
                tmp/=6;
            }
            vic += cnt[sum-1] - cnt[0];
            mu = cnt[sum];
            def += cnt[MX] - cnt[sum];
        }
        
        // cout<<vic<<' '<<mu<<' '<<def<<'\n';         
        vector<int> tmp;
        
        // cout<<vic<<' ';
        if(mx < vic){
            mx = vic;
            ans.clear();
            for(int i=0;i<n;i++){
                if(p[i]) ans.push_back(i+1);
            }
        }
        
    }while(next_permutation(p.begin(),p.end()));
    // cout<<mx<<' ';
    return ans;
}