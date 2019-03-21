#ifndef __COMMON_SHA1_HPP__
#define __COMMON_SHA1_HPP__

#include "string"
#include "sstream"

class SHA1{
public:
    SHA1(std::string hexString);
    SHA1(unsigned char sha1[]);
    std::string to_string() const;
    std::string getdirName() const;
    std::string getFileName() const;

private:
    std::string hexString_;
    const int SHA1_CHAR_LENGTH = 20;
    const int DIRLEN = 2;
};

#endif