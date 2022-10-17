/*
 * Title: 수 정렬하기 2
 * Link: https://www.acmicpc.net/submit/2751/50661389
 */

#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000000;

int N;
int arr[MAX_N];

int main(int argc, char** argv) {
	scanf("%d", &N);
	for (int i = 0; N > i; ++i) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; N > i; ++i) {
		printf("%d\n", arr[i]);
	}

	return 0;
}