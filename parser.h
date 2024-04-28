#ifndef PARSER_H
#define PARSER_H

#include <compare>
#include <map>
#include <nlohmann/json.hpp>
#include <raylib.h>

#include <array>
#include <iomanip>
#include <iostream>
#include <unordered_map>

// Used units
// Space  [Angstrom]
// Angle  [Degree]
// Volume [Angstrom^3]

using json = nlohmann::json; 
using Matrix3d = std::array<std::array<float, 3>, 3>;
using Vector3d = std::array<float, 3>;
using Space = float;
using Angle = float;
using Volume = float;
using Elements = std::vector<std::string>;



class Lattice{
public:
    Matrix3d _vectors;
    Space _a, _b, _c;
    Angle _alpha, _beta, _gamma;
    Volume _volume_conventional_cell;

public:
    void parse_from(const json& j);
    void print_info();
};

struct Atom{
    std::string _label;
    Vector3d _position;
    Color _color;
};

class Compound{
public:
    std::vector<Atom> _sites;
    std::unordered_map<std::string, std::vector<Atom>> _label_atoms_map;
    Lattice _lattice;
    std::string _name;

public:
    void parse_from(const json& j, std::string filename);
    void print_info();
    //std::map<std::string, std::vector<Atom>> getMap() const;
    //void setColors(std::map<std::string, std::vector<Atom>> map);
};

#endif //PARSER_H
