#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#ifdef _WIN32
#include <conio.h>  // Windows-specific
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };

class SnakeGame {
private:
    bool gameOver;
    int score;
    static int highscore;
    int x, y;
    int foodX, foodY;
    int tailX[100], tailY[100];
    int tailLength;
    char snakehead,snakebody;
    Direction dir;

    void spawnFood() {
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
        for (int i = 0; i < tailLength; i++) {
            if (foodX == tailX[i] && foodY == tailY[i]) {
                spawnFood();
                break;
            }
        }
    }

public:
    SnakeGame() { resetGame(); }
    
    void resetGame() {
        gameOver = false;
        dir = STOP;
        x = WIDTH / 2;
        y = HEIGHT / 2;
        score = 0;
        tailLength = 3;
        spawnFood();
         for (int i = 0; i < tailLength; i++) 
         {
        tailX[i] = x - (i + 1); 
        tailY[i] = y;
         }
    }

    void Design_Snake(char head,char body)
    {
        snakehead=head;
        snakebody=body;
    }

    void clearScreen()
     {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    void draw() {
        clearScreen();
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0) cout << "#";
                if (i == y && j == x) cout <<snakehead;
                else if (i == foodY && j == foodX) cout << "F";
                else {
                    bool isTail = false;
                    for (int k = 0; k < tailLength; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout <<snakebody;
                            isTail = true;
                        }
                    }
                    if (!isTail) cout << " ";
                }
                if (j == WIDTH - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;
        cout << "Score: " << score << " | High Score: " << highscore << endl;
    }

    #ifndef _WIN32
int _kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

char _getch() {
    char ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

    void input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'x': gameOver = true; break;
            }
        }
    }

    void logic() {
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < tailLength; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
        case UP: y--; break;
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        default: break;
        }

        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
            gameOver = true;
        for (int i = 4; i < tailLength; i++) {
            if (tailX[i] == x && tailY[i] == y) {
                gameOver = true;
            }
        }

        if (x == foodX && y == foodY) {
            score += 10;
            tailLength++;
            spawnFood();
        }

        updateHighScore();
    }

    void updateHighScore() {
        if (score > highscore) {
            highscore = score;
        }
    }
    

    bool isGameOver() { return gameOver; }
    int getScore() { return score; }
    int getHighScore() { return highscore; }
};


int SnakeGame::highscore = 0;
void delay(int milliseconds)
 {
    #ifdef _WIN32
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000); //Windows
    #else
    usleep(milliseconds * 1000);  // Linux/macOS
    #endif
}
    

int main() {
    char c;
    srand(time(0));
    cout<<"Design your snake\n";
    char head,body;
    cout<<"Head : ";cin>>head;
    cout<<"Body : ";cin>>body;


    cout << "Select difficulty level" << endl;
    cout << "a) Easy " << endl;
    cout << "b) Medium " << endl;
    cout << "c) Hard " << endl;
    
    char diff;
    cin >> diff;

    if (diff != 'a' && diff != 'b' && diff != 'c') {
        cout << "Enter proper difficulty level!" << endl;
        return 0;
    }


    do {
        SnakeGame game;
        game.Design_Snake(head,body);
        while (!game.isGameOver()) {
            game.draw();
            game.input();
            game.logic();

            if (diff == 'a')
            {  delay(200);}
            else if (diff == 'b'){
    delay(50);}
else if (diff == 'c'){
    delay(10);}
        }

        game.draw();
        cout << "Game Over!\nFinal Score : " << game.getScore()<< " | High Score : " << game.getHighScore() << endl;
        cout << "Press 'p' to play again or 'x' to exit: ";
        cin >> c;
    } while (c == 'p');

    return 0;
}