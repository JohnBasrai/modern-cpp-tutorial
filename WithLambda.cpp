#include <algorithm>
#include <functional>
#include <vector>

struct TableEntry { int value; };
using TableType = std::vector<TableEntry>;
TableType theTable;

const TableEntry * findValueFor(const int toFind)
{
    TableType::const_iterator iter = 
        std::find_if(theTable.begin(),
                     theTable.end(), [toFind](const TableEntry & entry) -> bool
                     {
                         return entry.value == toFind; // found it
                     });

    return iter != theTable.end() ? &(*iter) : nullptr;
}

int main(){
    findValueFor(34);
    []{};
    []{}();
}
