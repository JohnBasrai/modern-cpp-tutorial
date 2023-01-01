#include <algorithm>
#include <functional>
#include <vector>
struct TableEntry { int value; };
typedef std::vector<TableEntry> TableType;
TableType theTable;

class FindMatchFunction : public std::unary_function<const TableEntry, bool>
{
public:
    FindMatchFunction(const int toFind) : theValueToFind(toFind) {}
    bool operator()(const TableEntry & val) const {return val.value == theValueToFind;}
private:
    const int theValueToFind;
};

const TableEntry * findValueFor(int toFind)
{
    const FindMatchFunction mySearchCrit(toFind);
    TableType::const_iterator iter =
        std::find_if(theTable.begin(), theTable.begin(), mySearchCrit);
    if( iter != theTable.end() ) { return &(*iter); } // found it }
    return nullptr;
}

int main(){ findValueFor(34); }

