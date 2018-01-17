#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int d[100001];
int main() {
	int n;
	cin >> n;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j*j] + 1) {
				d[i] = d[i - j*j] + 1;
			}
		}
	}
	cout << d[n] << '\n';
	return 0;
}