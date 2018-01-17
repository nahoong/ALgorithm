#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int arr[21][21];
int permu[21] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };


int main(char argc, char*argv) {

	freopen("input.txt", "r", stdin);

	int tc;

	cin >> tc;

	while (tc--) {

		cin >> n;

	/*	for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
	*/
		int min_p = 9999999999;
		do {
			for (int i = 0; i < n; i++) {
				cout << permu[i+1] << ",";
			}
			cout << endl;
		} while (next_permutation(permu+1,permu+n+1));

		cout << "------------------------------------" << endl;


		for (int i = 0; i < (1 << n); i++) {
			cout <<  int(1&(1 << i) ? 1:0  )<< ".";
		}
		cout << endl;
		for (int i = 0; i < (1 << n); i++) {
			cout << int(1 | i) << ".";
		}
		cout << endl;



	}

}