#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
    bool isNeg = x < 0;
    string newString = "";
    while(true) {
        newString += std::to_string(abs(x%10));
        x /= 10;
        if (x == 0) {
            break;
        }
    }
    std::reverse(newString.begin(), newString.end());
    return isNeg ? "-" + newString : newString;
}
int StringToInt(const string& s) {
    int i = 0;
    bool isNeg = false;
    if (s[i] == '-') {
        i += 1;
        isNeg = true;
    }

    int result = 0;
    for (; i < s.length(); ++i) {
        result *= 10;
        result += (s[i] - '0');
    }
    return isNeg ? result * -1 : result;
}
void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
