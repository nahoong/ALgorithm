#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K, A, B;
vector<int> reception;
vector<int> repair;
vector<int> a;
vector<int> b;
vector<int> t;
vector<int> wait1;
vector<int> Answer1;
vector<int> Answer2;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> M >> K >> A >> B;
		reception.assign(N + 1, 1);
		repair.assign(M + 1, 1);
		a.assign(N+1,0);
		b.assign(M+1,0);
		t.assign(K+1,0);
		
		
		
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
		}
		for (int j = 1; j <= M; j++) {
			cin >> b[j];
		}
		for (int k = 1; k <= K; k++) {
			cin >> t[k];
		}
		int max_time = t[K];
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int  time = 0;
		while (max_time--) {
			for (int i = 0; i < K; i++) {
				if (t[i] == time) {
					wait1.push_back(i);
				}
			}
			for (int i = 1; i <= reception.size(); i++) {
				if (reception[i] == 1) {
					reception[i] = 0;
					if (i == A) {
						Answer1.push_back(wait1.at(0));
					}
					wait1.erase(wait1.begin());
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