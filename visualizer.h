#include "parser.h"
#include <raylib.h>
#include <raymath.h>

Vector3 getCenterOfVecs(const Compound& compound){
    Vector3 centerPos = Vector3Zero();
    for(const auto& atom: compound._sites){
        centerPos.x += atom._position[0];
        centerPos.y += atom._position[1];
        centerPos.z += atom._position[2];
    }

    return Vector3Scale(centerPos, 1 / (float)compound._sites.size());
}

void DrawCompound(const Compound& compound){
    Vector3 centerVecs = getCenterOfVecs(compound);

    for(const auto& atom: compound._sites){
        Vector3 temp = {atom._position[0], atom._position[1], atom._position[2]};
        Vector3 centerPos = Vector3Add(temp, Vector3Negate(centerVecs));
        DrawSphere(centerPos, 0.3, RED);
    }
}


