#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int sum_max=-999999999;
int sum_min=999999999;

int N;

void dfs(int p, int m, int t, int d, int sum, int deep){

	if (p == 0 && m == 0 && t == 0 && d == 0) {
		
		if (sum > sum_max) {
			sum_max = sum;
		}
		if (sum < sum_min) {
			sum_min = sum;
		}
		return;
	}

	if (p > 0 && deep < N) dfs(p - 1, m, t, d, sum + arr[deep+1], deep+1);
	if (m > 0 && deep < N) dfs(p , m-1, t, d, sum - arr[deep+1], deep+1);
	if (t > 0 && deep < N) dfs(p , m, t-1, d, sum * arr[deep+1], deep+1);
	if (d > 0 && deep < N) dfs(p , m, t, d-1, sum / arr[deep+1], deep+1);

	return;
}
int main(int argc, char** argv ) {

	
	cin >> N;
	arr.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int p, m, t, d;
	cin >> p >> m >> t >> d;

	dfs(p, m, t, d, arr[0], 0);



	cout << sum_max << endl << sum_min << endl;
	return 0;
	

}