#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_
#include <unordered_map>
#include <string>
class Fixture {
public:
        
protected:
    std::string name;
    std::unordered_map <std::string, unsigned char> channels;
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
