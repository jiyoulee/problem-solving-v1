/*
 * Title: Tongues
 * Link: https://www.acmicpc.net/problem/4446
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cctype>

using namespace std;

constexpr int MAX_STR_LENGTH = 100;
constexpr int VOWELS_CNT = 6;
constexpr int CONSONANTS_CNT = 20;
constexpr char vowels[VOWELS_CNT] = {'a', 'i', 'y', 'e', 'o', 'u'};
constexpr char consonants[CONSONANTS_CNT] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

string str;
int str_length;
char c;
char str_lower[1 + MAX_STR_LENGTH];
unordered_map<char, int> m;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
     * Map alphabet character to index.
     */
    for (int i = 0; VOWELS_CNT > i; ++i) {
        m[vowels[i]] = i;
    }
    for (int i = 0; CONSONANTS_CNT > i; ++i) {
        m[consonants[i]] = i;
    }

    /*
     * Get and decode encrypted mesage line by line.
     */
    while (getline(cin, str)) {
        for (int i = 0, str_length = str.size(); str_length > i; ++i) {
            c = tolower(str[i]);

            if (islower(c)) {
                switch (c) {
                    case 'a':
                    case 'i':
                    case 'y':
                    case 'e':
                    case 'o':
                    case 'u':
                        c = vowels[(m[c] + 3) % VOWELS_CNT];
                        break;
                    default:
                        c = consonants[(m[c] + 10) % CONSONANTS_CNT];
                        break;
                }
            }

            cout << (isupper(str[i]) ? (char)toupper(c) : c);
        }
        cout << "\n";
    }

    return 0;
}