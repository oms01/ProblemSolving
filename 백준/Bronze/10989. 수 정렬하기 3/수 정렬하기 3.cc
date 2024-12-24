#include<iostream>
using namespace std;

int main() {
	int arr[10001] = { 0 };
	int t;
	int num;
	scanf("%d", &t);

	for (int i = 0;i < t;i++) {
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 1;i <= 10000;i++) {
		for (int j = 0;j < arr[i];j++) {
			printf("%d\n", i);
		}
	}
}