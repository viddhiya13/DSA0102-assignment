
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
private:
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm)
    {
    }

    friend int minutesBetween(const Time& a, const Time& b);

    friend bool earlier(const Time& a, const Time& b);

    friend inline int inlineMinutesBetween(
        const Time& a, const Time& b);

    friend inline bool inlineEarlier(
        const Time& a, const Time& b);
};

// Friend function to calculate time difference
int minutesBetween(const Time& a, const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return first > second
           ? first - second
           : second - first;
}

// Friend function to compare times
bool earlier(const Time& a, const Time& b)
{
    if (a.h < b.h)
    {
        return true;
    }

    if (a.h == b.h && a.m < b.m)
    {
        return true;
    }

    return false;
}

// Inline friend function
inline int inlineMinutesBetween(
    const Time& a, const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return first > second
           ? first - second
           : second - first;
}

// Inline comparison function
inline bool inlineEarlier(
    const Time& a, const Time& b)
{
    return (a.h < b.h) ||
           (a.h == b.h && a.m < b.m);
}

// Function for testing execution time
void performanceTest(const Time& a,
                     const Time& b)
{
    constexpr int ITERATIONS = 10000000;

    volatile long long result = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result += minutesBetween(a, b);
    }

    auto stop = high_resolution_clock::now();

    auto normalTime =
        duration_cast<milliseconds>(stop - start);

    cout << "Normal Function Time: "
         << normalTime.count() << " ms" << endl;

    start = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result += inlineMinutesBetween(a, b);
    }

    stop = high_resolution_clock::now();

    auto inlineTime =
        duration_cast<milliseconds>(stop - start);

    cout << "Inline Function Time: "
         << inlineTime.count() << " ms" << endl;

    cout << "Result: " << result << endl;
}

int main()
{
    cout << "TRAIN JOURNEY PLANNER" << endl;
    cout << "---------------------" << endl;

    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "\nTIME DIFFERENCE" << endl;

    cout << minutesBetween(departure, arrival)
         << " minutes" << endl;

    cout << "\nTIME COMPARISON" << endl;

    cout << boolalpha;

    cout << "Arrival Earlier Than Departure: "
         << earlier(arrival, departure) << endl;

    cout << "Departure Earlier Than Arrival: "
         << earlier(departure, arrival) << endl;

    cout << "\nSAME TIME TEST" << endl;

    Time time1(12, 30);
    Time time2(12, 30);

    cout << "Difference: "
         << minutesBetween(time1, time2)
         << " minutes" << endl;

    cout << "Earlier: "
         << earlier(time1, time2) << endl;

    cout << "\nBEFORE AND AFTER NOON" << endl;

    Time morning(11, 50);
    Time afternoon(12, 10);

    cout << "Difference: "
         << minutesBetween(morning, afternoon)
         << " minutes" << endl;

    cout << "Morning Earlier: "
         << earlier(morning, afternoon) << endl;

    cout << "\nINLINE FUNCTION TEST" << endl;

    cout << "Inline Difference: "
         << inlineMinutesBetween(departure, arrival)
         << endl;

    cout << "Inline Comparison: "
         << inlineEarlier(departure, arrival)
         << endl;

    cout << "\nPERFORMANCE TEST" << endl;

    performanceTest(departure, arrival);

    return 0;
}
