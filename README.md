<!-- TITLE with Animated Typing Effect -->
<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=1B7A43&center=true&vCenter=true&width=600&lines=Bank+Account+Simulator%3A+Deposit.+Withdraw.+Never+Overdraw.;Classes%2C+Exceptions%2C+Clean+C%2B%2B.;Zero+Dependencies." alt="Typing SVG" />
</p>

<h1 align="center">🏦 Bank Account Simulator 🏦</h1>
<h3 align="center">Deposit It, Withdraw It, Never Go Negative.</h3>

<br>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B17-1B7A43?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++17" />
  <img src="https://img.shields.io/badge/Dependencies-None-1B7A43?style=for-the-badge" alt="Zero Dependencies" />
  <img src="https://img.shields.io/badge/Platform-Terminal-1B7A43?style=for-the-badge&logo=gnubash&logoColor=white" alt="Terminal" />
</p>

<br>

---

## 🚀 What Did I Build?

**Bank Account Simulator** is a command-line banking app written in **C++17** that lets you open an account, deposit, withdraw, and check your balance, while making sure the balance **can never go below zero**.

- **`BankAccount` class**: owns the balance and enforces every rule, with a private balance that only `deposit` and `withdraw` can change
- **Overdraft protection**: withdrawing more than you have is rejected with a clear error
- **Exact money handling**: balances are stored in whole cents, so there are no floating point rounding errors
- **Exception-based errors**: invalid amounts and insufficient funds are reported with `std::invalid_argument` and `std::runtime_error`
- **Input validation**: letters, symbols, and bad menu choices never crash the program
- **Clean menu loop**: deposit, withdraw, check balance, and exit, with a short and readable `main()`
- **Zero dependencies**: only the C++ standard library

<br>

---

<br>

## ☁️ What is This Project?

**Bank Account Simulator** is a small, focused project built to brush up on core C++ and object-oriented fundamentals. The scope is deliberately simple, so the attention goes where it matters: a well-designed class, honest error handling, and code that reads cleanly.

The logic and the interface are kept apart on purpose. `BankAccount` knows nothing about the console, so it could be reused in a GUI, a test suite, or a larger system without changes. `main.cpp` only handles prompting, parsing input, and printing results.

Validation lives in exactly one place. The input helpers let zero and negative amounts through, and the class rejects them, so the rule can never drift out of sync between layers.

<br>

---

<br>

## 🛠️ Tech Stack and Tools

<br>

<div align="center">

<table>
  <thead>
    <tr>
      <th>Tech Used</th>
      <th>Purpose</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>C++17</td>
      <td>Classes, constructors, encapsulation, and program flow</td>
    </tr>
    <tr>
      <td>&lt;iostream&gt;</td>
      <td>Console input and output</td>
    </tr>
    <tr>
      <td>&lt;stdexcept&gt;</td>
      <td>Standard exception types for error handling</td>
    </tr>
    <tr>
      <td>&lt;cmath&gt;</td>
      <td>Safe conversion of dollar amounts to cents with <code>std::llround</code></td>
    </tr>
    <tr>
      <td>&lt;sstream&gt; and &lt;iomanip&gt;</td>
      <td>Formatting cents as a clean <code>$12.05</code> string</td>
    </tr>
    <tr>
      <td>&lt;limits&gt;</td>
      <td>Discarding leftover input after a failed read</td>
    </tr>
  </tbody>
</table>

</div>

<br>

---

<br>

## ⚙️ Getting Started

**Project structure**

```text
.
├── BankAccount.h      # Class declaration and the rules it promises
├── BankAccount.cpp    # Class implementation and validation
└── main.cpp           # Menu loop and console input handling
```

**Compile**

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -o bank main.cpp BankAccount.cpp
```

**Run**

```bash
./bank        # macOS / Linux
bank.exe      # Windows
```

**Sample session**

```text
=== Simple Bank ===
Account holder name: Sumedh

Welcome, Sumedh. Your account is open with $0.00.

1. Deposit
2. Withdraw
3. Check balance
4. Exit

Choose an option: 1
Amount to deposit: $100.50
Deposited $100.50. New balance: $100.50

Choose an option: 2
Amount to withdraw: $500
Error: Insufficient funds.

Choose an option: 3
Current balance: $100.50

Choose an option: 4

Thanks for banking with us, Sumedh.
```

<br>

---

<br>

## 🔐 Core Features

- 🏦 Open an account with an owner name, validated on creation
- ➕ Deposit money, with zero and negative amounts rejected
- ➖ Withdraw money, with overdrafts blocked
- 💵 Balances stored as integer cents for exact arithmetic
- 🛡️ Bad input is caught, the stream is reset, and the user is prompted again
- ⚠️ Every error is reported through exceptions and shown as a clear message
- 🚪 Exits cleanly on option 4 or when the input stream closes
- 📦 Three small files, standard library only

<br>

---

<br>

## 🔍 Learning Highlights

- Practiced **encapsulation**: the balance is private, so the only way to change it is through methods that enforce the rules
- Validated object state in the **constructor**, so an invalid `BankAccount` can never exist
- Chose **integer cents over `double`** to avoid the rounding errors that make floating point a bad fit for money
- Used the right **exception types** for the right failures: `invalid_argument` for bad input, `runtime_error` for a valid request that can't be fulfilled
- Split the class into a **header and source file**, keeping the interface separate from the implementation
- Kept helpers in an **anonymous namespace** and replaced magic numbers with named constants
- Handled **end-of-input** (Ctrl+D or Ctrl+Z) so the program never loops forever on a closed stream
- Kept the rule for "what is a valid amount" in **one place**, so the class stays the single source of truth

<br>



## 👨‍💻 About the Creator

*LinkedIn - [Sumedh Pimplikar](https://www.linkedin.com/in/sumedh-pimplikar)*
