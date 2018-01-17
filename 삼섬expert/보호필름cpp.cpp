#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int Answer;
vector<vector<int> > film;
int D, W, K;

bool judgement() {
	int cnt;
	for (int w = 0; w < W; w++) {
		cnt = 1;
		for (int d = 1; d < D; d++) {
			if (film[d][w] == film[d - 1][w]) {
				cnt++;
				if (cnt >= K) break;
			}
			else {
				cnt = 1;
			}
		}
		if (cnt < K) {
			return false;
		}
	}
	//cout << endl;
	//for (int w = 0; w < D; w++) {
	//	for (int d = 1; d < W; d++) {
	//		cout << film[w][d] << " / ";
	//	}
	//	cout << endl;
	//}
	return true;
}
void dfs(int d,int deep) {

	if (deep > Answer)
		return;
	//cout << "safety index = " << judge <<"deep = " << deep << endl;
	if (d == D)
		if( judgement() ) {
		Answer = min(Answer, deep);
		return;
	}
	if (d > D - 1)	return;
	else {
		vector<int> temp(W);
		copy(film[d].begin(), film[d].end(), temp.begin());
		dfs(d + 1, deep);

		film[d].assign(W, 0);
		dfs(d + 1, deep + 1);

		film[d].assign(W, 1);
		dfs(d + 1, deep + 1);

		copy(temp.begin(), temp.end(), film[d].begin());
	}

	

}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {

		
		cin >> D >> W >> K;
		film.assign(D,vector<int>(W,-1));
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}

		Answer = D + 1;
		dfs(0,0);



		cout << "#" << t+1 << " ";
		cout << Answer << endl;
	}

	return 0;
}