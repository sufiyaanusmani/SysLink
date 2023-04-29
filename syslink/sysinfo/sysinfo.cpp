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
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);

    system("uname -s > /tmp/syslink/sysinfo");
    system("uname -n >> /tmp/syslink/sysinfo");
    system("uname -r >> /tmp/syslink/sysinfo");
    system("uname -p >> /tmp/syslink/sysinfo");

    return 0;
}
