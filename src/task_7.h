#include <iostream>

using namespace std;

int recursivePow(int x, int n) {
    if (n == 0) {
        return 1;
    }

    int temp = recursivePow(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

int main() {
    int x, n;
    cin >> x;

    n = 2 * x; // Sample input has only one number, considering it as 'n'

    int result = recursivePow(x, n);
    cout << result << endl;

    return 0;
}
//Overall complexity: O(log n)
