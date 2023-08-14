#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

	int arr[1000001];
int main(){
	int i,a;
	scanf("%d", &a);

	for(i=0;i<a;i++){
		scanf("%d", &arr[i]);
	}
	
	sort(arr,arr+a);
	
	for(i=0;i<a;i++){
		printf("%d\n", arr[i]);
	}
}
