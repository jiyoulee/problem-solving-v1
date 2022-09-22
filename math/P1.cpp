/*
 * Platform: Programmers
 * Title: K진수에서 소수 개수 구하기
 */

#include <string>
#include <vector>

using namespace std;

constexpr int MAX_N = 13;

int solution(int n, int k) {
    int answer = 0;
    long long int temp = 0;
    int digit[MAX_N] = {0};
    
    /*
     * Convert into k-base number.
     */
    for (int i = 12; i >= 0 && 0 != n; --i) {
        digit[i] = n % k;
        n /= k;
    }
    
    /*
     * Count prime numbers.
     */
    for (int i = 0; MAX_N >= i; ++i) {
        /*
         * Determine if number is prime.
         */
        if (0 == digit[i] || MAX_N == i) {
            if (1 < temp) {
                int is_valid = true;
                
                for (long long int j = 2; temp >= j * j; ++j) {
                    if (0 == temp % j) {
                        is_valid = false;
                        break;
                    }
                }
                
                if (is_valid) {
                    ++answer;
                }
            }
            
            temp = 0;
            continue;
        }
        
        /*
         * Create number.
         */
        temp *= 10;
        temp += digit[i];
    }
    
    return answer;
}