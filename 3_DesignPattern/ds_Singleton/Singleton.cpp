#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::Instance = nullptr;

Singleton::Singleton()
{
    Instance = nullptr;
}

Singleton* Singleton::getInstance()
{
    if (Instance == nullptr) {
        Instance = new Singleton();
        return Instance;
    }
    return nullptr;
}

void Singleton::ReleaseInst()
{
    if (Instance != nullptr) {
        delete Instance;
        Instance = nullptr;
    }
}
