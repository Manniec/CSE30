#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>

std::string sayHello();

std::string echoWord(std::string);

ucm::json getSuperBowlScore();

ucm::json toUpperLower(std::string);

#endif
