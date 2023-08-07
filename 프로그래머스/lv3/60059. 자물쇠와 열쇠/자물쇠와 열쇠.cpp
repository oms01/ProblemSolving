#include<bits/stdc++.h>
using namespace std;
int n,m; // key, lock
void print(vector<vector<int>> v){
    for(int a=0;a<v[0].size();a++){
        for(int b=0;b<v[0].size();b++){
            cout<<v[a][b]<<' ';
        }
        cout<<'\n';
    }
}
vector<vector<int>> rotate(vector<vector<int>> key){ // key 시계방향 90도 회전
    vector<vector<int>> tmp;
    int size = key[0].size();
    tmp.resize(size,vector<int>(size,0));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            tmp[i][j] = key[size-1-j][i];
        }
    }
    return tmp;
}
bool check(vector<vector<int>> lock){
    for(int i=n;i<n+n;i++){
        for(int j=n;j<n+n;j++){
            if(lock[i][j]!=1){
                return 0; // lock이 채워지지 않음
            }
        }
    }
    return 1;
}

bool func(vector<vector<int>> key, vector<vector<int>> lock){ //lock에 key 삽입 + 검사
    int keysize = key[0].size();
    int locksize = lock[0].size(); //board
    
    
    for(int i=0;i<locksize-keysize+1;i++){
        for(int j=0;j<locksize-keysize+1;j++){
            
            
            vector<vector<int>> tmp; //lock을 tmp에 복사
            tmp.resize(locksize, vector<int> (locksize,1));
            for(int i=0;i<locksize;i++){
                for(int j=0;j<locksize;j++){
                    tmp[i][j] = lock[i][j];
                }
            }
            
            for(int k=0;k<keysize;k++){
                for(int l=0;l<keysize;l++){
                    tmp[i+k][j+l] += key[k][l];
                }
            }
            if(check(tmp)){
                return 1;
            };
        }
    }
    return 0;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    m = key[0].size(); n = lock[0].size();
    
    vector<vector<int>> board; //lock을 board에 확장
    board.resize(3*n,vector<int> (3*n,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i+n][j+n] = lock[i][j];
        }
    }
    
    
    int t=4;
    while(t--){
        key = rotate(key);
        
        if(func(key,board)){
            return 1;
        };
        
    }
    
    return 0;
}