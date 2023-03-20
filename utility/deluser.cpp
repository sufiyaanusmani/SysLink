#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        string username(argv[2]);
        string pass(argv[1]);
        string command = "echo " + pass + " | sudo -S userdel " + username;
        system(command.c_str());
    }
    return 0;
}
