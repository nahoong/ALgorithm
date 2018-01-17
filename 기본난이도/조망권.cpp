#include<iostream>
#include<algorithm>
#include<vector>

#pragma warning(disable:4996)
using namespace std;
int n;
int apt[1002] = { 0, };
int main(int argc, char* argv) {

	freopen("input.txt", "r", stdin);
	int tc = 10;
	int tcc = tc;
	while (tc--) {
		int ans = 0;
		int view,view1,view2;
		cin >> n;
		for(int i = 2 ; i < n+2 ; i++){
			cin >> apt[i];
		}

		for (int i = 2; i < n + 2; i++) {
			view1 = min(apt[i] - apt[i + 1], apt[i] - apt[i - 1]);
			view2 = min(apt[i] - apt[i + 2], apt[i] - apt[i - 2]);
			view = min(view1, view2);
			if (view > 0) {
				ans += view;
			}
		}

		cout << "#" << tcc - tc << " " << ans << endl;
	}
}