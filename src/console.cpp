//
// Created by Liplum on 4/23/2023.
//

#include <cstdlib>
#include <iostream>

using namespace std;

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void alert() {
  cout << "\a";
}