#include "Snake.h"

#include <vector>
#include <iostream>
#include <utility>


Snake::Snake() {
    current_dir = RIGHT;

    body.push_back({30, 10});
    body.push_back({29, 10});
    body.push_back({28, 10});
}





void Snake::move_snake(){
    std::pair<int, int> new_head = body.front();
    if (current_dir == UP){
        new_head.second--;
    } else if (current_dir == DOWN){
        new_head.second++;
    } else if (current_dir == RIGHT){
        new_head.first++;
    } else if (current_dir == LEFT){
        new_head.first--;
    }
    body.insert(body.begin(), new_head);
    body.pop_back();
}

void Snake::add_body_snake(){
    std::pair<int, int> new_head = body.front();
    if (current_dir == UP){
        new_head.second--;
    } else if (current_dir == DOWN){
        new_head.second++;
    } else if (current_dir == RIGHT){
        new_head.first++;
    } else if (current_dir == LEFT){
        new_head.first--;
    }
    body.insert(body.begin(), new_head);
}


bool Snake::is_collision_with_wall(int width, int height){
    auto head = body.front();
    return (head.first <= 0 || head.first >= width - 1 || head.second <= 0 || head.second >= height - 1);
}


bool Snake::is_collision_with_body(){
    for (int i = 1; i < body.size(); ++i){
        if(body[0] == body[i]){
            return true;
        }
    }
    return false;
}
