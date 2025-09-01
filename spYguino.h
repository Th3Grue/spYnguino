#ifndef SPYGUINO_H
#define SPYGUINO_H

#include <string>

struct SystemProfile
{
    std::string user;
    std::string kernelVersion;
    std::string distro;
    std::string ip;
    std::string ip_publica;
};

// Declaraciones de funciones
SystemProfile systemprofile();
std::string readIp();
std::string readDistro();
std::string readKernelVersion();
std::string readUser();
std::string readPublicIp();

#endif // SPYGUINO_H
