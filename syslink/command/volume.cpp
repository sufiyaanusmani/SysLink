#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        string percentage = argv[1];
        string command;
        command = "pactl set-sink-volume 0 " + percentage + "%";
        system(command.c_str());
    }
    return 0;
}
