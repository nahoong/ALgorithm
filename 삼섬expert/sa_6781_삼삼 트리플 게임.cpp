#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)

using namespace std;


int tf(vector<int> &R) {

	if (R.size() == 0) return 1;
	if (R.size() % 3 != 0 ) return 0;

	int stemp[10] = { 0, };
	int offset = 0;
	int rep = 0;
	int del = 0;
	int i = 0;

	while (i < R.size() - 1) {
		if (R[i] == R[i + 1]) {
			rep++;
			del = i + 1;
		}
		else {
			rep = 0;
		}
		if (rep == 3) {
			R.erase(R.begin() + del - 3, R.begin() + del);
			del = 0;
			rep = 0;
			i = 0;
		}
		i++;
	}


	for (i = 0; i < R.size(); i++) {
		stemp[R[i]]++;
	}

	for (i = 1; i <= 7; i++) {
		if (stemp[i] > 0 && stemp[i] <= 3 && stemp[i + 1] >0 && stemp[i + 1] <= 3 && stemp[i + 2]>0 && stemp[i + 2] <= 3) {
			stemp[i]--;
			stemp[i + 1]--;
			stemp[i + 2]--;
			i--;
			continue;
		}
	}
	for (i = 1; i <= 9; i++) {
		if (stemp[i] == 3) {
			stemp[i] = 0;
		}
	}

	for (i = 1; i <= 9; i++) {
		if (stemp[i] > 0)	return 0;
	}
	
	return 1;
	
}
int main(){

	freopen("6781.txt", "r", stdin);

	int tc;
	cin >> tc;
	char ch;
	int input[9] = { 0, };	//³¡¹®ÀÚ\0
	vector<int> R;
	vector<int> G;
	vector<int> B;
	int ans = 1;
	string Ans[2] = { "Continue", "Win" };

	for (int t = 0; t < tc; t++) {
		
		for (int i = 0; i < 9; i++) {
			scanf("%1d", &input[i]);
		}

		for (int i = 0; i < 9; i++) {
			scanf(" %c", &ch);		//scnaf ÇÑÄ­¶Ù¸é °ø°´ °³Çà ¹«½Ã
			switch (ch){
			case 'B':
				B.push_back(input[i]);
				break;
			case 'G':
				G.push_back(input[i]);
				break;
			case 'R':
				R.push_back(input[i]);
				break;
			default:
				break;
			}
		}

		sort(R.begin(), R.end());
		sort(G.begin(), G.end());
		sort(B.begin(), B.end());

		ans = tf(R) * tf(G) * tf(B);

		cout << "#" << t + 1 << " " << Ans[ans] << endl;
		
		R.clear();
		G.clear();
		B.clear();

		ans = 1;
	}
}