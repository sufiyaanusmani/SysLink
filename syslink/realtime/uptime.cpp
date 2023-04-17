#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sys/stat.h>

using namespace std;

int main()
{
    int time = 60;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    while (true)
    {
        string command = "uptime -p | awk '{print $2,$3}' | sed 's/ /@/g' > /tmp/syslink/uptime";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(time));
    }
    return 0;
}
