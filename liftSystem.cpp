#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <windows.h>
using namespace std;
void sayFloor(int n)
{
    cout << "Currently on floor: " << n << "\n";
}
int getfloor()
{
    int x;
    // cout << "Enter the floor you want to go: " << endl;
    cin >> x;
    return x;
}
int check(int c, int g)
{
    if (g == -1)
    {
        Beep(500, 1500);
        cout << "Exiting {{{(>_<)}}}";
        return -1;
    }
    else if (g == c)
    {
        cout << "Currently on that floor enter other floor( if you want to exit type '-1' without quotes ): " << endl;
        g = getfloor();
        return check(c, g);
    }
    else
    {
        if (g < c)
        {
            for (int i = c; i >= g; i--)
            {
                cout << i << endl;
                sleep(1);
            }
            Beep(500, 500);
            c = g;
            return c;
        }
        else
        {
            for (int i = c; i <= g; i++)
            {

                cout << i << endl;
                sleep(1);
            }
            Beep(500, 500);
            // cout << \a;
            c = g;
            return c;
        }
    }
}
int main()
{
    int floor = 6;
    int cflorr = 0;
    bool isIdle = true;
    string x;
    do
    {
        system("cls");
        int gfloor = 0;
        sayFloor(cflorr);
        cout << "Enter the floor you want to go from 0 to " << floor << ": " << endl;
        cin >> gfloor;
        if (gfloor > floor || (gfloor != -1 && gfloor < 0))
        {
            cout << "No such floor!!" << endl;
            sleep(1 * 2);
            // getchar();
            continue;
        }
        int tyui = check(cflorr, gfloor);
        if (tyui == -1)
        {
            return 0;
        }
        else
        {
            cflorr = tyui;
        }
        // getfloor(gfloor);
        // if (gfloor == -1)
        // {
        //     return 0;
        // }
        // else if (gfloor == cflorr)
        // {
        //     cout << "Currently on that floor enter other floor: " << endl;
        //     cin >> gfloor;
        // }
        // {
        cout << "Do you want to continue (y = yes / n = no): ";
        cin >> x;
        // }
    } while (x != "n");
    return 0;
}