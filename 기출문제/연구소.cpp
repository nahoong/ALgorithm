#include<iostream>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
vector<int> map;

int main() {

	freopen("input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;
	map.assign(M*N,0);
	int bit = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i*M + j];
			if (map[i*M + j] == 0)	bit++;
		}
	}
	
	for (int i = 0; i < (1 << bit); i++) {
		int count = 0;
		for (int j = 0; j < N*M; j++) {
			if (map[j] == 0 && count < 3) {
				map[j] = 1;
				count++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i*M + j] <<' ';
				
			}
			cout << endl;
		}
	}

}