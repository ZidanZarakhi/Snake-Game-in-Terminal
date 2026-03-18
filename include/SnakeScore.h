#pragma once

class ScoreBoard{
    public:  
        int score {}; 
        void display_score();
        void display_high_score();
        void add_highest_score();
        int get_high_score();
        void increase_score();
};