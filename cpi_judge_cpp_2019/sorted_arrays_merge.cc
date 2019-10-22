#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"

using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
    if (b.empty()) {
        return true;
    } else if (a.empty()) {
        return false;
    }
    return a.back() < b.back();
}

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    vector<int> results;
    vector<vector<int>> heap;
    heap.reserve(sorted_arrays.size());
    for (const vector<int>& array : sorted_arrays) {
        heap.push_back(array);
    }
    make_heap(heap.begin(), heap.end(), comparator);

    while (!heap.empty()) {
        pop_heap(heap.begin(), heap.end(), comparator);
        vector<int>& top = heap.back();
        results.push_back(top.back());
        top.pop_back();
        if (!top.empty()) {
            push_heap(heap.begin(), heap.end(), comparator);
        } else {
            heap.pop_back();
        }
    }
    reverse(results.begin(), results.end());
    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
