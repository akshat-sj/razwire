#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <fstream>
#include <iostream>
#include <cmath>
#include "src/geometry.hpp"
#define SCREEN_WIDTH 400 
#define SCREEN_HEIGHT 300
const float FOCAL_LENGTH =  1 / tanf(75.0 / 2);
int main(int argc, char** argv){
    int rd,gd,bd;
   scanf("%d %d %d",&rd,&gd,&bd);
     SDL_Window *window = SDL_CreateWindow("raz wireframe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
     bool running = true;
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, rd, gd, bd, 255); 
         Model model;
         model = model.loadobj(argv[1]);;
         std::vector<Vertex> Vertices_new = model.vertices;
        for (int i = 0; i < Vertices_new.size(); i++) {
            std::get<2>(Vertices_new[i]) -= 5;
            std::get<0>(Vertices_new[i]) = 2*(SCREEN_HEIGHT / (float)SCREEN_WIDTH * FOCAL_LENGTH * std::get<0>(Vertices_new[i]) / (FOCAL_LENGTH + std::get<2>(Vertices_new[i])) + 1) * SCREEN_WIDTH / 2;
            std::get<1>(Vertices_new[i]) = 2*(FOCAL_LENGTH * std::get<1>(Vertices_new[i]) / (FOCAL_LENGTH + std::get<2>(Vertices_new[i])) + 1) * SCREEN_HEIGHT / 2;
        }
        for (const auto& edge : model.edges) {
            SDL_RenderDrawLine(renderer, std::get<0>(Vertices_new[std::get<0>(edge)]), std::get<1>(Vertices_new[std::get<0>(edge)]), std::get<0>(Vertices_new[std::get<1>(edge)]), std::get<1>(Vertices_new[std::get<1>(edge)]));
        }
        SDL_RenderPresent(renderer);
        }

    return 0;
}