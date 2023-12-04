#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxBeautifulness(int n, vector<int>& Y) {
    int beautifulness = 0;
    for (int i = 0; i < n; ++i) { // O(N)
        beautifulness += abs(Y[i] - (i + 1)); // O(1)
    }

    int maxBeautifulness = beautifulness; // O(1)
    for (int i = 0; i < n; ++i) { // O(N^2)
        for (int j = i + 1; j < n; ++j) { // O(N)
            swap(Y[i], Y[j]); // O(1)
            int newBeautifulness = 0;
            for (int k = 0; k < n; ++k) { // O(N)
                newBeautifulness += abs(Y[k] - (k + 1)); // O(1)
            }
            maxBeautifulness = max(maxBeautifulness, newBeautifulness); // O(1)
            swap(Y[i], Y[j]); // O(1) - revert swap
        }
    }
    return maxBeautifulness;
}

int main() {
    int n;
    cin >> n;

    vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> Y[i];
    }

    int result = maxBeautifulness(n, Y);
    cout << result << endl;

    return 0;
}
//Overall complexity: O(N^3)
