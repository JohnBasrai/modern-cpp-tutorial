
#include "demo.h"
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T> auto seq_begin(const T & t) -> decltype(&t[0])
{
    return &t[0];
}

template<typename T> auto seq_end(const T & t)   -> decltype(&t[0])
{
    return seq_begin(t) + t.length();
}

int sum(const ::BeginEnd::DoubleSeq& args)
{
    double tally{0};
    for_each(seq_begin(args), seq_end(args),
                  [&tally](const double value) {tally += value;});
    return tally;
}

int main(int ac, char *av[])
{
    ::BeginEnd::DoubleSeq seq;
    seq.length(5);

    size_t index{};

    for(const double value : {1.0, 2.0, 3.0, 4.0, 5.0})
    {
        seq[index++] = value;
    }
    cout << "BEG::" << (seq_begin(seq) - &seq[0])
              << " END:" << (seq_end(seq)   - &seq[0]) << endl;

    cout << "Tally is " << sum(seq) << endl;
}


