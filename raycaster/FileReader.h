#pragma once
#include <vector>
#include "Map.h"
#include "Object.h"
#include "Enemy.h"

class FileReader {
public:
    static bool readMapFromFile(const char* fileName, int map[GRID_SIZE][GRID_SIZE]);
    static bool readObjectsFromFile(const char* fileName, std::vector<Object*>& objectList);
    static bool readEnemiesFromFile(const char* fileName, std::vector<Enemy*>& enemyList);
};
