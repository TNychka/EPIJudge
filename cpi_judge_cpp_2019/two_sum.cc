#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;

// Can also be done as a set
bool HasTwoSum(vector<int>& A, int t) {
    std::sort(A.begin(), A.end());
    int i = 0;
    int j = A.size() - 1;
    while (i <= j) {
        int sum = A[i] + A[j];
        if (sum == t) {
            return true;
        } else if (sum < t) {
            i += 1;
        } else {
            j -= 1;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "two_sum.cc", "two_sum.tsv", &HasTwoSum,
                         DefaultComparator{}, param_names);
}
