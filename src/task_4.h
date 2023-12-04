#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<int, vector<int>, greater<int>> minHeap; // O(1)

    for (int i = 0; i < n; ++i) { // O(n)
        for (int j = 0; j < n; ++j) { // O(n)
            minHeap.push(matrix[i][j]); // O(log k)
        }
    }

    while (k > 1) { // O(k * log k)
        minHeap.pop(); // O(log k)
        k--;
    }

    return minHeap.top(); // O(1)
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
//Overall complexity: O(n^2 * log k)
