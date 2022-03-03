#include <fcntl.h>
#include <unistd.h>
#include <string>

#include "xp58.h"


Xp58::Xp58(const char *dev_path)
{
    fd = open(dev_path, O_RDWR);
}

void Xp58::PrintLine(const std::string &text) const
{
    write(fd, (text + '\n').c_str(), text.length() + 1);
}

void Xp58::FeedNLine(int n) const
{
    uint8_t buf[2] = {0x1B, 'd'};
    write(fd, buf, 2);
    write(fd, &n, 1);
}

Xp58::~Xp58()
{
    close(fd);
}
