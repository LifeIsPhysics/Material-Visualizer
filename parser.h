#ifndef PARSER_H
#define PARSER_H

#include <nlohmann/json.hpp>

#include <array>
#include <iomanip>
#include <iostream>

// Used units
// Space  [Angstrom]
// Angle  [Degree]
// Volume [Angstrom^3]

using json = nlohmann::json; 
using Matrix3d = std::array<std::array<double, 3>, 3>;
using Vector3d = std::array<double, 3>;
using Space = double;
using Angle = double;
using Volume = double;
using Elements = std::vector<std::string>;

class Lattice{
private:
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
};

class Compound{
private:
    std::vector<Atom> _sites;
    Lattice _lattice;
    std::string _name;

public:
    void parse_from(const json& j, std::string filename);
    void print_info();
};

#endif //PARSER_H
