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

int main()
{
    char buffer[1024];
    string result = "";
    string path;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    // Run the Linux command and open a pipe to read its output
    while (1)
    {
        FILE *pipe = popen("iostat -o JSON", "r");
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
        path = directoryName + "/iostat.json";
        storeInFile(path, result);
    }
    return 0;
}
