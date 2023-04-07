#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>

using namespace std;

int main()
{
    char buffer[1024];
    string path;
    string directoryName = "/tmp/syslink";
    double memtotal, swaptotal;

    mkdir(directoryName.c_str(), 0777);
    // Run the Linux command and open a pipe to read its output
    FILE *pipe = popen("cat /proc/meminfo | sed -n '1p;15p' | awk '{print $2}'", "r");
    if (!pipe)
    {
        cerr << "Failed to run command" << std::endl;
        return 1;
    }

    // Read the output of the command line by line
    fgets(buffer, sizeof(buffer), pipe);
    memtotal = atoi(buffer);
    fgets(buffer, sizeof(buffer), pipe);
    swaptotal = atoi(buffer);

    memtotal = (double)memtotal / (1024 * 1024);
    swaptotal = (double)swaptotal / (1024 * 1024);

    // Close the pipe and print the output
    pclose(pipe);
    path = directoryName + "/meminfo";
    ofstream outfile(path);
    outfile << memtotal << "\n"
            << swaptotal << "\n";
    outfile.close();

    return 0;
}
