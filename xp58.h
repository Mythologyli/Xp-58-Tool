#ifndef XP58_H
#define XP58_H


class Xp58
{
public:
    explicit Xp58(const char *dev_path = "/dev/usb/lp0");

    void PrintLine(const std::string &text) const;

    void FeedNLine(int n) const;

    ~Xp58();

private:
    int fd;
};

#endif //XP58_H
