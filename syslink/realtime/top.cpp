#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{
    int time;
    if (argc == 1)
    {
        time = 2;
    }
    else if (argc == 2)
    {
        time = stoi(argv[1]);
    }
    else
    {
        exit(1);
    }
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    while (true)
    {
        string command = "top -b -n 1 | head -n 27 | tail -n 20 | awk '{print $1,$2,$9,$10,$11,$12}' | sed 's/ /@/g' > /tmp/syslink/top";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(time));
    }
    return 0;
}
