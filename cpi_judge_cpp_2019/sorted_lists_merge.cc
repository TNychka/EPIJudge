#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {

    if (L1 == nullptr) {
        return L2;
    } else if (L2 == nullptr) {
        return L1;
    }

    shared_ptr<ListNode<int>> newListHead;
    if (L1->data <= L2->data) {
        newListHead = L1;
        L1 = L1->next;
    } else {
        newListHead = L2;
        L2 = L2->next;
    }

    shared_ptr<ListNode<int>> newListEnd = newListHead;
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data <= L2->data) {
            newListEnd->next = L1;
            L1 = L1->next;
        } else {
            newListEnd->next = L2;
            L2 = L2->next;
        }
        newListEnd = newListEnd->next;
    }

    if (L1 == nullptr) {
        newListEnd->next = L2;
    } else {
        newListEnd->next = L1;
    }
    return newListHead;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
