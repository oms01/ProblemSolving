#include<bits/stdc++.h>
using namespace std;
bool board[11][11];
bool isused1[22]; // 대각선 /
bool isused2[22]; // 대각선 

int bishop[2];
int n;
//color 0 : 검정, 1 : 흰
void dfs(int cnt, int x, int y, int color){
	if(x>=n){ //다음칸
		y++;
		if(x%2) x=0;
		else x=1;
	}
	if(y>=n){ //비숍 수 저장
		if(cnt>bishop[color]) bishop[color]=cnt;
		return;
	}
	if(board[y][x]&&!isused1[x+y+1]&&!isused2[x-y+n]){
		isused1[x+y+1]=true;
		isused2[x-y+n]=true;
		dfs(cnt+1,x+2,y,color);
		isused1[x+y+1]=false;
		isused2[x-y+n]=false;
	}
	dfs(cnt,x+2,y,color);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
		}
	}
	
	dfs(0,0,0,0); //검은칸에 들어갈 수 있는 비숍 수 최대 구하기
	dfs(0,1,0,1); //흰칸에 들어갈 수 있는 비숍 수 최대 구하기
	
	cout<<bishop[0]+bishop[1];
	
}