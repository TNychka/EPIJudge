#include <unordered_map>
#include "test_framework/generic_test.h"

std::unordered_map<int, int> fib;

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n < 3) {
        return 1;
    }
    if (fib.find(n) != fib.end()) {
        return fib[n];
    }
    int seq = Fibonacci(n - 1) + Fibonacci(n - 2);
    fib[n] = seq;
    return seq;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "fibonacci.cc", "fibonacci.tsv", &Fibonacci,
                         DefaultComparator{}, param_names);
}
