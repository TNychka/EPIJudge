#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<vector<int>> AppendPermutations(vector<int> A, int i = 0) {
    if (i > A.size()) {
        return vector<vector<int>>();
    }
    int mixin = A.at(i);
    vector<vector<int>> permutations = AppendPermutations(A, i+1);
    vector<vector<int>> results;
    for (vector<int> v : permutations) {
        for (int j = i; j < A.size(); ++j) {

        }
    }
}

vector<vector<int>> Permutations(vector<int> A) {
    return AppendPermutations(A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "permutations.cc", "permutations.tsv", &Permutations,
      &UnorderedComparator<vector<vector<int>>>, param_names);
}
