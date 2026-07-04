#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    int width, height, channels;

    unsigned char* pixels = stbi_load(
        argv[1],
        &width,
        &height,
        &channels,
        STBI_rgb_alpha
    );

    if (!pixels)
    {
        printf("Failed to load image: %s\n", stbi_failure_reason());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        argv[1],
        width,
        height,
        0
    );

    if (!window)
    {
        printf("Window error: %s\n", SDL_GetError());
        stbi_image_free(pixels);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    if (!renderer)
    {
        printf("Renderer error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        stbi_image_free(pixels);
        SDL_Quit();
        return 1;
    }

    int running = 1;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int index = (y * width + x) * 4;

                Uint8 r = pixels[index];
                Uint8 g = pixels[index + 1];
                Uint8 b = pixels[index + 2];
                Uint8 a = pixels[index + 3];

                SDL_SetRenderDrawColor(renderer, r, g, b, a);
                SDL_RenderPoint(renderer, (float)x, (float)y);
            }
        }

        SDL_RenderPresent(renderer);
    }

    stbi_image_free(pixels);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
