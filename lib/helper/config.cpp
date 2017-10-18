#include "config.h"

config* config::instance = 0;

config::config() {
    silent = false;
    port = 8000;
}

config* config::getInstance() {
  if (instance == 0) {
    instance = new config();
  }

  return instance;
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
