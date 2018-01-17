#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		int N, M;
		cin >> N >> M;

		bool M_check[10001] = { true, };
		vector<int> cls;
		cls.push_back(0);   //0먼저 넣고 0 + 어떤것 = 어떤것이니까
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;

			for (int j = 0; j < cls.size(); j++) {
				sum = cls[j] + temp;
				if (sum <= M && !M_check[sum]) {
					M_check[sum] = true;
					cls.push_back(sum);
					Answer = max(Answer, sum);
				}
			}

		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
