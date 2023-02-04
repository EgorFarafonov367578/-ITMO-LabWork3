//
// Created by User on 12.10.2022.
//

#include <fstream>
#include <vector>
#include <queue>

#include "../MainHeader.h"

void SandModel::UpdateUpX (int new_levels) {
  uint32_t** new_matrix;
  bool** new_matrix_of_iterated;
  new_matrix = new uint32_t*[x+new_levels];
  new_matrix_of_iterated = new bool*[x+new_levels];
  for (int i = 0; i < (x+new_levels); i++) {
    new_matrix[i] = new uint32_t[y];
  }
  for (int i = 0; i < (x+new_levels); i++) {
    new_matrix_of_iterated[i] = new bool[y];
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[i+new_levels][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[i+new_levels][j] = matrix_of_iterated[i][j];
    }
  }
  for (int i = 0; i < new_levels; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < new_levels; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[i][j] = false;
    }
  }
  for (int i = 0; i < x; i++)
  {
    delete matrix[i];
    delete matrix_of_iterated[i];
  }
  delete matrix;
  delete matrix_of_iterated;
  x = x + new_levels;
  x0 = x0 + new_levels;
  matrix = new_matrix;
  matrix_of_iterated = new_matrix_of_iterated;
}

void SandModel::UpdateDownX (int new_levels) {
  uint32_t** new_matrix;
  bool** new_matrix_of_iterated;
  new_matrix = new uint32_t*[x+new_levels];
  new_matrix_of_iterated = new bool*[x+new_levels];
  for (int i = 0; i < (x+new_levels); i++) {
    new_matrix[i] = new uint32_t[y];
  }
  for (int i = 0; i < (x+new_levels); i++) {
    new_matrix_of_iterated[i] = new bool[y];
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[i][j] = matrix_of_iterated[i][j];
    }
  }
  for (int i = 0; i < new_levels; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[x + i][j] = 0;
    }
  }
  for (int i = 0; i < new_levels; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[x + i][j] = false;
    }
  }
  for (int i = 0; i < x; i++)
  {
    delete matrix[i];
    delete matrix_of_iterated[i];
  }
  delete matrix;
  delete matrix_of_iterated;
  x = x + new_levels;
  matrix = new_matrix;
  matrix_of_iterated = new_matrix_of_iterated;
}

void SandModel::UpdateRightY(int new_levels) {
  uint32_t** new_matrix;
  bool** new_matrix_of_iterated;
  new_matrix = new uint32_t*[x];
  new_matrix_of_iterated = new bool*[x];
  for (int i = 0; i < x; i++) {
    new_matrix[i] = new uint32_t[y+new_levels];
  }
  for (int i = 0; i < x; i++) {
    new_matrix_of_iterated[i] = new bool[y+new_levels];
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[i][j] = matrix_of_iterated[i][j];
    }
  }
  for (int j = 0; j < new_levels; j++) {
    for (int i = 0; i < x; i++) {
      new_matrix[i][y + j] = 0;
    }
  }
  for (int j = 0; j < new_levels; j++) {
    for (int i = 0; i < x; i++) {
      new_matrix_of_iterated[i][y + j] = false;
    }
  }
  for (int i = 0; i < x; i++)
  {
    delete matrix[i];
    delete matrix_of_iterated[i];
  }
  delete matrix;
  delete matrix_of_iterated;
  y = y + new_levels;
  matrix = new_matrix;
  matrix_of_iterated = new_matrix_of_iterated;
}

void SandModel::UpdateLeftY(int new_levels) {
  uint32_t** new_matrix;
  bool** new_matrix_of_iterated;
  new_matrix = new uint32_t*[x];
  new_matrix_of_iterated = new bool*[x];
  for (int i = 0; i < x; i++) {
    new_matrix[i] = new uint32_t[y+new_levels];
  }
  for (int i = 0; i < x; i++) {
    new_matrix_of_iterated[i] = new bool[y+new_levels];
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix[i][j+new_levels] = matrix[i][j];
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      new_matrix_of_iterated[i][j+new_levels] = matrix_of_iterated[i][j];
    }
  }
  for (int j = 0; j < new_levels; j++) {
    for (int i = 0; i < x; i++) {
      new_matrix[i][j] = 0;
    }
  }
  for (int j = 0; j < new_levels; j++) {
    for (int i = 0; i < x; i++) {
      new_matrix_of_iterated[i][j] = false;
    }
  }
  for (int i = 0; i < x; i++)
  {
    delete matrix[i];
    delete matrix_of_iterated[i];
  }
  delete matrix;
  delete matrix_of_iterated;
  y = y + new_levels;
  y0 = y0 + new_levels;
  matrix = new_matrix;
  matrix_of_iterated = new_matrix_of_iterated;
}

bool SandModel::Iterastion() {
  bool changes = false;
  std::queue<std::pair<int16_t,int16_t>>* new_dangerous_points = new std::queue<std::pair<int16_t,int16_t>>();
  std::queue<std::pair<int16_t,int16_t>> old_dangerous_points;
  while (!(*dangerous_points).empty()) {
    std::pair<int16_t, int16_t> point = (*dangerous_points).front();
    (*dangerous_points).pop();
    int nx = point.first;
    int ny = point.second;
    if (nx + x0 + 1 >= x) {
      UpdateDownX(1);
    }
    if (nx + x0 - 1 < 0) {
      UpdateUpX(1);
    }
    if (ny + y0 + 1 >= y) {
      UpdateRightY(1);
    }
    if (ny + y0 - 1 < 0) {
      UpdateLeftY(1);
    }
    if ((matrix[nx+x0][ny+y0] >= 4) && (matrix_of_iterated[nx+x0][ny+y0] == false)) {
      matrix_of_iterated[nx+x0][ny+y0] = true;
      matrix[nx+x0][ny+y0] -=4;
      matrix[nx+x0+1][ny+y0] +=1;
      matrix[nx+x0-1][ny+y0] +=1;
      matrix[nx+x0][ny+y0+1] +=1;
      matrix[nx+x0][ny+y0-1] +=1;
      old_dangerous_points.push(point);
      if (matrix[nx + x0][ny + y0] >= 4) (*new_dangerous_points).push(std::make_pair(nx,ny));
      if (matrix[nx + x0 + 1][ny + y0] >= 4) (*new_dangerous_points).push(std::make_pair(nx+1,ny));
      if (matrix[nx + x0 - 1][ny + y0] >= 4) (*new_dangerous_points).push(std::make_pair(nx-1,ny));
      if (matrix[nx + x0][ny + y0 + 1] >= 4) (*new_dangerous_points).push(std::make_pair(nx,ny+1));
      if (matrix[nx + x0][ny + y0 - 1] >= 4) (*new_dangerous_points).push(std::make_pair(nx,ny-1));
      changes = true;
    }
  }
  delete dangerous_points;
  dangerous_points = new_dangerous_points;
  while (!old_dangerous_points.empty()) {
    std::pair<int16_t, int16_t> point = old_dangerous_points.front();
    old_dangerous_points.pop();
    int nx = point.first;
    int ny = point.second;
    matrix_of_iterated[nx+x0][ny+y0] = false;
  }
  return changes;
}

void SandModel::Load(const std::string& file_name) {
  std::ifstream file(file_name, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "File is broken" << std::endl;
  }
  int nx;
  int ny;
  int amount;
  while (file >> nx)
  {
    file >> ny;
    file >> amount;
    if (x0 + nx >= x)
    {
      UpdateDownX(x0 + nx - x + 1);
    }
    if (x0 + nx < 0)
    {
      UpdateUpX(-(x0 + nx));
    }
    if (y0 + ny >= y)
    {
      UpdateRightY(y0 + ny - y + 1);
    }
    if (y0 + ny <= 0)
    {
      UpdateLeftY(-(y0 + ny));
    }
    matrix[x0+nx][y0+ny] += amount;
    if (matrix[x0+nx][y0+ny] >= 4) (*dangerous_points).push(std::make_pair(nx,ny));
  }
}


void SandModel::MakeCleanPicture(const std::string& file_name) {
  int x1 = x;
  int x2 = 0;
  int y1 = y;
  int y2 = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (matrix[i][j] > 0) {
        if (i < x1) {
          x1 = i;
        }
        if (i > x2) {
          x2 = i;
        }
        if (j < y1) {
          y1 = j;
        }
        if (j > y2) {
          y2 = j;
        }
      }
    }
  }
  pixel** pixel_matrix;
  pixel_matrix = new pixel*[x2 - x1 + 1];
  for (int i = 0; i < x2 - x1 + 1; i++) {
    pixel_matrix[i] = new pixel[y2 - y1 + 1];
  }
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      switch (matrix[i][j]) {
        case (0):
          pixel_matrix[i - x1][j - y1] = pixel(255,255,255);
          break;
        case(1):
          pixel_matrix[i - x1][j - y1] = pixel(0,255,0);
          break;
        case(2):
          pixel_matrix[i - x1][j - y1] = pixel(255,0,255);
          break;
        case(3):
          pixel_matrix[i - x1][j - y1] = pixel(255,255,0);
          break;
        default:
          pixel_matrix[i - x1][j - y1] = pixel(0,0,0);
          break;
      }
    }
  }
  WriteInBMPFile(file_name, x2 - x1 + 1, y2 - y1 + 1, pixel_matrix);
}
