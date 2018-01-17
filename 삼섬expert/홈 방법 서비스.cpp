#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int Answer_max;
int N, M;
vector<vector<int> > map;

int service(int i, int j, int k) {

	int Answer = 0;
	
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (map[a][b] && abs(i - a) + abs(j - b) < k)
				Answer++;
		}
	}
	
	return Answer;
}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N >> M;
		map.assign(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << map[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		Answer_max = 0;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= N + 1; k++) {
					int Answer = service(i, j, k);
					if (Answer*M - (k*k + (k - 1)*(k - 1)) >= 0 && Answer_max < Answer) {
						//	cout << "(" << i << '.' << j << ")   " << "k = " << k << " /// Answer = " << Answer << endl;
						Answer_max = Answer;
					}
				}
			}
		}




		cout << "#" << t + 1 << " " << Answer_max << endl;
	}
	return 0;
}