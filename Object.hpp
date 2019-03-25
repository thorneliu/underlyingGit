#ifndef __COMMON_OBJECT_HPP__
#define __COMMON_OBJECT_HPP__

#include "ObjectId.hpp"
#include "ObjectType.hpp"

struct ObjectList {
    Object *item;
    ObjectList *next;
};

struct Object {
    bool parsed;
    bool used;
    int  flags;
    ObjectId id;
    EObjectType type;
    ObjectList *refs;
    ObjectList *attached_deltas;
};

#endif