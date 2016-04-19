#include "PostfixCalculator.h"
#include <vector>
#include <iterator>
#include <sstream>


PostfixCalculator::PostfixCalculator() {
    _opMap.insert(std::make_pair('+', [](double a, double b){ return a + b;}));
    _opMap.insert(std::make_pair('-', [](double a, double b){ return a - b;}));
    _opMap.insert(std::make_pair('*', [](double a, double b){ return a * b;}));
    _opMap.insert(std::make_pair('/', [](double a, double b){ return a / b;}));
}

PostfixCalculator::~PostfixCalculator() {
    _opMap.clear();
    while (!_stack.empty()) {
        _stack.pop();
    }
}

double PostfixCalculator::calculate(const std::string& input) {
    while (!_stack.empty()) {
        _stack.pop();
    }
    std::istringstream ss(input);
    std::vector<std::string> list;
    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::back_inserter(list));
    for ( auto &iter : list) {
        if( iter.size() == 1) {
            auto op = _opMap.find(iter.at(0));
            if (op != _opMap.end()) {
                double a, b;
                b = popStack();
                a = popStack();
                _stack.push((op->second)(a, b));
                continue;
            }
        }
        validate(iter);
    }
    return popResult();
}

bool PostfixCalculator::calculate_noexception(const std::string& input, double& ret) noexcept{
    try {
        ret = calculate(input);
        return true;
    } catch(std::invalid_argument& e) {
        return false;
    } catch(...) {
        return false;
    }
}

void PostfixCalculator::validate(std::string& a) {
    std::string::size_type sz;
    double val = std::stod(a, &sz);
    if ( sz != a.size() ) {
        throw std::invalid_argument(a);
    }
    _stack.push(val);
}

double PostfixCalculator::popStack() {
    if (_stack.empty()) {
        throw std::invalid_argument("No value in stack");
    }
    auto ret = _stack.top();
    _stack.pop();
    return ret;
}

double PostfixCalculator::popResult() {
    auto ret = popStack();
    if (!_stack.empty()) {
        throw std::invalid_argument("no empty stack when popResult");
    }
    return ret;
}
