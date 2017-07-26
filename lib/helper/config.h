#ifndef CONFIG_H
#define CONFIG_H

class config {
private:
    bool silent;
    int port;
public:
    config();
    void setSilent(bool);
    void setPort(int);
    bool getSilent();
    int getPort();
};

#endif
