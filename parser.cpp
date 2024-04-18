#include "parser.h"

// Used units
// Space  [Angstrom]
// Angle  [Degree]
// Volume [Angstrom^3]

void Lattice::parse_from(const json& j){
    j.at("lattice").at("matrix").get_to(_vectors);
    j.at("lattice").at("a").get_to(_a);
    j.at("lattice").at("b").get_to(_b);
    j.at("lattice").at("c").get_to(_c);
    j.at("lattice").at("alpha").get_to(_alpha);
    j.at("lattice").at("beta").get_to(_beta);
    j.at("lattice").at("gamma").get_to(_gamma);
    j.at("lattice").at("volume").get_to(_volume_conventional_cell);
}

void Lattice::print_info(){

    std::cout << "\nLattice Vectors:\n";
    for(const auto& row : _vectors){
        std::cout << "[";
        for(const auto& elem : row){
            std::cout << elem;
            if(&elem != &(row[2])) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    std::cout << "\nLattice Parameters:\n";
    
    std::cout << "a, b, c (Angstrom): " << _a << ", " << _b << ", " << _c << '\n';
    std::cout << "alpha, beta, gamma (Degree): " << _alpha << ", " << _beta << ", " << _gamma << '\n';
    
    std::cout << "\nVolume of conventional unit cell (Angstrom^3): " 
        << _volume_conventional_cell << "\n";

}

void Compound::parse_from(const json& j, std::string filename){
    _lattice.parse_from(j);
    
    // get name of json file by removing file extension.
    size_t lastindex = filename.find_last_of("."); 
    _name = filename.substr(0, lastindex); 

    for(const auto& elem : j["sites"]){
        Atom tmp;
        elem["label"].get_to(tmp._label);
        elem["xyz"].get_to(tmp._position);
        _sites.push_back(tmp);
    }
}

void Compound::print_info(){
    
    std::cout << "\nChemical compound: " << _name << '\n';
    
    _lattice.print_info();

    std::cout << "\nIon, Position (Angstrom)\n";
    for(const auto& site : _sites){
        std::cout << site._label << ", ";
        std::cout << "[";
        for(const auto& elem : site._position){
            std::cout << elem;
            if(&elem != &(site._position[2])) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    std::cout << '\n';
}
