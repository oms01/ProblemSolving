#include<iostream>
#include<cmath>
using namespace std;
int main() {
	string board[10];
	int cnt=0;
	for(int i=0;i<8;i++){
		cin>>board[i];
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2==0 && board[i][j]!='.'){
				cnt++;
			}
		}
	}
	cout<<cnt;
}