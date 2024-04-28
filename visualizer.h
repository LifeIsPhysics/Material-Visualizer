#ifndef VISUALIZER_H
#define VISUALIZER_H


#include "parser.h"
#include <raylib.h>
#include <raymath.h>


Vector3 getCenterOfVecs(const Compound& compound);
void DrawCompound(const Compound& compound);

#endif /* VISUALIZER_H */
