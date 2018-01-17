#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int n, s;
int a[101] = { 0, };
int sum_a[101] = { 0, };
int sum_aa[101] = { 0, };

void precalc() {

	sort(a, a + n);
	sum_a[0] = a[0];
	sum_aa[0] = a[0] * a[0];

	for (int i = 1; i < n; i++) {
		sum_a[i] = sum_a[i-1] + a[i];
		sum_aa[i] = sum_aa[i - 1] + a[i] * a[i];
	}

}

int minerr(int Lo, int Hi) {
	int sum, sum2;
	int m;

	sum = sum_a[Hi] - (Lo == 0 ? 0 : sum_a[Lo - 1]);
	sum2 = sum_aa[Hi] - (Lo == 0 ? 0 : sum_aa[Lo - 1]);
	m = int(0.5+double(sum_a[Hi] - sum_a[Lo - 1]) / (Hi - Lo + 1));

	return sum2 - 2 * m * sum + m*m*(Hi - Lo + 1);

}

int cache[101][11];

int quant(int from, int parts) {

	if (from == n)	return 0;
	if (parts == 0)	return 987654321;

	int& ret = cache[from][parts];
	if (ret != -1)	return ret;
	ret =  987654321;

	for (int size = 1; size <= n; size++) {
		ret = min(ret, minerr(from, from + size - 1) + quant(from + size, parts - 1));
	}

	return ret;


}
int main(char argc, char* argv) {

	freopen("input.txt", "r", stdin);
	int cases;
	cin >> cases;

	while (cases--) {

		cin >> n >> s;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		precalc();

		memset(cache, -1, sizeof(cache));
		cout << quant(0, s) << endl;
				
	}
}