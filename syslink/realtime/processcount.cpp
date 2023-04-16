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
        string command = "top -b -n 1 | head -n 2 | tail -n 1 | awk '{print $2,$4,$6}' | sed 's/ /@/g' > /tmp/syslink/processcount";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(time));
    }
    return 0;
}
