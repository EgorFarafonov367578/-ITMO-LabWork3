//
// Created by User on 12.10.2022.
//

#ifndef THIRD_LAB_JB_CORE_SANDMODEL_H_
#define THIRD_LAB_JB_CORE_SANDMODEL_H_

#endif //THIRD_LAB_JB_CORE_SANDMODEL_H_

#include <cstdint>
#include <fstream>
#include <string>
#include <set>
#include <queue>

class SandModel {
 private:
  uint32_t ** matrix;
  uint16_t x;
  uint16_t y;
  std::queue<std::pair<int16_t,int16_t>>* dangerous_points;
  bool** matrix_of_iterated;
  uint16_t x0;
  uint16_t y0;
 public:
  SandModel(int given_x, int given_y): x(given_x), y(given_y), x0(0), y0(0), dangerous_points(new std::queue<std::pair<int16_t,int16_t>>()) {
    matrix = new uint32_t*[x];
    for (int i = 0; i < x; i++) {
      matrix[i] = new uint32_t[y];
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        matrix[i][j] = 0;
      }
    }
    matrix_of_iterated = new bool*[x];
    for (int i = 0; i < x; i++) {
      matrix_of_iterated[i] = new bool[y];
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        matrix_of_iterated[i][j] = false;
      }
    }
  }
  bool Iterastion();
  void Load(const std::string& file_name);
  void MakeCleanPicture(const std::string& file_name);
  void UpdateUpX (int new_levels);
  void UpdateDownX (int new_levels);
  void UpdateRightY(int new_levels);
  void UpdateLeftY(int new_levels);
};
