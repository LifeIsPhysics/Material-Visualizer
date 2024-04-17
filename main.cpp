#include<iostream>
#include<fstream>

#include<nlohmann/json.hpp>
using json = nlohmann::json;

#include "configureFile.h"

class Lattice{
};

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout << "Material Visualizer Version " << VERSION_MAJOR << '.' << VERSION_MINOR << '\n';
        std::cout << "Usage: " << argv[0] << " <rel-filepath-of-json>" << '\n';
        return 1;
    }
    
    std::ifstream file(argv[1]);
    
    json data;

    return 0;
}
