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

int PostfixCalculator::calculate(std::string input) {
    std::istringstream ss(input);
    std::vector<std::string> list;
    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::back_inserter(list));
    for ( auto &iter : list) {
        if( iter.size() == 1) {
            auto op = _opMap.find(iter.at(0));
            if (op != _opMap.end()) {
                double a, b;
                if ( _stack.empty() ) 
                    return 2;
                else 
                    b = _stack.top();
                _stack.pop();
                if ( _stack.empty() ) 
                    return 2;
                else 
                    a = _stack.top();
                _stack.pop();
                _stack.push((op->second)(a, b));
                continue;
            }
        }
        if (!validate(iter)) {
            return 1;
        }
    }
    return 0;
}

double PostfixCalculator::getResult() {
    return _stack.top();
}

std::string PostfixCalculator::getResultMsg() {
    return "success";
}

bool PostfixCalculator::validate(std::string a) {
    std::string::size_type sz;
    double val = std::stod(a, &sz);
    if ( sz != a.size() ) return false;
    _stack.push(val);
    return true;
}
