#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, result;
	int num = 0;
	cin >> t >> result;
	int* money = new int[t];
	for (int i = t-1;i >= 0 ;i--) {
		cin >> money[i];
	}
	for (int i = 0;i < t;i++) {
		if (money[i] <= result) {
//			cout << "!";
			num += result / money[i];
			result %= money[i];
		}
//		cout << money[i] << "\n";
	}
	cout << num;
}