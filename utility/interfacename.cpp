#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

using namespace std;

int main()
{
    char buffer[1024];
    string path;
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);

    FILE *pipe = popen("ifconfig -s | awk '{print $1}' | tail -n +2 | grep e", "r");
    fgets(buffer, sizeof(buffer), pipe);
    pclose(pipe);

    string interface(buffer);
    string command = "";

    path = directoryName + "/interfacename";
    ofstream outfile(path);
    outfile << interface;
    outfile.close();

    return 0;
}
