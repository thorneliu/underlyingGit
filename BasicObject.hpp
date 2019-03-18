#ifndef __COMMON_BASIC_OBJECT_HPP__
#define __COMMON_BASIC_OBJECT_HPP__

#include "ObjectType.hpp"

struct Object{
    unsigned char sha1[20];
    EObjectType type_;
};

#endif