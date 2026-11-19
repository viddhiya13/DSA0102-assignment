
#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    long long balance;

    static constexpr int MAX_TRANSACTIONS = 10;

    long long transactions[MAX_TRANSACTIONS];

    int count;
    int nextIndex;

public:
    SavingsAccount(int accountNo, long long initialBalance)
        : accountNumber(accountNo),
          balance(initialBalance),
          transactions{},
          count(0),
          nextIndex(0)
    {
    }

    void addTransaction(long long amount)
    {
        transactions[nextIndex] = amount;

        nextIndex =
            (nextIndex + 1) % MAX_TRANSACTIONS;

        if (count < MAX_TRANSACTIONS)
        {
            count++;
        }
    }

    void deposit(long long amount);

    bool withdraw(long long amount);

    void miniStatement() const;

    void displayBalance() const;
};

// Deposit function
void SavingsAccount::deposit(long long amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    if (balance > 1000000000000LL - amount)
    {
        cout << "Deposit exceeds balance limit." << endl;
        return;
    }

    balance += amount;

    addTransaction(amount);

    cout << "Deposit Successful." << endl;
}

// Withdraw function
bool SavingsAccount::withdraw(long long amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount." << endl;
        return false;
    }

    if (amount > balance)
    {
        cout << "Insufficient Balance." << endl;
        return false;
    }

    balance -= amount;

    addTransaction(-amount);

    cout << "Withdrawal Successful." << endl;

    return true;
}

// Mini statement
void SavingsAccount::miniStatement() const
{
    cout << "\nMINI STATEMENT" << endl;
    cout << "------------------------" << endl;

    cout << "Account Number: "
         << accountNumber << endl;

    cout << "Recent Transactions:" << endl;

    int start =
        (nextIndex - count + MAX_TRANSACTIONS)
        % MAX_TRANSACTIONS;

    for (int i = 0; i < count; i++)
    {
        int index =
            (start + i) % MAX_TRANSACTIONS;

        long long amount = transactions[index];

        cout << (amount >= 0 ? "Deposit: Rs " :
                              "Withdrawal: Rs ")
             << (amount >= 0 ? amount : -amount)
             << endl;
    }
}

// Display balance
void SavingsAccount::displayBalance() const
{
    cout << "Account Balance: Rs "
         << balance << endl;
}

int main()
{
    SavingsAccount account(1001, 10000);

    cout << "SAVINGS ACCOUNT SYSTEM" << endl;
    cout << "----------------------" << endl;

    account.displayBalance();

    account.deposit(2000);
    account.withdraw(1500);
    account.deposit(3000);
    account.withdraw(1000);

    account.deposit(500);
    account.withdraw(200);

    account.deposit(700);
    account.withdraw(300);

    account.deposit(900);
    account.withdraw(400);

    account.deposit(1100);
    account.withdraw(600);

    account.miniStatement();

    cout << "\nFINAL ACCOUNT DETAILS" << endl;

    account.displayBalance();

    return 0;
}
