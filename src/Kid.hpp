#pragma once
#include <string>
#include <ostream>
#include "Plush.hpp"
#include "PlushStore.hpp"

class Kid {
public:
    Kid(const std::string& name, const int& money)
        : name {name}, money {money}
    {}

    std::string get_name() const {
        return name;
    }

    int get_money() const {
        return money;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Kid& kid){
        stream << kid.name << " has " << kid.money << " euros.";
        return stream;
    }

    void buy_plush(PlushStore& plushstore){
        std::optional<Plush> op = plushstore.buy(money);
        if(op == std::nullopt){
            return;
        }
        auto plush = op.value();
        money -= plush.get_cost();
        nb_plush += 1;
    }

private:
    std::string name;
    int money;
    int nb_plush = 0;
};