# modern-cpp-tutorial
An Introductory Tutorial for Modern C++

# BUILD

`$ conan profile update settings.compiler.libcxx=libstdc++11 default`
`$ rm -rf build ; mkdir build ; cd build`
`$ conan install ..`
`$ cmake ..`
`$ make`

