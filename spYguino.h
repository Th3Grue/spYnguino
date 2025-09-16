#ifndef SPYGUINO_H
#define SPYGUINO_H

#include <string>

struct SystemProfile
{
    std::string user;
    std::string sudouser;
    std::string tablaenrutamiento;
    std::string kernelVersion;
    std::string distro;
    std::string ip;
    std::string ip_publica;
    std::string etcpasswd;
};

// Declaraciones de funciones
SystemProfile systemprofile();
std::string runCommand;

#endif // SPYGUINO_H
