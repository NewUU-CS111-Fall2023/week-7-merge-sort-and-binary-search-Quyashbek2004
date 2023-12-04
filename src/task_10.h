#include <iostream>

using namespace std;

int kthFactor(int n, int k) {
    int countFactors = 0; // Initialize count of factors to 0

    for (int i = 1; i <= n; ++i) { // Iterate from 1 to n
        if (n % i == 0) { // If 'i' is a factor of 'n'
            ++countFactors; // Increment count of factors

            if (countFactors == k) { // If count reaches k
                return i; // Return the kth factor
            }
        }
    }

    return -1; // If less than k factors are found
}

int main() {
    int n, k;
    cin >> n >> k;

    int result = kthFactor(n, k);
    cout << result << endl;

    return 0;
}
