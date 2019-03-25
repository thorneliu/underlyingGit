#include "ObjectRepository.hpp"

void ObjectRepository::addObject(Object *obj)
{
    objectList_.push_back(obj);
}

void ObjectRepository::removeObject(std::string objectId)
{
    for (auto it = objectList_.begin(); it != objectList_.end(); it++)
    {
        if (((*it)->id).to_string == objectId)
        {
            objectList_.erase(it);
            return;
        }
    }
}

Object* ObjectRepository::findObject(std::string objectId) const
{
    for (auto it = objectList_.begin(); it != objectList_.end(); it++)
    {
        if (((*it)->id).to_string == objectId)
        {
            return *it;
        }
    }

    return nullptr;
}