#include<cassert>
#include<vector>
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

int n, m;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	// ���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�
	int firstFree = -1;
	for (int i = 0; i < (n); i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	// ���� ���: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = (firstFree + 1); pairWith < (n); pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
/**/

int main() {

	freopen("input.txt", "r", stdin);
	int cases;
	cin >> cases;
	while (cases--) {
		cin >> n >> m;
		assert(n <= 10);
		memset(areFriends, 0, sizeof(areFriends));
		for (int i = 0; i < (m); i++) {
			int a, b;
			cin >> a >> b;
			assert(0 <= a && a < n && 0 <= b && b < n);
			assert(!areFriends[a][b]);
			areFriends[a][b] = areFriends[b][a] = true;
		}
		bool taken[10];
		memset(taken, 0, sizeof(taken));
		cout << countPairings(taken) << endl;
	}
}
