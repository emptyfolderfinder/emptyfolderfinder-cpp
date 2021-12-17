#include "helper.hpp"
#include <iostream>

namespace helpers {
  void printHelpMessage()
  {
    std::cout << "Usage: emptyfolderfinder [-d] <Path>" << std::endl;
    std::cout << "-d: Delete folders" << std::endl;
  }

  void printDirectories(std::vector<std::string> dirs)
  {
    for (std::string dir : dirs) {
      std::cout << dir << std::endl;
    }
  }
}