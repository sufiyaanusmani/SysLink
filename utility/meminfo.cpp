#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>

using namespace std;

void storeInFile(string path, string str)
{
    ofstream outfile(path);
    outfile << str;
    outfile.close();
}

int main()
{
    char buffer[1024];
    string result = "";
    string path;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    // Run the Linux command and open a pipe to read its output
    FILE *pipe = popen("lscpu | head -11", "r");
    if (!pipe)
    {
        cerr << "Failed to run command" << std::endl;
        return 1;
    }

    // Read the output of the command line by line
    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    {
        result += buffer;
    }

    // Close the pipe and print the output
    pclose(pipe);
    path = directoryName + "/cpuinfo";
    storeInFile(path, result);

    return 0;
}
