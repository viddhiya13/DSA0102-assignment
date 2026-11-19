
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

constexpr int MAX_TRANSACTIONS = 10;
constexpr int TEST_TRANSACTIONS = 1000000;

// ORIGINAL DESIGN: SHIFTING ARRAY

class OriginalAccount
{
private:
    long long transactions[MAX_TRANSACTIONS];
    int count;

public:
    OriginalAccount() : transactions{}, count(0)
    {
    }

    void addTransaction(long long amount)
    {
        if (count < MAX_TRANSACTIONS)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            // Shift all elements to remove oldest transaction
            for (int i = 1; i < MAX_TRANSACTIONS; i++)
            {
                transactions[i - 1] = transactions[i];
            }

            transactions[MAX_TRANSACTIONS - 1] = amount;
        }
    }

    void display() const
    {
        cout << "\nORIGINAL ACCOUNT TRANSACTIONS" << endl;

        for (int i = 0; i < count; i++)
        {
            cout << transactions[i] << endl;
        }
    }
};

// REDESIGNED: CIRCULAR BUFFER

class RedesignedAccount
{
private:
    long long transactions[MAX_TRANSACTIONS];
    int count;
    int nextIndex;

public:
    RedesignedAccount()
        : transactions{}, count(0), nextIndex(0)
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

    void display() const
    {
        cout << "\nREDESIGNED ACCOUNT TRANSACTIONS" << endl;

        int start =
            (nextIndex - count + MAX_TRANSACTIONS)
            % MAX_TRANSACTIONS;

        for (int i = 0; i < count; i++)
        {
            int index =
                (start + i) % MAX_TRANSACTIONS;

            cout << transactions[index] << endl;
        }
    }
};

// Performance measurement for original design
long long testOriginal()
{
    OriginalAccount account;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < TEST_TRANSACTIONS; i++)
    {
        account.addTransaction(i + 1);
    }

    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(
        stop - start).count();
}

// Performance measurement for redesigned design
long long testRedesigned()
{
    RedesignedAccount account;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < TEST_TRANSACTIONS; i++)
    {
        account.addTransaction(i + 1);
    }

    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(
        stop - start).count();
}

int main()
{
    cout << "SAVINGS ACCOUNT REDESIGN SYSTEM" << endl;
    cout << "--------------------------------" << endl;

    OriginalAccount original;

    RedesignedAccount redesigned;

    // Insert sample transactions
    for (int i = 1; i <= 15; i++)
    {
        original.addTransaction(i * 100);

        redesigned.addTransaction(i * 100);
    }

    // Display original transactions
    original.display();

    // Display redesigned transactions
    redesigned.display();

    // Performance comparison
    cout << "\nPERFORMANCE COMPARISON" << endl;

    cout << "Number of Transactions: "
         << TEST_TRANSACTIONS << endl;

    long long originalTime = testOriginal();

    long long redesignedTime = testRedesigned();

    cout << "\nOriginal Shifting Array Time: "
         << originalTime << " microseconds" << endl;

    cout << "Redesigned Circular Buffer Time: "
         << redesignedTime << " microseconds" << endl;

    cout << "\nDESIGN COMPARISON" << endl;

    cout << "Original Array:" << endl;
    cout << "Time for insertion after full: O(k)" << endl;
    cout << "Space Complexity: O(k)" << endl;

    cout << "\nCircular Buffer:" << endl;
    cout << "Time for insertion: O(1)" << endl;
    cout << "Space Complexity: O(k)" << endl;

    cout << "\nREDESIGN VALIDATION" << endl;

    cout << "Both designs retain the latest "
         << MAX_TRANSACTIONS
         << " transactions." << endl;

    cout << "Circular buffer avoids shifting elements."
         << endl;

    return 0;
}
