#include "parser.h"
#include <raylib.h>
#include <raymath.h>

void DrawCompound(const Compound& compound){
    for(const auto& atom: compound._sites){
        Vector3 centerPos = {atom._position[0], atom._position[1], atom._position[2]};
        DrawSphere(centerPos, 0.3, RED);
    }
}

Vector3 getCenterPos(const Compound& compound){
    Vector3 centerPos;
    for(const auto& atom: compound._sites){
        centerPos.x += atom._position[0];
        centerPos.y += atom._position[1];
        centerPos.z += atom._position[2];
    }

    return Vector3Scale(centerPos, 1 / (float)compound._sites.size());
}
