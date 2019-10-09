#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
    double best = 0.0;
    double min = std::numeric_limits<double>::max();
    for (double price : prices) {
        if (price < min) {
            min = price;
        } else if (price - min > best) {
            best = price - min;
        }
    }
    return best;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
