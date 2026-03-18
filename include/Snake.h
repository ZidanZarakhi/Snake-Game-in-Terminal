#pragma once

#include <vector>
#include <iostream>


enum Direction { UP = 90, DOWN = 270, LEFT = 180, RIGHT = 0 };

class Snake{
    public:
        std::vector<std::pair<int, int>> body;
        Direction current_dir;

        
        Snake();
        void move_snake();
        void add_body_snake();
        bool is_collision_with_wall(int width, int height);
        bool is_collision_with_body();
};