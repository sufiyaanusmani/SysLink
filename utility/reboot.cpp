#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 2 || argc == 3)
    {
        string pass = argv[1];
        string command = "";
        int time;
        if (argc == 2)
        {
            command = "echo " + pass + " | sudo -S shutdown -r";
        }
        else
        {
            time = stoi(argv[2]);
            command = "echo " + pass + " | sudo -S shutdown -r +" + to_string(time);
        }
        system(command.c_str());
    }
    return 0;
}
