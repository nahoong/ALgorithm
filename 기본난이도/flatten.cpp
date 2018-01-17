#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int flt[100];
int n;

int dif(int* arr,int dump) {
	sort(arr, arr + 100);

	int ret;
	ret = arr[99] - arr[0];
	if (dump == 0) return ret;
	if (ret > 1) {
		arr[99] = arr[99]-1;
		arr[0] = arr[0]+1;
		dif(arr, dump - 1);
	}
	else {
		return ret;
	}
	

}
int main(int argc, char** argv) {

	freopen("input.txt", "r", stdin);
	int tc = 10;
	//cin >> tc;
	while (tc--) {

		cin >> n;

		for (int i = 0; i < 100; i++) {
			cin >> flt[i];
		}
		
		cout << "#" << 10 - tc << " " << dif(flt, n) << endl;

	}
}