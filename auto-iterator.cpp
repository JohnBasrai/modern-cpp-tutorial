#include <list>
#include <string>


bool isReadyStream(const std::string & strm)
{
    // Logic to see if stream is ready;
    return true;
}

using StreamList = std::list<std::string>;

StreamList getReadyStreams(const StreamList& streams)
{
    std::list<std::string> result;

    for (StreamList::const_iterator scan = streams.begin(); scan != streams.end(); ++scan) { }
    // Or with auto...
    for (auto scan = streams.begin(); scan != streams.end(); ++scan) {}
    return result;
}

int main()
{
    StreamList streams; // = getStreams()
    const StreamList ready1 = getReadyStreams(streams);
}
