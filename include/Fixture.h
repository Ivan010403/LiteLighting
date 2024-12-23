#include <string>
#include <unordered_map>
#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_

class Fixture {
public:
        
protected:
    std::string name;
    std::unordered_map <std::string, unsigned char> channels;
};

int Sum_int_test(int a, int b);


#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_