#include "Score.h"

#include <iostream>
#include <fstream>
#include <string>


void ScoreBoard::display_score(){
    std::cout << "Score: " << score << "\n";
}

void ScoreBoard::display_high_score(){
    std::cout << "High Score: " << get_high_score() << "\n";
}

void ScoreBoard::add_highest_score(){
    if (score > get_high_score()){
        std::fstream NewHighScore("high_score.txt");
        NewHighScore << score;
    }
}

int ScoreBoard::get_high_score(){
    std::fstream HighestScore("high_score.txt");

    int get_score {};
    HighestScore >> get_score;

    return get_score;
}

void ScoreBoard::increase_score(){
    ++score;
}