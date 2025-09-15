#include "myLibrary.hpp"

void rotateList(std::vector<char>& a, int k) {
    int n = static_cast<int>(a.size()); // Cast to int since .size() for containers like std::vector returns unsigned integer type

    // Edge case: List is size 0 or 1
    if (n <= 1) {
        return;
    }

    // Normalize k to [0, n)
    k %= n;
    if (k < 0) k += n;   // only needed if negatives are possible
    if (k == 0) return;

    // Shift k times
    while (k != 0) {
        char temp = a[n - 1]; // Temporarily stores last character in vector
        // Shift each character over once
        for (int i = n - 1; i > 0; --i) {
            a[i] = a[i - 1];
        }
        a[0] = temp; // Move last character to front
        --k;
    }

    
}

bool isPalindrome(const std::vector<char>& a) { // Pass by By const reference to avoid copying and promise not to change vector

    for (int i = 0, j = (int)a.size() - 1; i < j; ++i, --j) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}