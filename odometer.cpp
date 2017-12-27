
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cassert>

/*
* This should be divided into sub cases, limited by number of digits. Each sub case will take constant time.
* So we can construct the numbers like the solution below.
* I think another way to solve this is using permutation to compute the number of possible numbers.
* Limit the number generated by number of digits (3 < a < 17)
* Remove the numbers out of range at the beginning and at the end that are out of range. This should be an easy task. 
*/
using namespace std;

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);

	long long X, Y;
	cin >> X >> Y;

	int result = 0;
	for (int sz = 3; sz <= 17; sz++) {
		for (int d0 = 0; d0 < 10; d0++) {
			string S(sz, '0' + d0);
			for (int d1 = 0; d1 < 10; d1++) {
				if (d0 == d1) continue;

				for (int i = 0; i < sz; i++) {
					S[i] = '0' + d1;

					long long num = atoll(S.c_str());
					if (S[0] != '0' && X <= num && num <= Y) {
						++result;
					}

					S[i] = '0' + d0;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}