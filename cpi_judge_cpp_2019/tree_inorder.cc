#include <memory>
#include <vector>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

void BuildInorderedTraversal(const unique_ptr<BinaryTreeNode<int>> &tree, vector<int>& result) {
    if (!tree) {
        return;
    }
    BuildInorderedTraversal(tree->left, result);
    result.push_back(tree->data);
    BuildInorderedTraversal(tree->right, result);
}

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>> &tree) {
    vector<int> result;
    BuildInorderedTraversal(tree, result);
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}
