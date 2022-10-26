#include <iostream>
#include <string>
#include <string_view>
#include <memory>
#include <algorithm>
#include <algorithm>
#include <memory>

class IStrategy
{
public:
    virtual std::string doAlgorithm(std::string_view data) const = 0;
    virtual ~IStrategy() {}
};

class StrategyA : public IStrategy
{
public:
    std::string doAlgorithm(std::string_view data) const override
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};

class StrategyB : public IStrategy
{
public:
    std::string doAlgorithm(std::string_view data) const override
    {
        std::string result(data);
        std::sort(std::begin(result), std::end(result), std::greater<>());

        return result;
    }
};

class Context
{
private:
    std::unique_ptr<IStrategy> strategy_;

public:
    explicit Context(std::unique_ptr<IStrategy> &&strategy = {}) : strategy_(std::move(strategy))
    {
    }

    void set_strategy(std::unique_ptr<IStrategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }

    void doSomeBusinessLogic() const
    {
        if (strategy_)
        {
            std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            std::string result = strategy_->doAlgorithm("aecbd");
            std::cout << result << "\n";
        }
        else
        {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};

void clientCode()
{
    Context context(std::make_unique<StrategyA>());
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(std::make_unique<StrategyB>());
    context.doSomeBusinessLogic();
}

int main()
{
    clientCode();

    return 0;
}