#include <random>
#include <utility>
#include "Food.h"

std::pair <int, int> Food::random_coordinat_food(int width, int height){
    int xcor {};
    int ycor {};

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < 2; ++i){
        if (i == 0){
            std::uniform_int_distribution<> dis (1, width -2);
            xcor = dis(gen);
        } else {
            std::uniform_int_distribution<> dis (1, height -2);
            ycor = dis(gen);
        }
    }
    return std::pair (xcor, ycor);
}