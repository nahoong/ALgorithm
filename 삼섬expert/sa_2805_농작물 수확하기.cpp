#include <iostream>
using namespace std;

char arr[50][50];

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int N;
		cin >> N;
		memset(arr, '0', sizeof(arr));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < N/2; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				ans += arr[i][(N / 2) - i + j]-'0';
			}
		}
		for (int i = N / 2; i < N; i++) {
			for (int j = 0; j < 2*(N-i)-1 ; j++) {
				ans += arr[i][i - (N / 2) + j]-'0';
			}
		}
		cout << "#" << t + 1 << " " << ans << endl;
	}
}