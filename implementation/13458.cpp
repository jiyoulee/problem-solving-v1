#include <cstdio>
#include <cmath>

using namespace std;

constexpr int MAX_N = 1000000;

long long int answer;
int N, B;
double C;
int A[MAX_N];

int main(int argc, char** argv) {
	/*
	 * Get input.
	 */
	scanf("%d", &N);
	for (int i = 0; N > i; ++i) {
		scanf("%d", &A[i]);
	}
	scanf("%d%lf", &B, &C);

	/*
	 * Account for all primary proctors.
	 */
	answer = N;

	/*
	 * Account for all secondary proctors.
	 */
	for (int i = 0; N > i; ++i) {
		if (B >= A[i]) {
			continue;
		}

		answer += ceil((A[i] - B) / C);
	}

	printf("%lld", answer);

	return 0;
}