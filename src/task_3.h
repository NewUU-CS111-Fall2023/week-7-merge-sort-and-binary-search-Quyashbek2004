#include <iostream>
#include <vector>

using namespace std;

void mergeArrays(int N, int M, vector<int>& A, vector<int>& B) {
    vector<int> merged(N + M); // O(N+M)
    int i = 0, j = 0, k = 0;

    while (i < N && j < M) { // O(N+M)
        if (A[i] >= B[j]) { // O(1)
            merged[k++] = A[i++]; // O(1)
        } else {
            merged[k++] = B[j++]; // O(1)
        }
    }

    while (i < N) { // O(N)
        merged[k++] = A[i++]; // O(1)
    }

    while (j < M) { // O(M)
        merged[k++] = B[j++]; // O(1)
    }

    // Printing the merged array in non-increasing order
    for (int l = N + M - 1; l >= 0; --l) { // O(N+M)
        cout << merged[l] << " "; // O(1)
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        mergeArrays(N, M, A, B);
    }

    return 0;
}
//Overall complexity: O(N + M)
