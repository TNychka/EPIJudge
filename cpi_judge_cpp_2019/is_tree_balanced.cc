#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
struct BalancedHeight {
    int depth;
    bool balanced;
};

BalancedHeight IsBalancedWithHeight(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (tree == nullptr) {
        return {-1, true};
    }
    const BalancedHeight& right = IsBalancedWithHeight(tree->right);
    if (!right.balanced) {
        return {-1, false};
    }
    const BalancedHeight& left = IsBalancedWithHeight(tree->left);
    if (!left.balanced) {
        return {-1, false};
    }

    int depth = std::max(right.depth, left.depth) +  1;
    bool balanced = std::abs(right.depth - left.depth) <= 2;
    return {depth, balanced};
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    return IsBalancedWithHeight(tree).balanced;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
