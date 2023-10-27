#include<bits/stdc++.h>
using namespace std;
double res;
int n;
int x, y;
vector<pair<int, int>> v;
double ex(double x1, double x2, double x3, double y1, double y2, double y3) {
	return ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x >> y;
		v.push_back({ x ,y });
	}
	for (int i = 1;i < n;i++) {
		res += ex(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);
	}
	printf("%.1lf", abs(res));
}

