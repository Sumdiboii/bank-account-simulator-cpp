#include "BankAccount.h"

#include <stdexcept>
#include <utility>

BankAccount::BankAccount(std::string owner, long long openingBalanceCents)
    : owner_(std::move(owner)), balanceCents_(openingBalanceCents) {
    if (owner_.empty()) {
        throw std::invalid_argument("Account owner name cannot be empty.");
    }
    if (balanceCents_ < 0) {
        throw std::invalid_argument("Opening balance cannot be negative.");
    }
}

void BankAccount::deposit(long long amountCents) {
    if (amountCents <= 0) {
        throw std::invalid_argument("Deposit must be greater than zero.");
    }
    balanceCents_ += amountCents;
}

void BankAccount::withdraw(long long amountCents) {
    if (amountCents <= 0) {
        throw std::invalid_argument("Withdrawal must be greater than zero.");
    }
    if (amountCents > balanceCents_) {
        throw std::runtime_error("Insufficient funds.");
    }
    balanceCents_ -= amountCents;
}
