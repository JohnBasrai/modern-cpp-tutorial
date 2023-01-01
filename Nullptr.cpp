
#include <memory>
struct Stream { void process(); };
using StreamPtr = std::shared_ptr<Stream>; // Old: typedef std::shared_ptr<Stream> StreamPtr;

void process()
{
    StreamPtr aStream = nullptr;
    if( aStream != nullptr )
        aStream->process();
}
int main(){return 0;}
