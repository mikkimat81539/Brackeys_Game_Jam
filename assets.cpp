#include "assets.h"

#include "wallpaper.png.h"
#include "house.png.h"
#include "front_fence.png.h"
#include "back_fence.png.h"
#include "idle_right.png.h"
#include "idle_left.png.h"
#include "run_right.png.h"
#include "run_left.png.h"
#include "opps_left.png.h"
#include "health.png.h"


Texture2D wallpaper;
Texture2D house;
Texture2D front_fence;
Texture2D back_fence;
Texture2D idle_right_img;
Texture2D idle_left_img;
Texture2D run_right_img;
Texture2D run_left_img;
Texture2D opponent_img;
Texture2D health_img;


void LoadGameAssets()
{
    // WALLPAPER
    Image wallpaper_image = LoadImageFromMemory(".png", assets_wallpaper_png, assets_wallpaper_png_len);
    wallpaper = LoadTextureFromImage(wallpaper_image);
    UnloadImage(wallpaper_image);


    // HOUSE
    Image house_image = LoadImageFromMemory(".png", assets_house_png, assets_house_png_len);
    house = LoadTextureFromImage(house_image);
    UnloadImage(house_image);


    // FRONT FENCE
    Image front_fence_image = LoadImageFromMemory(".png", assets_front_fence_png, assets_front_fence_png_len);
    front_fence = LoadTextureFromImage(front_fence_image);
    UnloadImage(front_fence_image);


    // BACK FENCE
    Image back_fence_image = LoadImageFromMemory(".png", assets_back_fence_png, assets_back_fence_png_len);
    back_fence = LoadTextureFromImage(back_fence_image);
    UnloadImage(back_fence_image);


    // IDLE RIGHT
    Image idle_right_image = LoadImageFromMemory(".png", assets_idle_right_png, assets_idle_right_png_len);
    idle_right_img = LoadTextureFromImage(idle_right_image);
    UnloadImage(idle_right_image);


    // IDLE LEFT
    Image idle_left_image = LoadImageFromMemory(".png", assets_idle_left_png, assets_idle_left_png_len);
    idle_left_img = LoadTextureFromImage(idle_left_image);
    UnloadImage(idle_left_image);


    // RUN RIGHT
    Image run_right_image = LoadImageFromMemory(".png", assets_run_right_png, assets_run_right_png_len);
    run_right_img = LoadTextureFromImage(run_right_image);
    UnloadImage(run_right_image);


    // RUN LEFT
    Image run_left_image = LoadImageFromMemory(".png", assets_run_left_png, assets_run_left_png_len);
    run_left_img = LoadTextureFromImage(run_left_image);
    UnloadImage(run_left_image);


    // OPPONENT
    Image opponent_image = LoadImageFromMemory(".png", assets_opps_left_png, assets_opps_left_png_len);
    opponent_img = LoadTextureFromImage(opponent_image);
    UnloadImage(opponent_image);


    // HEALTH
    Image health_image = LoadImageFromMemory(".png", assets_health_png, assets_health_png_len);
    health_img = LoadTextureFromImage(health_image);
    UnloadImage(health_image);
}
