#include <myLib.h>

int num = 0;

std::string intToHexStr(int x){

   return "00";
}

ucm::json memRep(int x){
   ucm::json result;

   num = x;

   int* p = &num;

   ucm::json hex;



   result["valid"] = true;
   result["hex"] = {"00", "00", "00", "00"};

   return result;
}
