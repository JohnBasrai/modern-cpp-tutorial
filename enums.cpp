#include <iostream>
#include <map>

enum class Fruit {Peach, Plum, Mango, Kiwi};

void eat(Fruit);

std::map<Fruit,std::string> const fruitToString
    {
        { Fruit::Peach, "Peach" },
        { Fruit::Plum,  "Plum"  },
        { Fruit::Mango, "Mango" },
        { Fruit::Kiwi,  "Kiwi"  }
    };
std::ostream& operator<<(std::ostream&out, Fruit f) { out << fruitToString.at(f); return out; }

int main()
{
    auto myLunch = Fruit::Peach;
    myLunch      = Fruit::Mango;
    auto Peach   = " and a juicy peach"; // const char*, not Fruit::Peach
    eat(myLunch);
    std::cout << Peach << std::endl;
    return 0;
}
void eat(Fruit fruit) { std::cout << "Eating a " << fruit; }


