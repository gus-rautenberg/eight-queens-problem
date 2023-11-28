#include <iostream>
#include <fstream>
#include "breadth_first.h"

using namespace std;

int main(int argc, char const *argv[]){

    if (argc != 2)
    {
        exit(1);
    }

    fstream out;
    float time;

    switch (argv[1][0])
    {
    case 'n':
        breath_first();
        break;
    
    case 'f':
        time = breath_first_Time_First_Solution();
        out.open("first.out", ios::app);
        out << time << endl;
        break;

    case 'a':
        time = breath_first_Time_All_Solutions();
        out.open("all.out", ios::app);
        out << time << endl;
        break;

    default:
        break;
    }

    out.close();

    return 0;
}
