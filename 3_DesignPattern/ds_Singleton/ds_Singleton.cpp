#include "Singleton.h"
#include <iostream>
using namespace std;

int main()
{
    Singleton* singleton = nullptr;
    Singleton::getInstance(); //인스턴스 생성
    Singleton::getInstance(); //두번째 인스턴스는 중복생성 방지
    Singleton::ReleaseInst(); //메모리 해제 및 인스턴스 nullptr

    return 0;
}
