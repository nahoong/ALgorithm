#include<iostream>
#include<map>
#include<string>

#pragma warning(disable:4996)
using namespace std;

char Imap[4][4];
map<string, bool> code;
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };
bool bound(int i, int j) {
	return (i >= 0 && i < 4 && j >= 0 && j < 4);
}
void dfs(int i, int j, string str, int length) {
	if (length == 1) {
			if (!code[str]){
			code[str] = true;
			//cout << str << endl;
			}
		return;
	}
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if (bound(ni, nj)) {
			dfs(ni, nj, str + Imap[ni][nj], length - 1);
		}
	}
}
int main() {
	freopen("input_2819.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {


		memset(Imap, '-', sizeof(Imap));

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> Imap[i][j];
			}
		}
		
		string str;
		code.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				str = "";
				dfs(i, j, str + Imap[i][j], 7);
			}
		}

		cout << "#" << t << " " << code.size() << endl;

	}
}

