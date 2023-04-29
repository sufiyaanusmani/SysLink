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
        string command = "df -BG | awk '{print $2,$3,$4}' | sort -hr | sed 's/ /@/g' | head -n 1 > /tmp/syslink/diskinfo";
        system(command.c_str());
        this_thread::sleep_for(chrono::seconds(7));
    }
    return 0;
}
