#include <iostream>
#include <vector>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;
vector<vector<char>> maze = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', '#', ' ', '#', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

struct Player {
    int x, y;
};

Player player = {1, 1};

void displayMaze() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == player.y && j == player.x) {
                cout << 'P';
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

void movePlayer(char direction) {
    int newX = player.x;
    int newY = player.y;
    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
    }
    if (maze[newY][newX] == ' ') {
        player.x = newX;
        player.y = newY;
    }
}

int main() {
    char input;
    while (true) {
        displayMaze();
        cout << "Move (w/a/s/d): ";
        cin >> input;
        movePlayer(input);
        system("clear");
    }
    return 0;
}
