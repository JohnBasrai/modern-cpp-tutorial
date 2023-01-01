
struct Stream
{
    int a;
    void process(){};
};
Stream streams[] = {0,1,2,3};
void process()
{
    for(auto s : streams)
    {
        s.process();
    }
}
    
int main(){return 0;}
