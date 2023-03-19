#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    long long n, max_A;
    scanf("%ld %ld", &n, &max_A);
    queue<long long> last_a;
    last_a.push(1);
    if (n == 1) {
        bool need_enter = false;
        for (long long b = 32; true; ++b) {
            long long cur_a = b * b / 1000;
            if (cur_a > max_A) break;
            if (need_enter) printf("\n");
            need_enter = true;
            printf("%ld %ld", cur_a, b);
        }
        if (!need_enter) printf("No Solution.\n");
        return 0;
    }
    bool has_sol = false, need_enter = false;
    for (long long b = 32; true; ++b) {
        long long cur_a = b * b / 1000;
        if (last_a.back() == cur_a - 1) {
            last_a.push(cur_a);
            if (last_a.size() == n) {
                has_sol = true;
                if (need_enter) printf("\n");
                need_enter = true;
                printf("%ld %ld", last_a.front(), b - n + 1);
                last_a.pop();
            }
        } else {
            while (!last_a.empty()) last_a.pop();
            last_a.push(cur_a);
        }
        if (last_a.front() > max_A) break;
    }
    if (!has_sol) printf("No Solution.\n");
    return 0;
}