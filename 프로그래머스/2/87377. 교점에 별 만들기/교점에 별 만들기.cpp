#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int mnX=2e9, mnY=2e9;
int mxX=-2e9, mxY=-2e9;
int board[1001][1001];
vector<pair<int,int>> v;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    for(int i=0;i<line.size();i++) for(int j=i+1;j<line.size();j++){
        int a,b,c,d,e,f;
        tie(a,b,e) = {line[i][0],line[i][1],line[i][2]};
        tie(c,d,f) = {line[j][0],line[j][1],line[j][2]};
        
        long long A = ((ll)b*f) - ((ll)e*d);
        long long B = ((ll)a*d) - ((ll)b*c);
        long long C = ((ll)e*c) - ((ll)a*f);

        if(B==0 || A%B || C%B) continue;
        
        int x = A/B;
        int y = C/B;
        v.push_back({A/B,C/B});
        mnX = min(mnX, x); mxX = max(mxX, x);
        mnY = min(mnY, y); mxY = max(mxY, y);
        
    }
    for(int i=0;i<v.size();i++){
        board[v[i].first-mnX][mxY-v[i].second] = 1;
    }
    for(int i=0;i<=mxY-mnY;i++){
        string tmp = "";
        for(int j=0;j<=mxX-mnX;j++){
            tmp+=(board[j][i]? '*':'.');
        }
        answer.push_back(tmp);
    }
    return answer;
}