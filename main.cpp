//
// Created by User on 11.10.2022.
//

#include "MainHeader.h"

int main(int argc, char* argv[]) {
  if (argc != 7) {
    std::cout << "Incorrect input" << std::endl;
    return 0;
  } 
  SandModel sm(0,0);
  std::string input = argv[3];
  sm.Load(input);
  std::string out = argv[4];
  int maxi = atoi(argv[5]);
  int freq = atoi(argv[6]);
  for (int i = 0; i < maxi; i++) {
    if (sm.Iterastion()) {
      if (freq != 0) {
        if ((i % freq) == 0) {
          sm.MakeCleanPicture(((out == "-")? "" : out) + std::to_string(i) + ".bmp");
        }
      }
    }
  }
  sm.MakeCleanPicture("Fin.bmp");
  return 0;
}
