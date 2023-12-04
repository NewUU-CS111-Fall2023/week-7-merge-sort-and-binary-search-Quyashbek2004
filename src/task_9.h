#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1; // O(1)

    while (low <= high) { // O(log n)
        int mid = low + (high - low) / 2; // O(1)

        // Calculate the number of missing elements until 'mid' index
        int missing = arr[mid] - (mid + 1); // O(1)

        if (missing >= k) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    // At the end, 'low' represents the count of present elements
    // So, the k-th missing positive integer is k + low
    return k + low; // O(1)
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findKthPositive(arr, k);
    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1; // O(1)

    while (low <= high) { // O(log n)
        int mid = low + (high - low) / 2; // O(1)

        // Calculate the number of missing elements until 'mid' index
        int missing = arr[mid] - (mid + 1); // O(1)

        if (missing >= k) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    // At the end, 'low' represents the count of present elements
    // So, the k-th missing positive integer is k + low
    return k + low; // O(1)
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findKthPositive(arr, k);
    cout << result << endl;

    return 0;
}
//Overall complexity: O(log n)
