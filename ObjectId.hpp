#ifndef __COMMON_OBJECTID_HPP__
#define __COMMON_OBJECTID_HPP__

#include <string>
#include <sstream>

class ObjectId{
public:
    ObjectId(std::string hexString);
    ObjectId(unsigned char sha1[]);
    std::string to_string() const;
    std::string getdirName() const;
    std::string getFileName() const;

private:
    std::string hexString_;
    const int SHA1_CHAR_LENGTH = 20;
    const int DIRLEN = 2;
};

#endif