/* Bạn được cho 2 số tự nhiên n và k. Bạn hãy tính tổng (1k + 2k + 3k + ... + nk) mod 109 + 7.

Ví dụ:

Với n = 4 và k = 2 thì ta có (12 + 22 + 32 + 42) mod (109 + 7) = 30. */
#include <iostream>

int main() {
    int n = 4;
    int k = 2;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int power = 1;
        for (int j = 1; j <= k; j++) {
            power = (power * i) % (1000000007);
        }
        sum = (sum + power) % (1000000007);
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
