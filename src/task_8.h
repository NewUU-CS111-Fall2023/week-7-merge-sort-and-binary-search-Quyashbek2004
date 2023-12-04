#include <iostream>
#include <vector>

using namespace std;

vector<int> missingNumber(int n, vector<int>& nums) {
    vector<int> result; // O(1)

    // Create a vector to mark the presence of each number in the range [0, n]
    vector<bool> found(n + 1, false); // O(n)

    for (int num : nums) { // O(n)
        found[num] = true;
    }

    // Check for missing numbers in the range [0, n]
    for (int i = 0; i <= n; ++i) { // O(n)
        if (!found[i]) {
            result.push_back(i); // Store missing numbers
        }
    }

    return result; // O(1)
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = missingNumber(n, nums);
    for (int i = 0; i < result.size(); ++i) { // O(1)
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
//Overall complexity: O(n)
