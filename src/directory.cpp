#include "directory.hpp"
#include <filesystem>
#include <iostream>

std::vector<std::string> checkDirectory(std::string path)
{
  std::vector<std::string> result;
  std::vector<std::string> emptyDirs;
  std::vector<std::string> dirs;
  std::vector<std::string> files;

  for (auto& file : std::filesystem::directory_iterator(path)) 
  {
    std::string filePath = file.path().generic_string();

    if (std::filesystem::is_directory(file)) 
    {
      dirs.push_back(filePath);
      
      emptyDirs = checkDirectory(filePath);

      for (std::string dir : emptyDirs)
      {
        result.push_back(dir);
      }
    }
    else
    {
      files.push_back(filePath);
    }
  }

  if (files.size() == 0 && dirs.size() == 0)
  {
    result.push_back(path);
    return result;
  }

  if (result.size() == dirs.size() && files.size() == 0) 
  {
    result.push_back(path);
    return result;
  }

  return result;  
}

void deleteDirectories(std::vector<std::string> dirs)
{
  for (std::string dir : dirs) {
    std::filesystem::remove(dir);
  }
}
