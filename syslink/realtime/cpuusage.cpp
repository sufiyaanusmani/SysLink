#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sys/stat.h>

using namespace std;

int main()
{
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    while (true)
    {
        string command = "top -bn 1 | awk 'NR>7{s+=$9} END {print s}' > /tmp/syslink/cpuusage";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(2));
    }
    return 0;
}
