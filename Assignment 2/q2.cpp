
#include <iostream>
#include <vector>
using namespace std;

// Return reference to highest mark
int& highestMark(int marks[], int size)
{
    int highestIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highestIndex])
        {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

// Return const reference
const int& highestMarkConst(const int marks[], int size)
{
    int highestIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highestIndex])
        {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

// Return highest mark as a copy
int highestMarkCopy(const int marks[], int size)
{
    int highest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

// Return highest mark index
int highestMarkIndex(const int marks[], int size)
{
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[index])
        {
            index = i;
        }
    }

    return index;
}

// Return pointer to highest mark
int* highestMarkPointer(int marks[], int size)
{
    int index = highestMarkIndex(marks, size);
    return &marks[index];
}

// Dangerous function: do not call
int& dangerousReference()
{
    int value = 100;
    return value;
}

void displayMarks(const int marks[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;
}

int main()
{
    int marks[5] = {75, 90, 85, 95, 80};

    cout << "EXAMINATION MARKS REGISTER" << endl;
    cout << "--------------------------" << endl;

    cout << "\nOriginal Marks: ";
    displayMarks(marks, 5);

    cout << "\nRETURN BY REFERENCE" << endl;

    int& highest = highestMark(marks, 5);

    cout << "Highest Mark: " << highest << endl;

    highest += 2;

    cout << "After Moderation: ";
    displayMarks(marks, 5);

    cout << "\nRETURN BY CONST REFERENCE" << endl;

    const int& highestConst = highestMarkConst(marks, 5);

    cout << "Highest Mark: " << highestConst << endl;

    cout << "\nRETURN BY VALUE" << endl;

    int copiedMark = highestMarkCopy(marks, 5);

    copiedMark += 10;

    cout << "Copied Mark: " << copiedMark << endl;

    cout << "\nRETURN BY INDEX" << endl;

    int index = highestMarkIndex(marks, 5);

    cout << "Highest Index: " << index << endl;

    marks[index] += 1;

    cout << "Updated Mark: " << marks[index] << endl;

    cout << "\nRETURN BY POINTER" << endl;

    int* highestPointer = highestMarkPointer(marks, 5);

    if (highestPointer != nullptr)
    {
        *highestPointer += 1;
        cout << "Updated Highest Mark: "
             << *highestPointer << endl;
    }

    cout << "\nVECTOR IMPLEMENTATION" << endl;

    vector<int> vectorMarks = {70, 80, 90, 95, 85};

    int& vectorHighest =
        vectorMarks[highestMarkIndex(vectorMarks.data(),
                                     static_cast<int>(vectorMarks.size()))];

    cout << "Highest Vector Mark: "
         << vectorHighest << endl;

    // Do not use vectorHighest after an operation
    // that reallocates vectorMarks.

    cout << "\nFINAL MARKS: ";
    displayMarks(marks, 5);

    return 0;
}
