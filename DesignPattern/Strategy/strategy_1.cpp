#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class IStrategy
{
public:
    virtual std::string doAlgorithm(std::string data) = 0;
};

class StrategyA : public IStrategy
{
public:
    std::string doAlgorithm(std::string data)
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};

class StrategyB : public IStrategy
{
public:
    std::string doAlgorithm(std::string data)
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};

template <class T>
class Context
{
private:
    T strategy;
    std::string m_str;

public:
    Context(std::string str) { m_str = str; }
    ~Context() {}

    void Replace()
    {
        std::string result = strategy.doAlgorithm(m_str);
        std::cout << result << "\n";
    }
};

void clientCode()
{
    Context<StrategyA> c1("klfsaahJFIO");
    c1.Replace();
}

int main()
{
    clientCode();
    return 0;
}