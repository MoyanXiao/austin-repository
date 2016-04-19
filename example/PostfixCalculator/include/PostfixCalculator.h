#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <string>
#include <map>
#include <stack>
#include <functional>


class PostfixCalculator 
{
public:
    PostfixCalculator();
    ~PostfixCalculator();

    double calculate(const std::string& input);
    bool calculate_noexception(const std::string& input, double& result) noexcept;
private:
    /* data */
    std::stack<double> _stack;
    std::map<char, std::function<double(double,double)> > _opMap;

private:
    void validate(std::string&);
    double popStack();
    double popResult();
};


#endif /* end of include guard: POSTFIXCALCULATOR_H */
