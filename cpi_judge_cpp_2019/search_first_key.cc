#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

// 1 2 3 4 4 5
// 0 1 2 3 4 5
int SearchFirstOfK(const vector<int> &A, int k) {
    if (A.empty()) {
        return -1;
    }

    int l = 0, u = A.size() - 1;
    while (l < u) {
        int m = l + (u - l) / 2;
        if (A[m] > k) {
            u = m - 1;
        } else if (A[m] == k) {
            u = m;
        } else {
            l = m + 1;
        }
    }
    return A[l] == k ? l : -1;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"A", "k"};
    return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                           &SearchFirstOfK, DefaultComparator{}, param_names);
}
