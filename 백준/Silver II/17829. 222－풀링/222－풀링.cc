#include<bits/stdc++.h>
using namespace std;
int t;
int arr[1050][1050];
int func(int x,int y){
	vector<int> v;
	for(int i=x;i<x+2;i++){
		for(int j=y;j<y+2;j++){
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(),v.end());
	return v[2];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			cin>>arr[i][j];
		}
	}
	while(t/2){
		for(int i=0;i<t;i+=2){
			for(int j=0;j<t;j+=2){
				arr[i/2][j/2] = func(i,j);
			}
		}
		t/=2;
	}
	cout<<arr[0][0];
}
