#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    char buffer[1024];
    string result = "";
    string path;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    // Run the Linux command and open a pipe to read its output
    FILE *pipe = popen("timedatectl | grep -i 'time zone' | awk '{print $3}' | sed 's/\//@/g' > /tmp/syslink/location", "r");
    if (!pipe)
    {
        cerr << "Failed to run command" << std::endl;
        return 1;
    }

    // Close the pipe and print the output
    pclose(pipe);

    return 0;
}
