#include<iostream>
#include<vector>
#include<algorithm>

#pragma warning(disable:4996)
using namespace std;

int n, d, p, q;
int connected[51][51], deg[51];


double cache[51][101];

double search2(int here, int days) {
	if (days == d) return (here == q ? 1.0 : 0.0);

	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
		if (connected[here][there])
			ret += search2(there, days + 1) / deg[here];
	return ret;
}

int main() {

	freopen("input.txt","r", stdin);

	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {

		cin >> n >> d >> p;
		memset(connected, 0,sizeof(connected));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> connected[i][j];
			}
		}
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; i++) {
			int count = 0; 
			for (int j = 0; j < n; j++) {
				if (connected[i][j] == 1)
					count += 1;
			}
			deg[i] = count;
		}
		int answer_n;
		cin >> answer_n;
		vector<int> tar(answer_n);
		for (int i = 0; i < answer_n; i++) {
			cin >> tar[i];
		}

		
		for (int i = 0; i < answer_n; i++) {
			memset(cache, -1, sizeof(cache));
			q = tar[i];
			cout.precision(9);
			//cout.setf(ios_base::showpoint);
			cout << fixed << search2(p, 0) << " ";

		}
		cout << endl;
	}


}