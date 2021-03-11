#include <bits/stdc++.h>
using namespace std;

int N, slen, ans, i;
char tmp;
char S[101];
bool locked[26];

int main() {
	scanf("%d", &N);
	
	/*
	 * Assume, at first, that all words are group words.
	 */
	ans = N;
	
	/*
	 * Then, check each word to see if it actually is a group word.
	 */
	while (N--) {
		scanf("%s", S);
		
		i = 0;
		slen = strlen(S);
		
		while (i < slen) {
			tmp = S[i];
			
			/*
			 * Since a string composed of the current character has already been noted, the word is not a group word.
			 * So, decrement the group word count, and move on to the next word.
			 */
			if (locked[tmp - 'a']) {
				ans--;
				break;
			}
			
			/*
			 * The word may be, or may not be, a group word.
			 * So, note the appearance of the current character string, and then find the start next new character string.
			 */
			while (tmp == S[i]) {		
				i++;
			}
			locked[tmp - 'a'] = true;
		}
		
		/*
		 * (Reset global variables.)
		 */
		fill(locked, locked + 26, false);
	}
	
	printf("%d", ans);
	
	return 0;
}