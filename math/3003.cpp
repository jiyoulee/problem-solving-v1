/*
 * Title: BIJELE
 * Link: https://www.acmicpc.net/problem/3003
 */

#include <cstdio>

using namespace std;

constexpr int PIECES_CNT = 6;
constexpr int chess_set[6] = {1, 1, 2, 2, 2, 8};

int piece;

int main(int argc, char** argv) {
	for (int i = 0; PIECES_CNT > i; ++i) {
		scanf("%d", &piece);
		
		printf("%d ", chess_set[i] - piece);
	}

	return 0;
}