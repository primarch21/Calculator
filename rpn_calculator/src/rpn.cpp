#include "rpn.h"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>

std::vector<std::string> tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool is_number(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+') {
        if (s.size() == 1) return false;
        start = 1;
    }
    bool has_dot = false;
    for (size_t i = start; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (has_dot) return false;
            has_dot = true;
        } else if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

double evaluate_rpn(const std::string& expression) {
    std::stack<double> stack;
    std::vector<std::string> tokens = tokenize(expression);

    for (const auto& token : tokens) {
        if (is_number(token)) {
            stack.push(std::stod(token));
        } else {
            if (token == "~" || token == "++" || token == "--" || token == "!") {
                if (stack.empty()) {
                    throw std::invalid_argument("Not enough operands for operator '" + token + "'");
                }

                double a = stack.top(); stack.pop();
                double result;

                if (token == "~") {
                    result = -a;  // Унарный минус
                } else if (token == "++") {
                    result = a + 1;  // Инкремент
                } else if (token == "--") {
                    result = a - 1;  // Декремент
                } else if (token == "!") {
                    // Факториал (только для целых неотрицательных чисел)
                    if (a < 0 || std::floor(a) != a) {
                        throw std::invalid_argument("Factorial requires non-negative integer");
                    }
                    result = 1;
                    for (int i = 2; i <= a; ++i) {
                        result *= i;
                    }
                }
                stack.push(result);
            }  else {
                  if (stack.size() < 2) {
                      throw std::invalid_argument("Not enough operands for operator '" + token + "'");
                  }

                  double b = stack.top(); stack.pop();
                  double a = stack.top(); stack.pop();
                  double result;

                  if (token == "+") {
                      result = a + b;
                  } else if (token == "-") {
                      result = a - b;
                  } else if (token == "*") {
                      result = a * b;
                  } else if (token == "/") {
                      if (b == 0.0) {
                          throw std::invalid_argument("Division by zero");
                      }
                      result = a / b;
                  } else if (token == "^") {
                      result = std::pow(a, b);
                  } else {
                    throw std::invalid_argument("Invalid operator: '" + token + "'");
                  }

                  stack.push(result);
            }
        }

        if (stack.size() != 1) {
            throw std::invalid_argument("Invalid expression: too many operands");
        }

        return stack.top();
    }
}
