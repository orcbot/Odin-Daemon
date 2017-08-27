#ifndef CONFIG_H
#define CONFIG_H

class config {
  private:
    static config* instance;
    bool silent;
    int port;

    config();

  public:
    static config* getInstance();

    void setSilent(bool);
    void setPort(int);
    bool getSilent();
    int getPort();
};

#endif
