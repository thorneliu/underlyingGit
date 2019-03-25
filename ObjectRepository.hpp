#ifndef __COMMON_OBJECT_REPOSITORY_HPP__
#define __COMMON_OBJECT_REPOSITORY_HPP__

#include <vector>
#include "Object.hpp"

class ObjectRepository{
public:
    ObjectRepository() = default;
    void addObject(Object *obj);
    void removeObject(std::string objectId);
    Object* findObject(std::string objectId) const;

private:
    std::vector<Object *> objectList_;
};

#endif