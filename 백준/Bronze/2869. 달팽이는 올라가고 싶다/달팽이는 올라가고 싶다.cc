#include<iostream>
using namespace std;

int main() {
	int plus, minus, height;
	cin >> plus >> minus >> height;

	cout << (height - minus - 1) / (plus - minus) + 1;
}