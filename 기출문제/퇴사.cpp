#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(int argc, char** argv) {

	int N;
	cin >> N;
	vector<int> T(N);
	vector<int> P(N);
	vector<int> Dp(N+1);
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	
	for (int i = N-1; i >= 0 ; i--) {
		if (i + T[i] >= N + 1) {
			Dp[i] = max(Dp[i + 1], 0);
			continue;
		}
		Dp[i] = max(Dp[i + 1], Dp[i + T[i]] + P[i]);
	}
	
	cout << Dp[0] << endl;
	return 0;
}