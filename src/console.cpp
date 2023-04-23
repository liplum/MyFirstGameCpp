//
// Created by Liplum on 4/23/2023.
//

#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}