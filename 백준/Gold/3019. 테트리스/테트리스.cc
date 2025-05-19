#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
int inputboard[200][200];
int board[200][200];
int c,p;
int blockIdx[7][2] = {{0,2},{2,3},{3,5},{5,7},{7,11},{11,15},{15,19}};
pair<int,int> shape[19][4] = {
    {{0,0},{0,1},{0,2},{0,3}}, //1-1 0
    {{0,0},{1,0},{2,0},{3,0}}, //1-2 1
 
	{{0,0},{0,1},{1,0},{1,1}}, //2-1 2

	{{0,0},{0,1},{1,1},{1,2}}, //3-1 3
	{{0,0},{1,0},{1,-1},{2,-1}}, //3-2 4

    {{0,0},{0,1},{-1,1},{-1,2}}, //4-1 5
    {{0,0},{1,0},{1,1},{2,1}}, //4-2 6

	{{0,0},{0,1},{0,2},{1,1}}, //5-1 7
    {{0,0},{1,0},{1,1},{2,0}}, //5-2 8
    {{0,0},{0,1},{0,2},{-1,1}}, //5-3 9
    {{0,0},{1,0},{1,-1},{2,0}}, //5-4 10

	{{0,0},{0,1},{0,2},{1,2}}, //6-1 11
    {{0,0},{1,0},{2,0},{0,1}}, //6-2 12
    {{0,0},{1,0},{1,1},{1,2}}, //6-3 13
    {{0,0},{0,1},{-1,1},{-2,1}}, //6-4 14

    {{0,0},{01,0},{0,1},{0,2}}, //7-1 15
    {{0,0},{1,0},{2,0},{2,1}}, //7-2 16
    {{0,0},{0,1},{0,2},{-1,2}}, //7-3 17 
    {{0,0},{0,1},{1,1},{2,1}}, //7-4 18

};
bool checkboard(){
	bool flag = true;
	for(int j=0;j<c;j++){
		int tmp = 0;
		for(int i=0;i<200;i++){
			if(board[i][j]!=0) tmp++;
		}
		for(int i=0;i<200;i++){
			if(board[i][j]==0){
				if (i < tmp) flag = false;
				break;
			}
		}
	}
	if(flag){
		//printboard();
		//cout<<'\n';
		return 1;
	}
	return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	vector<pair<int,int>> v; //탐색할 좌표 저장
	cin>>c>>p;
	for(int i=0;i<c;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++) inputboard[j][i]=1;
		v.push_back({n,i});
	}
	int cnt = 0;
	int st = blockIdx[p-1][0], en = blockIdx[p-1][1];
	for(auto cur:v){ //cur : 현재 탐색중인 칸
		for(int i = st;i<en;i++){ //블럭 회전에 의한 모양 변화 

			for(int j=0;j<200;j++){ //필드 복사
				for(int k=0;k<200;k++) board[j][k] = inputboard[j][k];
			}
			
			bool flag = true;
			for(int j=0;j<4;j++){ 
				int nx = cur.X + shape[i][j].X;
				int ny = cur.Y + shape[i][j].Y;
				if((nx<0||ny<0||ny>=c)||(board[nx][ny]==1)){
					flag = false;
					break;
				}
				board[nx][ny] = 2;
			}
			if(flag){
				cnt += checkboard();
				continue;
			}
		}
	}
	cout<<cnt;

}
/*

*/