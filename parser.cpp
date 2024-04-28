#include "parser.h"
#include <raylib.h>

std::vector<Color> colorVec {BROWN, LIME, GOLD, GRAY, SKYBLUE, 
    PURPLE, VIOLET, BLUE, BLACK, RED};

// Used units
// Space  [Angstrom]
// Angle  [Degree]
// Volume [Angstrom^3]

void Lattice::parse_from(const json& j){
    j["lattice"]["matrix"].get_to(_vectors);
    j["lattice"]["a"].get_to(_a);
    j["lattice"]["b"].get_to(_b);
    j["lattice"]["c"].get_to(_c);
    j["lattice"]["alpha"].get_to(_alpha);
    j["lattice"]["beta"].get_to(_beta);
    j["lattice"]["gamma"].get_to(_gamma);
    j["lattice"]["volume"].get_to(_volume_conventional_cell);
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
        _label_atoms_map[tmp._label].push_back(tmp); 
        _sites.push_back(tmp);
    }
    
    // Set color of atoms. Atoms with different labels get unique colors.
    for(auto& [_, atoms] : _label_atoms_map){
        Color color = colorVec.back();
        colorVec.pop_back();
        for(auto& atom : atoms){
            atom._color.r = color.r;
            atom._color.g = color.g;
            atom._color.b = color.b;
            atom._color.a = color.a;
        }
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



/*void Compound::setColors(std::map<std::string, std::vector<Atom>> map){
    // Set color of each atom. Each label gets unique color
    for(auto& [_, atoms] : map){
        Color color = RED; //(Color) {(unsigned char) GetRandomValue(0, 255), 
                           //    (unsigned char) GetRandomValue(0, 255),
                            //   (unsigned char) GetRandomValue(0, 255), 255};
        for(auto& atom : atoms){
            atom._color.r = color.r;
            atom._color.g = color.g;
            atom._color.b = color.b;
            atom._color.a = color.a;
        }
    }
}*/
