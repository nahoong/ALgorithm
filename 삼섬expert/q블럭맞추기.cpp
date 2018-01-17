#include <iostream>
#include <stdlib.h>

#define MAX 30000

using namespace std;

extern int makeBlock(int module[][4][4]);

int main(void)
{
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}
int makeBlock(int module[][4][4]) {
	for (int a = 0; a < MAX; a++) {
		for (int b = a+1; b < MAX; b++) {
			if (a == b)	continue;
			int max_sum = 0;
			int sum1 = module[a][0][0]+module[b][0][3];
			for (int i = 0; i < 16; i++) {
				if (sum1 != module[a][i / 4][i % 4] + module[b][i / 4][3 - (i % 4)]) {
					sum1 = -1;
					break;
				}
			}
			if (max_sum < sum1) {
				max_sum = sum1;
			}
			int sum2 = module[a][0][0] + module[b][3][3];
			for (int i = 0; i < 16; i++) {
				if (sum2 != module[a][i / 4][i % 4] + module[b][3 - (i % 4)][3 - (i / 4)]) {
					sum2 = -1;
					break;
				}
			}
			if (max_sum < sum2) {
				max_sum = sum2;
			}
			int sum3 = module[a][0][0] + module[b][3][0];
			for (int i = 0; i < 16; i++) {
				if (sum2 != module[a][i / 4][i % 4] + module[b][3 - (i / 4)][i % 4]) {
					sum3 = -1;
					break;
				}
			}
			if (max_sum < sum3) {
				max_sum = sum3;
			}
			int sum4 = module[a][0][0] + module[b][0][0];
			for (int i = 0; i < 16; i++) {
				if (sum2 != module[a][i / 4][i % 4] + module[b][i % 4][i / 4]) {
					sum4 = -1;
					break;
				}
			}
			if (max_sum < sum4) {
				max_sum = sum4;
			}
		}
	}
}
