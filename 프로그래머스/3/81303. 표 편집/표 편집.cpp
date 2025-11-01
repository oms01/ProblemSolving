#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int nxt, prev;
} board[1'000'001];
int cur;
string ans;
stack<Node> s;
int n;

void U(int x){
    while(x--) cur = board[cur].prev;
}
void D(int x){
     while(x--) cur = board[cur].nxt;
}
void C(){
    int nxt = board[cur].nxt;
    int prev = board[cur].prev;
    
    s.push(board[cur]);
    ans[cur] = 'X';
    
    board[nxt].prev = prev;
    board[prev].nxt = nxt;
    cur = board[cur].nxt==-1 ? prev : nxt;
}
void Z(){
    auto tmp = s.top(); s.pop();
    ans[tmp.val] = 'O';
    if(tmp.prev!=-1) board[tmp.prev].nxt = tmp.val;
    if(tmp.nxt!=-1) board[tmp.nxt].prev = tmp.val;
}

string solution(int N, int k, vector<string> cmd) {
    n = N;
    
    for(int i=0;i<n;i++){
        board[i].val = i;
        board[i].prev = i==0 ? -1 : i-1;
        board[i].nxt = i==n-1 ? -1 : i+1;
    }
    
    for(int i=0;i<n;i++) ans += 'O';
    cur = k;
    
    for(auto str: cmd){
        if(str[0]=='U') U(stoi(str.substr(2)));
        else if(str[0]=='D') D(stoi(str.substr(2)));
        else if(str[0]=='C') C();
        else Z();
    }
    
    return ans;
}