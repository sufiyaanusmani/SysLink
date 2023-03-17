#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    char buffer[1024];
    string result = "";
    string path;
    string directoryName = "/tmp/kernelkit";

    fs::space_info info = fs::space("/");

    path = directoryName + "/diskinfo";
    ofstream file(path);
    double capacity = static_cast<double>(info.capacity) / (1024 * 1024 * 1024);
    double available = static_cast<double>(info.available) / (1024 * 1024 * 1024);
    double used = capacity - available;
    double percentageUsed = (used / capacity) * 100;

    file << capacity << "\n";
    file << used << "\n";
    file << available << "\n";
    file << (int)percentageUsed << "\n";

    return 0;
}
