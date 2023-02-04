//
// Created by User on 11.10.2022.
//

#ifndef THIRD_LAB_JB_BMPLIB_BMPWRITING_H_
#define THIRD_LAB_JB_BMPLIB_BMPWRITING_H_

#endif //THIRD_LAB_JB_BMPLIB_BMPWRITING_H_

#include <string>

struct pixel {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  pixel(): r(0), g(0), b(0) {}
  pixel(uint8_t given_r, uint8_t given_g, uint8_t given_b): r(given_r), g(given_g), b(given_b) {}
};

void WriteInBMPFile(const std::string& file_name, int x, int y, pixel** pixel_matrix);