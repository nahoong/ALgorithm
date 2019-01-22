#include<iostream>

using namespace std;

int main() {

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int N;
		cin >> N;
		long double a, b, sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			sum += a * b;
		}
		cout << fixed;
		cout.precision(6);
		cout << "#" << t << " " << sum << endl;
	}

}