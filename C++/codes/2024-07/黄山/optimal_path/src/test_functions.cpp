#include "project/obstacle_map.hpp"

bool main_path_finding(bool isCase)
{  // 是否使用示例
  srand(static_cast<unsigned int>(time(0)));

  if (isCase)
  {  // 使用默认示例
    std::vector<std::vector<std::string>> pathList{
      { "./test/test_case/origin1.txt", "./test/test_case/ref1.txt" },
      { "./test/test_case/origin2.txt", "./test/test_case/ref2.txt" },
      { "./test/test_case/origin3.txt", "./test/test_case/ref3.txt" }
    };
    for (int i = 0; i < pathList.size(); ++i)
    {
      const std::string orginpath = pathList[i][0];
      const std::string refpath = pathList[i][1];
      obstacleMap::strMap originMap;
      obstacleMap::strMap referenceMap;
      readCases(orginpath, refpath, originMap, referenceMap);
      std::cout << "Start Standard test " << i + 1 << ":\n";
      if (test_case(originMap, referenceMap) == false)
      {
        return false;
      }
    }
    return true;
  }
  else  // 使用随机生成的map
  {
    obstacleMap map(true);
    obstacleMap::strMap temp;
    map.toStringMap(temp);

    std::cout << "Origin Map:\n";
    showStrMap(temp);
    if (map.pathFinding())
    {
      map.pathAnnotation();
    }
    else
    {
      std::cout << "there is no accessible path!" << std::endl;
      return false;
    }
    obstacleMap::strMap resultMap;
    map.toStringMap(resultMap);
    std::cout << "The map and its result path are as follows:\n";
    showStrMap(resultMap);
  }
  return true;
}

bool test_case(const obstacleMap::strMap& originMap, const obstacleMap::strMap& referenceMap)
{
  std::cout << "Origin Map:\n";
  showStrMap(originMap);

  obstacleMap map(originMap);
  if (map.pathFinding())
  {
    map.pathAnnotation();
  }
  else
  {
    std::cout << "there is no accessible path!" << std::endl;
    return false;
  }

  obstacleMap::strMap resultMap;
  map.toStringMap(resultMap);

  std::cout << "The map and its result path are as follows:\n";
  showStrMap(resultMap);

  return isSame(referenceMap, resultMap);
}

void readCases(
    const std::string& originPath,
    const std::string& refPath,
    obstacleMap::strMap& originMap,
    obstacleMap::strMap& refMap)
{
  std::ifstream originFile(originPath);
  std::ifstream refFile(refPath);
  if (originFile.is_open())
  {
    std::string line;
    while (std::getline(originFile, line))
    {
      originMap.push_back(line);
    }
    originFile.close();
  }
  else
  {
    std::cerr << "无法打开文件: " << originPath << std::endl;
  }

  if (refFile.is_open())
  {
    std::string line;
    while (std::getline(refFile, line))
    {
      refMap.push_back(line);
    }
    refFile.close();
  }
  else
  {
    std::cerr << "无法打开文件: " << refPath << std::endl;
  }
}