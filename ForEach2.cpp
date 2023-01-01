#include <vector>
struct LargeStream
{
    int a[2096];
    void process();             // process 1
    void process() const;       // process 2
};
LargeStream streams[] = {{0},{1},{2},{3}};

void process_1()
{
    for(auto & s : streams)
        s.process();
}

void process_2()
{
    for(const auto & s : streams)
        s.process();
}
int main(){return 0;}
void LargeStream::process(){}
void LargeStream::process() const{}
