
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:
    static int issued;

    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n)
        : seat(0), name(n)
    {
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        return issued;
    }

    void print() const
    {
        cout << name << ": "
             << (seat
                 ? "Seat " + to_string(seat)
                 : string("Waiting"))
             << '\n';
    }
};

// Definition of static data member
int BusTicket::issued = 0;

// Function creating tickets
void createTickets()
{
    cout << "\nCREATING TICKETS" << endl;

    BusTicket tickets[2] =
    {
        BusTicket("Student A"),
        BusTicket("Student B")
    };

    for (const BusTicket& ticket : tickets)
    {
        ticket.print();
    }

    cout << "Total Issued: "
         << BusTicket::count() << endl;
}

int main()
{
    cout << "COLLEGE BUS SEAT TICKET SYSTEM" << endl;
    cout << "------------------------------" << endl;

    // Array of objects
    BusTicket trip[4] =
    {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    cout << "\nTICKET DETAILS" << endl;

    for (const BusTicket& ticket : trip)
    {
        ticket.print();
    }

    cout << "Issued: "
         << BusTicket::count() << endl;

    // Calling the function twice
    createTickets();

    createTickets();

    cout << "\nFINAL ISSUED COUNT: "
         << BusTicket::count() << endl;

    return 0;
}
