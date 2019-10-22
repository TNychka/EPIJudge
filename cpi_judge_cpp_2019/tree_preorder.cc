#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

using std::vector;

void BuildPreorderedTraversal(const unique_ptr<BinaryTreeNode<int>> &tree, vector<int>& result) {
    if (!tree) {
        return;
    }
    result.push_back(tree->data);
    BuildPreorderedTraversal(tree->left, result);
    BuildPreorderedTraversal(tree->right, result);
}

vector<int> PreorderTraversal(const unique_ptr<BinaryTreeNode<int>> &tree) {
    vector<int> result;
    BuildPreorderedTraversal(tree, result);
    return result;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"tree"};
    return GenericTestMain(args, "tree_preorder.cc", "tree_preorder.tsv",
                           &PreorderTraversal, DefaultComparator{}, param_names);
}
