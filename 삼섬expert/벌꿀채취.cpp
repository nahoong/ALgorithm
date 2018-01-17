#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;
int Answer;
int N, M, C;
vector<vector<int> > map;
vector<vector<int> >d;

int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		Answer = 0;

		cin >> N >> M >> C;

		map.assign(N, vector<int>(N, 0));
		d.assign(N, vector<int>(N, -1));


		//입력단
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		//m일떄 최댓값을 d[][]에 저장
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j + M <= N) {
					d[i][j] = 0;
					for (int num = 0; num < (1 << M); num++) {
						int sum = 0;
						int maxHoney = 0;
						for (int use = 0; use < M; use++) { //사용여부
							if ((num & (1 << use)) != 0) {
								sum += map[i][j + use];
								maxHoney += map[i][j + use] * map[i][j + use];
							}
						}
						if (sum <= C && d[i][j] < maxHoney)
							d[i][j] = maxHoney;
					}
				}
			}
		}

		Answer = 0;
		//for (int i = 0; i < N; i++) {	//겹치지 않는 두 공간 고르기
		//	for (int j = 0; j <= N - M; j++) {
		//		for (int k = i; k < N; k++) {
		//			for (int l = 0; l <= N - M; l++) {
		//				if (i == k && abs(j - l) >= M && Answer < d[i][j] + d[k][l]) {//같은 줄
		//					Answer = d[i][j] + d[k][l];
		//				}
		//				else if (i != k && Answer < d[i][j] + d[k][l])//다른 줄
		//					Answer = d[i][j] + d[k][l];
		//			}
		//		}
		//	}
		//}
		for (int i = 0; i <= N*N - M; i++) {
			for (int j = M; j <= N*N - M; j++) {
				if (i % N > N - M || j % N > N - M || j-i<M) continue;
				Answer = max(Answer, (d[i/N][i%N] + d[j/N][j%N]));
			}
		}


		cout << "#" << t + 1 << ' ' << Answer << endl;
	}
	return 0;
}