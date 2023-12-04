#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency; // O(1)
    for (int num : nums) { // O(N)
        frequency[num]++;
    }

    priority_queue<pair<int, int>> maxHeap; // O(1)
    for (auto& pair : frequency) { // O(U * log k)
        maxHeap.push({pair.second, pair.first});
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    vector<int> result; // O(1)
    while (!maxHeap.empty()) { // O(k * log k)
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result; // O(k)
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    vector<int> result = topKFrequent(nums, k);
    for (int i = 0; i < k; ++i) { // O(k)
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
//Overall complexity: O(N + U * log k + k * log k)
