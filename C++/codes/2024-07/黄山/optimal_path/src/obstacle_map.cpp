#include "project/obstacle_map.hpp"

obstacleMap::obstacleMap(bool israndom) : _map(), _open_list(), _closed_list(), _isAccessible(false)
{
  this->_map.resize(WIDTH);  // 调用Node默认构造函数
  if (israndom)
  {  // 生成随机地图
    for (size_t i = 0; i < WIDTH; ++i)
    {
      for (size_t j = 0; j < WIDTH; ++j)
      {
        int random = std::rand() % 100;
        if (random < 30)
        {
          this->_map[i].emplace_back(i, j, (i + WIDTH - 1 - j) * 10, true);
        }
        else
        {
          this->_map[i].emplace_back(i, j, (i + WIDTH - 1 - j) * 10, false);
        }
      }
    }
  }
  this->_map[0][WIDTH - 1].isBlock = false;  // 起点终点不是障碍
  this->_map[WIDTH - 1][0].isBlock = false;

  auto cmp = [this](const Node* a, const Node* b) { return a->F_value > b->F_value; };
  this->_open_list = std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>>(cmp);
}

obstacleMap::obstacleMap(const obstacleMap::strMap& input) : _map(), _open_list(), _closed_list(), _isAccessible(false)
{
  this->_map.resize(WIDTH);  // 先确保有WIDTH行
  for (size_t i = 0; i < WIDTH; ++i)
  {
    for (size_t j = 0; j < WIDTH; ++j)
    {
      if (input[i][2 * j] == '$')
      {
        this->_map[i].emplace_back(i, j, (i + WIDTH - 1 - j) * 10, true);
      }
      else if (input[i][2 * j] == '*')
      {
        this->_map[i].emplace_back(i, j, (i + WIDTH - 1 - j) * 10, false);
      }
      else
      {
        std::cerr << "错误输入，程序终止" << std::endl;
        std::exit(EXIT_FAILURE);
      }
    }
  }

  auto cmp = [this](const Node* a, const Node* b) { return a->F_value > b->F_value; };
  this->_open_list = std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>>(cmp);
}

obstacleMap::~obstacleMap()
{
}

// void obstacleMap::mapReconstruct(const obstacleMap::strMap& input)
// {
//   for (size_t i = 0; i < WIDTH; ++i)
//   {
//     for (size_t j = 0; j < WIDTH; ++j)
//     {  // 每次隔一个空格
//       if (input[i][2 * j] == '$')
//       {
//         this->_map[i][j].isBlock = true;
//       }
//       else if (input[i][2 * j] == '*')
//       {
//         this->_map[i][j].isBlock = false;
//       }
//       else
//       {
//         std::cerr << "错误输入，程序终止" << std::endl;
//         std::exit(EXIT_FAILURE);
//       }
//       this->_map[i][j].isPath = false;
//       this->_map[i][j].isOpen = false;
//       this->_map[i][j].fatherNode = nullptr;
//     }
//   }
// }

void obstacleMap::toStringMap(obstacleMap::strMap& string_map)
{
  for (size_t i = 0; i < WIDTH; ++i)
  {
    string_map.push_back(std::string(STRINGLENGTH - 1, ' '));  // 初始化为空字符串
    for (size_t j = 0; j < WIDTH; j++)
    {
      if (this->_map[i][j].isPath)
      {
        string_map[i][j * 2] = '#';
      }
      else if (this->_map[i][j].isBlock)
      {
        string_map[i][j * 2] = '$';
      }
      else
      {
        string_map[i][j * 2] = '*';
      }
    }
  }
}

bool obstacleMap::pathFinding()
{
  int row = WIDTH - 1, col = 0;                    // 当前节点坐标
  this->_open_list.push(&(this->_map[row][col]));  // 将起点放入openlist
  this->_map[row][col].isOpen = true;

  obstacleMap::Node* nodePtr;
  obstacleMap::Node* tmpNodePtr;
  while (this->_open_list.empty() != true)
  {
    nodePtr = this->_open_list.top();
    this->_open_list.pop();
    this->_closed_list.insert(nodePtr);
    row = nodePtr->_row;
    col = nodePtr->_col;
    if (row == 0 && col == WIDTH - 1)
    {
      return true;
    }
    int t_row, t_col, cost;  // temp row/col
    for (int i = 0; i < 8; ++i)
    {
      t_row = row + directions[0][i];
      t_col = col + directions[1][i];
      cost = directions[2][i];
      if (t_row >= 0 && t_row < WIDTH && t_col >= 0 && t_col < WIDTH)
      {
        tmpNodePtr = &(this->_map[t_row][t_col]);
        if (!(tmpNodePtr->isBlock) && (this->_closed_list.find(tmpNodePtr) == this->_closed_list.end()))
        {
          obstacleMap::neighbourSearch(tmpNodePtr, nodePtr, cost);
        }
      }
    }
  }
  return false;
}

void obstacleMap::pathAnnotation()
{
  std::stack<obstacleMap::Node*> path;
  obstacleMap::Node* nodePtr = &(this->_map[0][WIDTH - 1]);
  while (nodePtr)
  {
    path.push(nodePtr);
    nodePtr->isPath = true;
    nodePtr = nodePtr->fatherNode;
  }
  std::cout << "The result path is as follows: \n";
  while (!path.empty())
  {
    nodePtr = path.top();
    path.pop();
    std::cout << "(" << nodePtr->_row << ", " << nodePtr->_col << ")";
  }
  std::cout << "\n";
}

void obstacleMap::neighbourSearch(obstacleMap::Node* tmpNodePtr, obstacleMap::Node* nodePtr, int cost)
{
  auto cmp = [this](const Node* a, const Node* b) { return a->F_value > b->F_value; };
  if (tmpNodePtr->isOpen)
  {  // 在openlist里
    if (tmpNodePtr->G_value > nodePtr->G_value + cost)
    {  // G值比原来低
      tmpNodePtr->G_value = nodePtr->G_value + cost;
      tmpNodePtr->fatherNode = nodePtr;
      tmpNodePtr->F_value = tmpNodePtr->G_value + tmpNodePtr->H_value;
      std::make_heap(
          const_cast<Node**>(&(this->_open_list.top())),
          const_cast<Node**>(&(this->_open_list.top())) + this->_open_list.size(),
          cmp);  // 对priority_queue重新排序
    }
  }
  else
  {  // 不在openlist里
    tmpNodePtr->fatherNode = nodePtr;
    tmpNodePtr->isOpen = true;
    tmpNodePtr->G_value = nodePtr->G_value + cost;  // 根据父节点初始化G，F值
    tmpNodePtr->F_value = tmpNodePtr->G_value + tmpNodePtr->H_value;
    this->_open_list.push(tmpNodePtr);
  }
  // this->_closed_list.insert(tmpNodePtr);  // 无论如何都把closelist状态设为true
}

bool isSame(obstacleMap::strMap const& s1, obstacleMap::strMap const& s2)
{
  for (size_t i = 0; i < s1.size(); ++i)
  {
    if (s1[i] != s2[i])
    {
      std::cout << "Wrong path in " << i << " row: \n";
      std::cout << "ref: " << s1[i] << std::endl;
      std::cout << "our: " << s2[i] << std::endl;
      return false;
    }
  }
  return true;
}

void showStrMap(const obstacleMap::strMap& map)
{
  for (auto& string : map)
  {
    std::cout << string << std::endl;
  }
}