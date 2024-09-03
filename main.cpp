#include <string>
#include <iostream>

void drawScreen();
void inputListen();
bool checkIfWon();

char score[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawScreen() {
    std::cout << score[0][0] << " " << score[0][1] << " " << score[0][2] << '\n';
    std::cout << score[1][0] << " " << score[1][1] << " " << score[1][2] << '\n';
    std::cout << score[2][0] << " " << score[2][1] << " " << score[2][2] << '\n';
}

char currentTurn = 'x';

bool checkIfWon() {
    //Sideways
    if ((score[0][0] == score[1][1] & score[0][0] == score[2][2]) 
        || (score[2][0] == score[1][1] & score[2][0] == score[0][2])) {
        return true;    
    }

    //Rows
    if ((score[0][0] == score[0][1] & score[0][1] == score[0][2]) 
        || (score[1][0] == score[1][1] & score[1][1] == score[1][2])
        || (score[2][0] == score[2][1] & score[2][1] == score[2][2])) 
    {
        return true;
    }

    //Columns
    if ((score[0][0] == score[1][0] & score[1][0] == score[2][0]) 
        || (score[0][1] == score[1][1] & score[1][1] == score[2][1])
        || (score[0][2] == score[1][2] & score[1][2] == score[2][2]))
    {
        return true;
    }

    return false;
}

void inputListen() {
    system("cls");

    if (checkIfWon()) {
        std::cout << ((currentTurn == 'x') ? 'o' : 'x') << " WON!";
        return;
    }

    drawScreen();

    std::string input;
    std::cin >> input;
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            std::string symbol(1, score[r][c]);
            if (symbol == input) {
                score[r][c] = currentTurn;
            }
        }
    }

    currentTurn = (currentTurn == 'x') ? 'o' : 'x';
    inputListen();
}

int main() {
    inputListen();
    return 0;
}