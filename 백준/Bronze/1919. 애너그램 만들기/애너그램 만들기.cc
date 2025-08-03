#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[30][2]={0};
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		arr[a[i]-'a'][0]++;
	}
	for(int i=0;i<b.length();i++){
		arr[b[i]-'a'][1]++;
	}
	int num=0;
	for(int i=0;i<26;i++){
//		cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
		if(arr[i][0]>arr[i][1]){
			num+=arr[i][0]-arr[i][1];
		}
		else if(arr[i][0]<arr[i][1]){
			num+=arr[i][1]-arr[i][0];
		}
	}
	cout<<num;
}