#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    const std::string books[] = 
        {
         "Prelude to Foundation (1988)",
         "Forward the Foundation (1993)",
         "Foundation (1951)",
         "Foundation and Empire (1952)",
         "Second Foundation (1953)",
         "Foundation's Edge (1981)",
         "Foundation and Earth (1986)"
        };

    const auto end = std::end(books);
    for(auto iter  = std::begin(books); iter != end; ++iter)
    {
        std::cout << *iter << '\n';
    }
}


