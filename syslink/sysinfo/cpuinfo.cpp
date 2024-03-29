#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <string>
#include <sstream>

using namespace std;

void storeInFile(string path, string str)
{
    ofstream outfile(path);
    outfile << str;
    outfile.close();
}

string filterOutput(string result)
{
    string output = "";
    stringstream ss(result);
    string line;
    while (getline(ss, line))
    {
        size_t firstNonSpace = line.find_first_not_of(' ');
        line = line.substr(firstNonSpace);
        output = output + line + "\n";
    }
    return output;
}

int main()
{
    char buffer[1024];
    string result = "";
    string path;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    // Run the Linux command and open a pipe to read its output
    FILE *pipe = popen("lscpu | head -n 11 | cut -d':' -f2", "r");
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
    result = filterOutput(result);
    storeInFile(path, result);

    return 0;
}
