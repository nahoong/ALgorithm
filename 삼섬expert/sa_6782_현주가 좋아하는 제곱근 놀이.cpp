#include<iostream>
#include<map>
#include<cmath>

using namespace std;

//무조건 제곱이 빠르다 가정하에

map<long long, int> two;
int sum;

bool IsSquare(long long num) {
	//cout << "is not " << num << endl;
	long long temp;
	switch (num & 0x0f) {
	case 0:
	case 1:
	case 4:
	case 9:
		temp = (long long)(sqrt((long double)num) + 0.5);
		return temp * temp == num;

	default:
		return false;
	}
}

void dfs(long long N, int count) {
	//cout << N << "," << count << endl;
	int temp = 0;
	long long val;
	if (two.find(N) == two.end()) {
		if (IsSquare(N)) {
			val = sqrt(N);
			dfs(val, count +1);
		}
		else {
			val = long long(int(sqrt(N)) + 1) * long long(int(sqrt(N)) + 1);
			dfs(val, count+int(val-N));
		}

	}
	else if (two.find(N) != two.end()) {
		//cout << "찾음" << N << endl;
		count += two[N];
		sum = count;
	}
}

int main() {

	two[2] = 0;
	two[4] = 1;
	two[16] = 2;
	two[256] = 3;
	two[65536] = 4;

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {

		long long N;
		cin >> N;
		sum = 0;

		//if (IsSquare(N)) {
		//	cout << " 정 " << sqrt(N) << endl;
		//}
		//else {
		//	cout << " 낫 정 " << long long(int(sqrt(N)) + 1)*(int(sqrt(N)) + 1) << endl;
		//}
		//cout << IsSquare(N) << endl;;
		dfs(N, 0);
		//cout << " 입력받음" << endl;
		cout << "#" << t << " " << sum << endl;
	}
}