# A*寻路算法大作业

## Getting Started

These instructions will get you a copy of the project up and running on your local
machine for development and testing purposes.

### Prerequisites

This project is meant to be only a template, thus versions of the software used
can be change to better suit the needs of the developer(s). If you wish to use the
template *as-is*, meaning using the versions recommended here, then you will need:

* **CMake v3.15+** - found at [https://cmake.org/](https://cmake.org/)

* **C++ Compiler** - needs to support at least the **C++17** standard, i.e. *MSVC*,
*GCC*, *Clang*

> ***Note:*** *You also need to be able to provide ***CMake*** a supported
[generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).*

### Installing

It is fairly easy to install the project, all you need to do is clone if from
[Gitee](https://gitee.com/fun-sun/iTraining).

If you wish to clone the repository, rather than generate from it, you simply need
to run:

```bash
git clone https://gitee.com/fun-sun/iTraining
```

测试C++大作业：
```bash
cmake --build build --config Release
build/test/tmp_test_Tests 
```
标准测试提供了三个样例，前两个可以通过，第三个无法到达终点因此无法通过
随机测试有可能无法通过

## Generating the documentation
暂无

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our how you can
become a contributor and the process for submitting pull requests to us.

## Authors

* **黄山** - [@sparklesea](https://github.com/sparklesea)

## License

This project is licensed under the [Unlicense](https://unlicense.org/) - see the
[LICENSE](LICENSE) file for details
