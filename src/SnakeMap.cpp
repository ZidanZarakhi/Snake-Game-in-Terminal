#include <vector>
#include <iostream>
#include <utility>
#include "ncurses.h"

#include "SnakeMap.h"
void Map::render(const Snake &snake, std::pair <int, int> food_pos, int score) {
    erase(); // Membersihkan layar ncurses dengan efisien (pengganti system clear)
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            bool is_snake {false};
            
            // Gambar Tubuh Ular
            for (auto segment : snake.body) {
                if (segment.first == j && segment.second == i) {
                    // Gunakan mvaddch(y, x, char)
                    mvaddch(i, j, (segment == snake.body.front() ? '@' : 'o'));
                    is_snake = true;
                    break;
                }
            }
            if (is_snake) continue;

            // Gambar Tembok, Makanan, atau Ruang Kosong
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                mvaddch(i, j, '#');
            } else if (j == food_pos.first && i == food_pos.second) {
                mvaddch(i, j, '$');
            }
            // Tidak perlu mvaddch untuk spasi agar lebih cepat
        }
    }
    
    // Tampilkan Skor di bawah Map
    mvprintw(height + 1, 0, "Score: %d", score);
    refresh(); // Wajib dipanggil agar semua perubahan muncul di layar
}

