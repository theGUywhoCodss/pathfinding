/*******************************************************************************************
 *
 *   raylib [core] example - Basic 3d example
 *
 *   Welcome to raylib!
 *
 *   To compile example, just press F5.
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
 *
 *   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
// https://github.com/raylib-extras/examples-c/blob/main/ray2d_rect_intersection/ray2d_rect_intersection.c
#include "raylib.h"
#include <stdio.h>
#include "string.h"
#include "node.h"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void); // Update and draw one frame
//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    //feiufuierfhreiufifheifreiufhreiufhruifeuifreiuf
    //asfdsfdsafdasfdsfadsfsffs
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Template");
    generateNodes((Vector2){600,600});
    runNodes();
    printf("hi");
    //--------------------------------------------------------------------------------------
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(0, 0);
    drawNodes();
    EndDrawing();
}