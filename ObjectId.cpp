#include "ObjectId.hpp"

ObjectId::ObjectId(std::string hexString) : hexString_(hexString)
{
}

ObjectId::ObjectId(unsigned char sha1[])
{
    std::ostringstream oss;
    const char hex[] = "0123456789abcdef";
    for (int i = 0; i < SHA1_CHAR_LENGTH; i++)
    {
        unsigned char c = sha1[i];
        oss << (hex[c >> 4]);
        oss << (hex[c & 0xf]);
    }

    hexString_ = oss.str();
}

std::string ObjectId::to_string() const
{
    return hexString_;
}

std::string ObjectId::getdirName() const
{
    return hexString_.substr(0, DIRLEN);
}

std::string ObjectId::getFileName() const
{
    return hexString_.substr(DIRLEN);
}