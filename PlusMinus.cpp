
//https://www.hackerrank.com/challenges/plus-minus/problem

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    cout << fixed << setprecision(6);
    cout << (double)positiveCount / n << endl;
    cout << (double)negativeCount / n << endl;
    cout << (double)zeroCount / n << endl;

    return 0;
}