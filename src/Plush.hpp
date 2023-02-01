#pragma once

class Plush{
public:
    Plush(){}

    Plush(const int& cost)
        : cost {cost}
    {}

    int get_cost() const{
        return cost;
    }

    void set_cost(int value) {
        cost = value;
    }

private:
    int cost = 10;
};