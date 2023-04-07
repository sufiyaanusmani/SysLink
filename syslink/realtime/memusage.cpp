#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sys/stat.h>
#include <fstream>

using namespace std;

int main()
{
    string directoryName = "/tmp/syslink";
    FILE *pipe;
    char buffer[1024];
    double memtotal, memavailable, memused, per;
    string path = directoryName + "/memusage";

    mkdir(directoryName.c_str(), 0777);
    while (true)
    {
        pipe = popen("cat /proc/meminfo | sed -n '1p;3p' | awk '{print $2}'", "r");
        fgets(buffer, sizeof(buffer), pipe);
        memtotal = atoi(buffer);
        fgets(buffer, sizeof(buffer), pipe);
        pclose(pipe);
        memavailable = atoi(buffer);
        memtotal = (double)memtotal / (1024 * 1024);
        memavailable = (double)memavailable / (1024 * 1024);
        memused = memtotal - memavailable;
        this_thread::sleep_for(chrono::seconds(2));
        per = (memused / memtotal) * 100;

        ofstream outfile(path);
        outfile << per << "\n";
        outfile.close();
    }
    return 0;
}
