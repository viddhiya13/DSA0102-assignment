
#include <iostream>
using namespace std;

// Call by value
void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << endl;
}

// Call by reference
void applyByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long* fee, int percent)
{
    if (fee != nullptr)
    {
        *fee -= *fee * percent / 100;
    }
}

// Return new fee
long long applyAndReturn(long long fee, int percent)
{
    return fee - fee * percent / 100;
}

// Return by reference
int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

// Default arguments
void show(int x, int y = 5, int z = 10)
{
    cout << x + y + z << ' ';
}

int main()
{
    cout << "HOSTEL FEE CONCESSION SYSTEM" << endl;
    cout << "----------------------------" << endl;

    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    cout << "\nCALL BY VALUE" << endl;
    applyByValue(fee1, 10);
    cout << "Stored Fee: " << fee1 << endl;

    cout << "\nCALL BY REFERENCE" << endl;
    applyByReference(fee2, 10);
    cout << "Stored Fee: " << fee2 << endl;

    cout << "\nCALL BY POINTER" << endl;
    applyByPointer(&fee3, 15);
    cout << "Stored Fee: " << fee3 << endl;

    cout << "\nRETURN NEW FEE" << endl;
    long long newFee = applyAndReturn(45000, 25);
    cout << "New Fee: " << newFee << endl;

    cout << "\nRETURN BY REFERENCE" << endl;
    int a = 20;
    int b = 30;

    bigger(a, b) = 100;

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;

    cout << "\nDEFAULT ARGUMENTS" << endl;
    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << endl;

    cout << "\nMULTIPLE CONCESSIONS" << endl;

    long long studentFee = 45000;

    applyByReference(studentFee, 10);
    applyByReference(studentFee, 15);

    cout << "Final Fee: " << studentFee << endl;

    return 0;
}
