// Interrupt Handler

#include <bits/stdc++.h>

using namespace std;

void ioServiceRoutine()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;

}

void errorServiceRoutine()
{
    srand(time(NULL));
    int x = rand() % 5 + 1;
    for (int i = 1; i <= x; i++)
    {
        int delay = 1000;                 // in ms
        clock_t start_time = clock();
        while (clock() < start_time + delay);

        cout << "Error " << i << " Removed\n";
    }
}

void interruptHandler(int n)
{
    srand(time(NULL));
    int p1 = rand() % 4 + 2;
    int p2 = p1 + rand() % 3 + 1;
    for (int i = 1; i <= n;)
    {
        if (i == p1 - 1)
        {
            cout << "Process " << i << " executed\n";
            cout << "\nInput/Output Interrupt occured\nProcesses paused\n";
            ioServiceRoutine();
            cout << "\nInterrupt handled by Interrupt Service Routine!\n";
            cout << "Process Execution continue.....\n\n";
            i++;
        }
        else if (i == p2 - 1)
        {
            cout << "Process " << i << " executed\n";
            cout << "\nError Interrupt occured!\nProcesses paused, Please Wait\n";
            errorServiceRoutine();
            cout << "\nInterrupt handled by Interrupt Service Routine!\n";
            cout << "Process Execution continue.....\n\n";
            i++;
        }
        else
        {
            cout << "Process " << i << " Executed\n";
            i++;
        }
    }
}

int main()
{

    srand(time(NULL));
    int n = rand() % 6 + 10;
    interruptHandler(n);

    return 0;
}
