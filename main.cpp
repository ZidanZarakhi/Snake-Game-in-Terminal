#include "Snake.h"
#include "SnakeMap.h"
#include "Food.h"
#include "Score.h"
#include "ControlSnake.h"


#include <iostream>
#include <vector> 
#include <random>
#include <utility>
#include <ncurses.h>


int main() {
    // Inisialisasi Ncurses untuk input
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE); // Membuat getch() non-blocking
    keypad(stdscr, TRUE);

    Snake snake;
    Map gameMap(60, 20);
    ControlSnake controller;
    ScoreBoard score;
    Food food;
    std::pair<int, int> coordinate_food = food.random_coordinat_food(60, 20);
    bool gameOver = false;
    
    while (!gameOver) {
        controller.control(snake);
        snake.move_snake();
        
        std::pair<int, int> snake_head = snake.body.front();
        // Cek jika makan
        if (snake_head.first == coordinate_food.first && snake_head.second == coordinate_food.second ) {
            snake.add_body_snake();
            coordinate_food = food.random_coordinat_food(60, 20);
            score.increase_score();
        }


        if (score.score > score.get_high_score()){
            score.add_highest_score();
        }

        // Cek tabrakan
        if (snake.is_collision_with_wall(60, 20) || snake.is_collision_with_body()) {
            gameOver = true;
        }

        gameMap.render(snake, coordinate_food, score.score);
        usleep(100000); // Kontrol kecepatan (0.1 detik)
    }
    endwin();
    score.display_score();
    score.display_high_score();
     
    return 0;
}