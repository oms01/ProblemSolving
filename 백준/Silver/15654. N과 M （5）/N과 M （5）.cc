#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int input[10];
bool isused[10002];
void func(int k){
	if(k==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<' ';
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
        int cur = input[i];
		if(isused[cur]) continue;
        arr[k]=cur;
        isused[cur]=1;
        func(k+1);
        isused[cur]=0;
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
	func(0);
}