#include "Control.h"

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>


void ControlSnake::control(Snake &snake){
    int user_input_key {getch()};
    if (user_input_key == ERR){
        return;
    }
    switch (user_input_key) {
        case 'w':
            if (snake.current_dir != DOWN){
                snake.current_dir = UP;
            }
            break;
        case 's':
            if (snake.current_dir != UP){
                snake.current_dir = DOWN;
                }
            break;
        case 'd':
            if (snake.current_dir != LEFT){
                snake.current_dir = RIGHT;
            }
            break;
        case 'a':
            if (snake.current_dir != RIGHT){
                snake.current_dir = LEFT;
            }
            break;

    }
};