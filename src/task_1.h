#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate remaining sum after operations
void remainingSumAfterOperations(int T, vector<pair<int, vector<int>>>& testCases) {
    for (int test = 0; test < T; ++test) {
        int N = testCases[test].first;
        vector<int>& arr = testCases[test].second;

        vector<int> medians;
        for (int i = 0; i < N - 2; ++i) { // O(N)
            vector<int> subarray(arr.begin() + i, arr.begin() + i + 3); // O(1) - slicing
            if (subarray.size() % 2 != 0) {
                sort(subarray.begin(), subarray.end()); // O(1) - small size sorting
                medians.push_back(subarray[1]); // O(1)
            }
        }

        sort(medians.begin(), medians.end()); // O(KlogK) - K is the number of medians

        int minMedian = (medians.size() > 0) ? medians[0] : *min_element(arr.begin(), arr.end()); // O(N) - finding min

        arr.erase(find(arr.begin(), arr.end(), minMedian)); // O(N) - removing element

        int remainingSum = 0;
        for (int num : arr) { // O(N)
            remainingSum += num;
        }
        cout << remainingSum << endl;
    }
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, vector<int>>> testCases;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }
        testCases.push_back({ N, arr });
    }

    remainingSumAfterOperations(T, testCases);

    return 0;
}
//Overall complexity: O(T * N^2 + T * NlogN)
/*
 * Author:
 * Date:
 * Name:
 */
