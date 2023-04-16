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
        string command = "top -b -n 1 | head -n 27 | tail -n 20 | awk '{print $1,$2,$9,$10,$11,$12}' | sed 's/ /@/g' > /tmp/syslink/top";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(2));
    }
    return 0;
}
