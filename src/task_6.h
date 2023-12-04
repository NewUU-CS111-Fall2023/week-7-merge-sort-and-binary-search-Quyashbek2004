#include <iostream>
#include <vector>

using namespace std;

vector<int> searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1; // O(1)

    while (low <= high) { // O(log N)
        int mid = low + (high - low) / 2; // O(1)

        if (nums[mid] == target) {
            return {1, mid}; // Found the target
        } else if (nums[mid] < target) {
            low = mid + 1; // Target might be in the right half
        } else {
            high = mid - 1; // Target might be in the left half
        }
    }

    return {-1, low}; // Target not found, return -1 and the index where it should be inserted
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> result = searchInsert(nums, target);
    for (int i = 0; i < result.size(); ++i) { // O(1)
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
//Overall complexity: O(log N)
