#include <iostream>
#include <ifaddrs.h>
#include <cstring>
#include <net/if.h>
#include <fstream>
#include <sys/stat.h>

using namespace std;

int main()
{
    string directoryName = "/tmp/syslink";

    mkdir(directoryName.c_str(), 0777);
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1)
    {
        std::cerr << "Error getting network interface information" << std::endl;
        return 1;
    }

    bool wired = false;
    bool wireless = false;
    for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == nullptr)
            continue;
        if (strcmp(ifa->ifa_name, "lo") == 0)
            continue; // skip loopback interface
        if (ifa->ifa_addr->sa_family == AF_PACKET)
        {
            if (ifa->ifa_flags & IFF_LOOPBACK)
                continue; // skip loopback interface
            if (ifa->ifa_flags & IFF_UP)
            {
                if (ifa->ifa_flags & IFF_RUNNING)
                {
                    if (ifa->ifa_flags & IFF_BROADCAST)
                    {
                        wireless = true;
                    }
                    else
                    {
                        wired = true;
                    }
                }
            }
        }
    }

    freeifaddrs(ifaddr);

    ofstream fout("/tmp/syslink/connectiontype");

    if (wired)
    {
        fout << "ethernet\n";
    }
    else if (wireless)
    {
        fout << "wireless\n";
    }
    else
    {
        fout << "none\n";
    }

    fout.close();

    return 0;
}
