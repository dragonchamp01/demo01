#include "raylib.h"

#pragma comment(lib,"raylib.lib")
#pragma comment(lib,"winmm.lib")

/*
bug cant use windows.h include in this main.c file 
work around like void PlayMusic...in other file.


demo show image. play track


*/

void PlayMusic();





int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;// 800;
    const int screenHeight = 768;// 450;

    InitWindow(screenWidth, screenHeight, "DJ HELLBOY GRAPHIC DEMO ENGINE");

    Image background = LoadImage("icecream.png");     // Load image in CPU memory (RAM)

    // Load custom font for frawing on image
    Font font = LoadFont("custom_jupiter_crash.png");

    // Draw over image using custom font
    ImageDrawTextEx(&background, font, "welcome to the release of SONGNAME, BY DJ HELLBOY!", (Vector2){ 300, 230 }, (float)font.baseSize, -2, WHITE);

    UnloadFont(font);       // Unload custom font (already drawn used on image)

    Texture2D texture = LoadTextureFromImage(background);      // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(background);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
  //  ToggleFullscreen();
    SetTargetFPS(60);


    PlayMusic();


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, WHITE);
    
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    rCloseWindow();                // Close window and OpenGL context

    return 0;
}