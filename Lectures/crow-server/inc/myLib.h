#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>

std::string sayHello();

std::string echoWord(std::string);

ucm::json getSuperBowlScore();

ucm::json quadratic(float, float, float);

ucm::json countMostFreqLetter(std::string);

#endif
