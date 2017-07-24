//@todo maybe make it read from a file
#include "config.h"

config::config() {
    silent = false;
    port = 8000;
}

void config::setSilent(bool _silent) {
    silent = _silent;
}

void config::setPort(int _port) {
    port = _port;
}

bool config::getSilent() {
    return silent;
}

int config::getPort() {
    return port;
}
