
#include <memory>      // std::unique_ptr
#include <functional>  // std::function<>
#include <stdio.h>     // FILE
#include <iostream>
#include <string.h>

template<typename T>
using deleted_unique_ptr = std::unique_ptr<T,std::function<void(T*)>>;
using FILE_PTR = deleted_unique_ptr<FILE>;

int main()
{
    FILE_PTR file {
        fopen("file.txt", "r"),          // Open a file
        [](FILE* f) { if(f) fclose(f); }}; // exception safe auto-close

    if (not file)
    {
        std::cerr << "Error opening file:" << strerror(errno);
        return 1;
    }
    
    char buf[10];

    if (file) // check if OK.
    {
        fgets(buf, sizeof(buf), &* file );
        fgets(buf, sizeof(buf), file.get() );
    }
}


