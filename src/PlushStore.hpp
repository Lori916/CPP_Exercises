#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Plush.hpp"

class PlushStore {
public:
    PlushStore(const std::string& name)
        : name {name}
    {}

    std::string get_name() const {
        return name;
    }

    int get_wealth_amount() const{
        return wealth_amount;
    }

    int get_stock_size() const{
        return stock_size;
    }

    int get_debt_amount() const {
        return debt;
    }

    void loan(const int& value) {
        wealth_amount += value;
        debt += (value + (value/10));
    }

    int make_plush(const int& value) {
        auto cost = 0;
        if(wealth_amount == 0){
            return cost;
        } if(wealth_amount - value < 0){
            cost = wealth_amount;
            wealth_amount = 0;
        } else {
            wealth_amount -= value;
            cost = value;
        }
        stock_size += 1;
        exp += 1;
        cost += exp;
        stock.emplace_back(cost);
        return cost;
    }

    int get_experience() const {
        return exp;
    }

    std::optional<Plush> buy(const int& money) {
        if(stock_size == 0){
            stock.clear();//A Changer !!!!
            return std::nullopt;
        }
        for(auto plush : stock){
            if(plush.get_cost() == money){
                stock_size -= 1;
                wealth_amount += money;
                auto op = std::make_optional(plush);
                return op;
            }
        }
        return std::nullopt;
    }

private:
    std::string name;
    int wealth_amount = 0;
    std::vector<Plush> stock;
    int stock_size = 0;
    int debt = 0;
    int exp = 0;
};