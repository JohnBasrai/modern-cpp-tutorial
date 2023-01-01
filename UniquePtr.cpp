#include <memory>      // std::unique_ptr
#include <functional>  // std::function<>
#include <stdio.h>     // FILE

template<typename T>
using deleted_unique_ptr = std::unique_ptr<T,std::function<void(T*)>>;
using FILE_PTR = deleted_unique_ptr<FILE>;

int main()
{
    FILE_PTR file(
        fopen("file.txt", "r"),          // Open a file
        [](FILE* f) { if(f) fclose(f); } // exception safe auto-close
    );
    char buf[10];
    if(file) fgets(buf, sizeof(buf), &* file );
}

struct X { X(int){} };
X x1(0);
X x2 = X(0);


