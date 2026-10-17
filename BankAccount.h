#pragma once

#include <string>

// A bank account that can never go below zero.
//
// Money is stored as a whole number of cents. Doubles can't represent values
// like 0.10 exactly, and those tiny errors add up, so the class avoids them.
class BankAccount {
public:
    explicit BankAccount(std::string owner, long long openingBalanceCents = 0);

    // Both throw std::invalid_argument if the amount is zero or negative.
    void deposit(long long amountCents);

    // Also throws std::runtime_error if the balance can't cover the amount.
    void withdraw(long long amountCents);

    long long balanceCents() const { return balanceCents_; }
    const std::string& owner() const { return owner_; }

private:
    std::string owner_;
    long long balanceCents_;
};
