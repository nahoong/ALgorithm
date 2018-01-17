#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int Answer;
int fee_y, fee_3m, fee_m, fee_d=0;
vector<int> month(12, 0);

void dfs(int month_cnt, int cost) {

	if (cost >= Answer)	return;
	if (month_cnt >= 12) {
		if (Answer > cost) {
			Answer = cost;
		}
		return;
	}

	dfs(month_cnt + 1, cost + fee_d * month[month_cnt]);
	dfs(month_cnt + 1, cost + fee_m);
	dfs(month_cnt + 3, cost + fee_3m);
	dfs(month_cnt + 12, cost + fee_y);

}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		cin >> fee_d >> fee_m >> fee_3m >> fee_y;
		int cnt = 0;
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
			cnt += month[i];

		}
		Answer = max(fee_y, max(fee_m * 12, max(fee_3m * 4, fee_d * cnt))) + 1;
		dfs(0, 0);
		cout << "#" << t + 1 << ' ' << Answer << endl;
	}
	
	return 0;
}