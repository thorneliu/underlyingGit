#include "SHA1.hpp"

SHA1::SHA1(std::string hexString) : hexString_(hexString)
{
}

SHA1::SHA1(unsigned char sha1[])
{
    ostringstream oss;
    const char hex[] = "0123456789abcdef";
    for (int i = 0; i < SHA1_CHAR_LENGTH; i++)
    {
        unsigned char c = sha1[i];
        oss << (hex[c >> 4]);
        oss << (hex[c & 0xf]);
    }

    hexString_ = oss.str();
}

std::string SHA1::to_string() const
{
    return hexString_;
}

std::string SHA1::getdirName() const
{
    return hexString_.substr(0, DIRLEN);
}

std::string getFileName() const
{
    return hexString_.substr(DIRLEN);
}