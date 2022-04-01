#include <iostream>


#include "funcs.h"

int main()
{

  std::cout << "SOLVE(CAESAR_ENCRYPTED(Embrace the Chaos, 3))" << std::endl;
  std::cout << solve(caesar_encrypted("Embrace the Chaos", 3)) << std::endl;

  return 0;
}
