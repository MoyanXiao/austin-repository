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

    int calculate(std::string input);

    double getResult();

    std::string getResultMsg();

private:
    /* data */
    std::stack<double> _stack;
    std::map<char, std::function<double(double,double)> > _opMap;

private:
    bool validate(std::string);
};


#endif /* end of include guard: POSTFIXCALCULATOR_H */
