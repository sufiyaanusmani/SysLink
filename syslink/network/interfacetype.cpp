#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include <sys/stat.h>

using namespace std;

int main()
{
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    string line = "";
    system("./interfacename");
    ifstream inputFile("/tmp/syslink/interfacename");
    if (inputFile.is_open())
    {

        getline(inputFile, line);
        inputFile.close();
    }

    ofstream outfile("/tmp/syslink/interfacetype");
    string command;
    FILE *pipe;
    char buffer[1024];
    if (line.length() > 0)
    {
        command = "ip addr show " + line + " | grep -w dynamic";
        pipe = popen(command.c_str(), "r");
        fgets(buffer, sizeof(buffer), pipe);
        if (strlen(buffer) > 0)
        {
            outfile << "dynamic\n";
        }
        else
        {
            outfile << "static\n";
        }
        pclose(pipe);
    }

    return 0;
}