#include <fcntl.h>
#include <unistd.h>
#include <string>

#include "xp58.h"


Xp58::Xp58(const char *dev_path)
{
    fd = open(dev_path, O_RDWR);

    uint8_t buf[2] = {0x1B, '@'};
    write(fd, buf, 2);
}

void Xp58::PrintLine(const std::string &text) const
{
    write(fd, (text + '\n').c_str(), text.length() + 1);
}

void Xp58::FeedNLines(uint8_t n) const
{
    uint8_t buf[2] = {0x1B, 'd'};
    write(fd, buf, 2);
    write(fd, &n, 1);
}

void Xp58::ReverseModeOn() const
{
    uint8_t buf[3] = {0x1D, 'B', 1};
    write(fd, buf, 3);
}

void Xp58::ReverseModeOff() const
{
    uint8_t buf[3] = {0x1D, 'B', 0};
    write(fd, buf, 3);
}

void Xp58::SetCharacterSize(uint8_t width, uint8_t height) const
{
    uint8_t buf[2] = {0x1D, '!'};
    write(fd, buf, 2);

    uint8_t data = (width - 1) << 4 | (height - 1);
    write(fd, &data, 1);
}

Xp58::~Xp58()
{
    close(fd);
}
