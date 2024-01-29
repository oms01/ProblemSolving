#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int input[10];
bool isused[10];
void func(int k,int num){
	if(k==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<' ';
		}
		cout<<"\n";
		return;
	}
	int temp=-1;
	for(int i=0;i<n;i++){
		if(temp==input[i]) continue;
//		if(!isused[i]){
			temp=input[i];
			arr[k]=input[i];
			isused[i]=1;
			func(k+1,input[i]);
			isused[i]=0;
//		}
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	sort(input,input+n);
	func(0,input[0]);
}