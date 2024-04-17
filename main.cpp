#include "configureFile.h"
#include "parser.h"
#include<nlohmann/json.hpp>

#include<iostream>
#include<fstream>


using json = nlohmann::json;

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout << "Material Visualizer Version " << VERSION_MAJOR << '.' << VERSION_MINOR << '\n';
        std::cout << "Usage: " << argv[0] << " <rel-filepath-of-json>" << '\n';
        return 1;
    }
    
    std::ifstream file(argv[1]);
    
    json data;
    
    try{
        data = json::parse(file);
    } 
    catch (json::parse_error& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    Lattice lat;
    lat.parse_from(data);
    lat.print_info();

    return 0;
}
