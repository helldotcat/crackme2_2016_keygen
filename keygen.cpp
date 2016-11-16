#include <iostream>
#include <string>
using namespace std;

string keygen(int);
string getStr(int);

void main() {
  string str = "";
  std::cout << "Enter email:" << std::endl;
  std::cin >> str;

  const char* mail = str.c_str();
  
  int sum = 0;
  for (int i = 0; i < strlen(mail); i++) {
    sum += mail[i];
  }
  

  int x = sum ^ (mail[strlen(mail)-1] + ((mail[strlen(mail)-2] + ((mail[1] + (mail[0] << 8)) << 8)) << 8)) ^ 0xFEC0135A;
  std::cout << "Key:" << std::endl;
  std::cout << keygen(x) << std::endl;
  
  system("pause");

}

string keygen(int x) {
  string key = "";
  int g = (x & 0x1F) ^ 0xE;
  x = x >> 5;
  int f = (x & 0x1F) ^ 0x17 ^ 0xE;
  x = x >> 5;
  int e = (x & 0x1F) ^ 0xF ^ 0x17 ^ 0xE;
  x = x >> 5;
  int d = (x & 0x1F) ^ 0x1B ^ 0xF ^ 0x17 ^ 0xE;
  x = x >> 5;
  int c = (x & 0x1F) ^ 0xA ^ 0x1B ^ 0xF ^ 0x17 ^ 0xE;
  x = x >> 5;
  int b = (x & 0x1F) ^ 0xF ^ 0xA ^ 0x1B ^ 0xF ^ 0x17 ^ 0xE;
  x = x >> 5;
  int a = (x & 0x1F) ^ 0x3 ^ 0xF ^ 0xA ^ 0x1B ^ 0xF ^ 0x17 ^ 0xE;

  key = getStr(g);
  key = getStr(f) + key;
  key = getStr(e) + key;
  key = getStr(d) + key;
  key = getStr(c) + key;
  key = getStr(b) + key;
  key = getStr(a) + key;
  return key;
}

string getStr(int x) {
  string str = "";
  int first = x & 0xF;
  int sec = (x & 0xF0) >> 4;
  if (first >= 0 && first <= 9) {
    str += std::to_string(first);;
  } else {
    str = (char)(first + 55);
  }
  if (sec >= 0 && sec <= 9) {
    str = std::to_string(sec) + str;
  } else {
    str = (char)(sec + 55) + str;
  }

  return str;
}