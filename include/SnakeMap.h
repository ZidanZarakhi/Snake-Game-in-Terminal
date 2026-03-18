#pragma once
#include <vector>
#include <utility>

#include "Food.h"
#include "Snake.h"
#include "ncurses.h"


class Map{
    public:
        int width {};
        int height {};

        Map(int w, int h) : width{w}, height{h} {};
        

        void render(const Snake &snake, std::pair<int, int> food_pos, int score);


};