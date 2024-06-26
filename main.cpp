#include "configureFile.h"
#include "parser.h"
#include "visualizer.h"

#include <nlohmann/json.hpp>
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <raymath.h>
#include <string>


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
    
    Compound comp;
    comp.parse_from(data, argv[1]);
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    const std::string window_title = "Material Visualizer " + std::to_string(VERSION_MAJOR) + "." 
        + std::to_string(VERSION_MINOR);
    
    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    InitWindow(screenWidth, screenHeight, window_title.c_str());
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawCubeWires(Vector3Zero(), comp._lattice._a, comp._lattice._b, comp._lattice._c, GRAY);
                DrawCompound(comp);
            EndMode3D();

            

            //DrawText(comp._name.c_str(), 20, 20, 10, BLACK);
            int xPos = 20;
            int yPos = 20;
            for(const auto& [label,atom] : comp._label_atoms_map){
                DrawText(label.c_str(), xPos, yPos, 10, atom[0]._color);
                yPos += 20;
            }
            DrawRectangle(10, 10, 80, yPos-10, Fade(LIGHTGRAY, 0.5f));
            DrawRectangleLines( 10, 10, 80, yPos-10, GRAY);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
