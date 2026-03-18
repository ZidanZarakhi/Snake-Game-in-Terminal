#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include "Snake.h"


class ControlSnake{
    public:
        void control(Snake &snake);
};