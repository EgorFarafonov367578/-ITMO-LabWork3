//
// Created by User on 11.10.2022.
//

#include <string>
#include <fstream>

#include "..\MainHeader.h"

void WriteIn4BytesLittleEndian(std::ofstream& file, int num) {
  file << uint8_t(num % 256) << uint8_t((num >> 8) % 256) << uint8_t((num >> 16) % 256) << uint8_t((num >> 24) % 256);
}

void WriteBINMAPFILEHEADER(std::ofstream& file,int file_size, int referense_to_array) {
  file << "BM";
  WriteIn4BytesLittleEndian(file, file_size);
  WriteIn4BytesLittleEndian(file, 0);
  WriteIn4BytesLittleEndian(file, referense_to_array);
}

void WriteBINPAMCOREHEADER(std::ofstream& file, int x, int y) {
  WriteIn4BytesLittleEndian(file,40);
  WriteIn4BytesLittleEndian(file,x);
  WriteIn4BytesLittleEndian(file,y);
  file << uint8_t (1) << uint8_t (0);
  file << uint8_t (24) << uint8_t (0);
  WriteIn4BytesLittleEndian(file,0);
  int size = (3 * x + (y % 4)) * y;
  WriteIn4BytesLittleEndian(file,size);
  WriteIn4BytesLittleEndian(file,2835);
  WriteIn4BytesLittleEndian(file,2835);
  WriteIn4BytesLittleEndian(file,0);
  WriteIn4BytesLittleEndian(file,0);
}

void WritePixelMatrix(std::ofstream& file, int x, int y, pixel** pixel_matrix) {
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      pixel pi = pixel_matrix[i][j];
      file << uint8_t (pi.b) << uint8_t (pi.g) << uint8_t (pi.r);
    }
    for (int w = 0; w < (x % 4); w++) {
      file << uint8_t (0);
    }
  }
}

void WriteInBMPFile(const std::string& file_name, int x, int y, pixel** pixel_matrix) {
  std::ofstream file(file_name,std::ios::binary);
  if (!file.is_open()) {
    std::cout << "File is broken" << std::endl;
  }
  WriteBINMAPFILEHEADER(file,54 + (3 * x + (y % 4)) * y,54);
  WriteBINPAMCOREHEADER(file, x, y);
  WritePixelMatrix(file, x, y, pixel_matrix);
  file.close();
}
