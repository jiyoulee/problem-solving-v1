/*
 * Title: 2007년
 * Link: https://www.acmicpc.net/problem/1924
 */

#include <cstdio>

using namespace std;

constexpr int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
constexpr char days_of_week[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int month, day;

int main() {
    scanf("%d%d", &month, &day);
    
    /*
     * Convert date to order of days.
     */
    for (int i = 0; month > i; ++i) {
        day += months[i];
    }
    
    /*
     * Get day of week.
     */
    printf("%s", days_of_week[day % 7]);
    
    return 0;
}