#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include "BankAccount.h"

namespace {

constexpr int kDeposit = 1;
constexpr int kWithdraw = 2;
constexpr int kCheckBalance = 3;
constexpr int kExit = 4;

// Upper limit on a single transaction, so converting to cents can't overflow.
constexpr double kMaxAmount = 1'000'000'000.0;

std::string formatMoney(long long cents) {
    std::ostringstream out;
    out << '$' << cents / 100 << '.' << std::setw(2) << std::setfill('0') << cents % 100;
    return out.str();
}

void discardRestOfLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "\n1. Deposit\n"
              << "2. Withdraw\n"
              << "3. Check balance\n"
              << "4. Exit\n";
}

// Returns the menu number the user typed, or 0 if it wasn't a number.
// If the input stream is closed (Ctrl+D), treat it as a request to exit.
int promptForChoice() {
    std::cout << "\nChoose an option: ";
    int choice = 0;
    if (!(std::cin >> choice)) {
        if (std::cin.eof()) {
            return kExit;
        }
        std::cin.clear();
        discardRestOfLine();
        return 0;
    }
    discardRestOfLine();
    return choice;
}

// Keeps asking until the user types a number, then returns it in cents.
// Negative or zero amounts are allowed through on purpose: BankAccount is
// responsible for rejecting them, so the rule lives in one place.
long long promptForAmountCents(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        double amount = 0.0;
        if (std::cin >> amount && std::isfinite(amount) && std::abs(amount) <= kMaxAmount) {
            discardRestOfLine();
            return std::llround(amount * 100);
        }
        if (std::cin.eof()) {
            throw std::runtime_error("Input ended unexpectedly.");
        }
        std::cin.clear();
        discardRestOfLine();
        std::cout << "Please enter a valid amount.\n";
    }
}

}  // namespace

int main() {
    std::cout << "=== Simple Bank ===\n";

    std::string name;
    while (name.empty() && std::cin) {
        std::cout << "Account holder name: ";
        std::getline(std::cin, name);
    }
    if (name.empty()) {
        std::cout << "\nNo name given. Exiting.\n";
        return 1;
    }

    BankAccount account(name);
    std::cout << "\nWelcome, " << account.owner() << ". Your account is open with "
              << formatMoney(account.balanceCents()) << ".\n";

    bool running = true;
    while (running) {
        printMenu();

        try {
            switch (promptForChoice()) {
                case kDeposit: {
                    long long amount = promptForAmountCents("Amount to deposit: $");
                    account.deposit(amount);
                    std::cout << "Deposited " << formatMoney(amount) << ". New balance: "
                              << formatMoney(account.balanceCents()) << "\n";
                    break;
                }
                case kWithdraw: {
                    long long amount = promptForAmountCents("Amount to withdraw: $");
                    account.withdraw(amount);
                    std::cout << "Withdrew " << formatMoney(amount) << ". New balance: "
                              << formatMoney(account.balanceCents()) << "\n";
                    break;
                }
                case kCheckBalance:
                    std::cout << "Current balance: " << formatMoney(account.balanceCents()) << "\n";
                    break;
                case kExit:
                    running = false;
                    break;
                default:
                    std::cout << "Please choose a number from 1 to 4.\n";
            }
        } catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << "\n";
        }
    }

    std::cout << "\nThanks for banking with us, " << account.owner() << ".\n";
    return 0;
}
