// strings and c-strings
#include <iostream>
#include <cstring>
#include <string>

int main ()
{
  std::string str ("        Please split this sentence into tokens    ");
  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

  char * p = std::strtok (cstr," ");
  std::cout<<p<<std::endl;
  while (p!=0)
  {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
  }

  delete[] cstr;
  return 0;
}
