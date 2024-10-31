#include "ObjectManager.h"

std::vector<Object>* ObjectManager::getObjectList()
{
    std::vector<Object>* ptr = &objectList;
    return ptr;
}

void ObjectManager::initObjects()
{
    FileReader::readObjectsFromFile("assets\\data\\object_data.csv", objectList);
}

void ObjectManager::clearObjects()
{
    objectList.clear();
}
