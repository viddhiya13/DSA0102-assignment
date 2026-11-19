
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Parcel class
class Parcel
{
private:
    double weight;
    bool express;
    bool insured;

public:
    Parcel(double w, bool e = false, bool i = false)
        : weight(w), express(e), insured(i) {}

    double getWeight() const
    {
        return weight;
    }

    bool isExpress() const
    {
        return express;
    }

    bool isInsured() const
    {
        return insured;
    }
};

// Function prototype
double charge(double weight,
              bool express = false,
              bool insured = false);

double charge(int weightInGrams);

double charge(const Parcel& parcel);

// Weight in kilograms
double charge(double weight,
              bool express,
              bool insured)
{
    double amount = weight * 50;

    if (express)
    {
        amount += amount * 50 / 100;
    }

    if (insured)
    {
        amount += 20;
    }

    return amount;
}

// Weight in grams
double charge(int weightInGrams)
{
    double weightKg = weightInGrams / 1000.0;

    return charge(weightKg, false, false);
}

// Parcel object
double charge(const Parcel& parcel)
{
    return charge(
        parcel.getWeight(),
        parcel.isExpress(),
        parcel.isInsured()
    );
}

int main()
{
    cout << fixed << setprecision(2);

    cout << "COURIER CHARGE CALCULATOR" << endl;
    cout << "-------------------------" << endl;

    // Six different function calls
    cout << "\nCALL 1: charge(2)" << endl;
    cout << "Charge: Rs " << charge(2) << endl;

    cout << "\nCALL 2: charge(2.0)" << endl;
    cout << "Charge: Rs "
         << charge(2.0, false, false) << endl;

    cout << "\nCALL 3: charge(2.0f)" << endl;
    cout << "Charge: Rs "
         << charge(static_cast<double>(2.0f),
                   false, false) << endl;

    cout << "\nCALL 4: charge(2, true)" << endl;
    cout << "Charge: Rs "
         << charge(2.0, true, false) << endl;

    cout << "\nCALL 5: charge(2.5, true, true)" << endl;
    cout << "Charge: Rs "
         << charge(2.5, true, true) << endl;

    cout << "\nCALL 6: Parcel Object" << endl;

    Parcel p1(3.0, true, true);

    cout << "Charge: Rs " << charge(p1) << endl;

    cout << "\nADDITIONAL PARCEL TESTS" << endl;

    Parcel p2(1.5);
    Parcel p3(4.0, false, true);

    cout << "Normal Parcel: Rs "
         << charge(p2) << endl;

    cout << "Insured Parcel: Rs "
         << charge(p3) << endl;

    return 0;
}
