#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int arr_r[101];
int arr_k[101];



int main(char argc, char*argv) {

	int tc;

	cin >> tc;

	while(tc--){

		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> arr_r[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr_k[i];
		}

		for (int i = 0; i < (1 << n); i++) {

		}

	}

}