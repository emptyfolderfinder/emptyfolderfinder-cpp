#include <iostream>
#include "helper.hpp"
#include "directory.hpp"

int main(int argc, char** argv) 
{
  bool del = false;
  std::string path = "";
  std::vector<std::string> dirs;

  if (argc < 2)
  {
    helpers::printHelpMessage();
    return 0;
  }

  if (strcmp(argv[1], "-d") == 0)
  {
    if (argc != 3)
    {
      helpers::printHelpMessage();
      return 0;
    }

    del = true;
    path = argv[2];
  }
  else
  {
    path = argv[1];
  }

  dirs = checkDirectory(path);

  if (dirs.size() == 0) 
  {
    std::cout << "No empty directories found" << std::endl;
    return 0;
  }

  if (del)
  {
    deleteDirectories(dirs);

    std::cout << "Deleted the following directories" << std::endl;

    helpers::printDirectories(dirs);
  }
  else
  {
    helpers::printDirectories(dirs);
  }
  
  return 0;
}
