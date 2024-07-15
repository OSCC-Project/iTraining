# 设置CMake的最低版本要求  
cmake_minimum_required(VERSION 3.10)  
  
# 设置项目名称和版本  
project(MyWineProject VERSION 1.0)  
  
# 设置C++标准  
set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED True)  
  
# 添加可执行文件  
add_executable(myapp main.cpp Port.cpp VintagePort.cpp)  
  
# 如果你的项目更复杂，可能需要更详细的设置，比如：  
# 查找库、设置包含目录、链接库等  
# 但对于这个简单的例子，上面的 add_executable 就足够了  
  
# 如果你有头文件，通常不需要在 CMakeLists.txt 中特别指定它们，  
# 因为编译器在编译源文件时会自动查找它们（只要它们位于正确的包含路径中）。  
# 但是，如果你的头文件位于非标准位置，你可以使用 include_directories() 来指定它们。  
# 例如：  
# include_directories(${CMAKE_SOURCE_DIR}/include)  
# 注意：在这个例子中，我们不需要这样做，因为头文件和源文件都在同一目录下。