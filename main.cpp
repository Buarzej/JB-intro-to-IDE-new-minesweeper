#include <iostream>
#include <string>

const int MAX_SIZE = 1000;

bool mines[MAX_SIZE + 1][MAX_SIZE + 1];
bool revealed[MAX_SIZE + 1][MAX_SIZE + 1];
int rows = 0;
int columns = 0;
bool boardExists = false;
bool gameOver = false;
bool cheatEnabled = false;

void printBoard() {
    if (!boardExists) {
        std::cout << "Plansza nie została jeszcze wygenerowana.\n";
        return;
    }

    // TODO: wypisać planszę.
}

void startGame(int newRows, int newColumns, int mineCount) {
    if (newRows < 1 || newRows > MAX_SIZE ||
        newColumns < 1 || newColumns > MAX_SIZE ||
        mineCount < 1 || mineCount > newRows * newColumns) {
        std::cout << "Niepoprawne parametry planszy.\n";
        return;
    }

    rows = newRows;
    columns = newColumns;
    gameOver = false;
    boardExists = true;

    for (int row = 1; row <= rows; row++) {
        for (int column = 1; column <= columns; column++) {
            mines[row][column] = false;
            revealed[row][column] = false;
        }
    }

    int placedMines = 0;
    while (placedMines < mineCount) {
        int row = std::rand() % rows + 1;
        int column = std::rand() % columns + 1;

        if (!mines[row][column]) {
            mines[row][column] = true;
            placedMines++;
        }
    }

    printBoard();
}

void clickCell(int x, int y) {
    if (!boardExists) {
        std::cout << "Plansza nie została jeszcze wygenerowana.\n";
        return;
    }

    if (x < 1 || x > rows || y < 1 || y > columns) {
        std::cout << "Współrzędne są poza planszą.\n";
        return;
    }

    if (!gameOver && !revealed[x][y]) {
        if (mines[x][y]) {
            revealed[x][y] = true;
            gameOver = true;
        } else {
            // TODO: ogarnąć odsłonięcie komórki
            // reveal(x, y);
        }
    }

    printBoard();
}

void printHelp() {
    std::cout << "Dostępne komendy:\n"
            << "start n m b - rozpocznij nową grę na planszy n x m z b minami\n"
            << "show - wyświetl planszę\n"
            << "click x y - odkryj pole o współrzędnych (x, y)\n"
            << "cheat - przełącz widoczność min\n"
            << "help - wyświetl tę pomoc\n";
}

int main() {
    // Inicjalizacja randomizacji
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::string command;
    while (std::cin >> command) {
        if (command == "start") {
            int n, m, b;
            if (!(std::cin >> n >> m >> b)) break;
            startGame(n, m, b);
        } else if (command == "show") {
            printBoard();
        } else if (command == "click") {
            int x, y;
            if (!(std::cin >> x >> y)) break;
            clickCell(x, y);
        } else if (command == "cheat") {
            cheatEnabled = !cheatEnabled;
            if (cheatEnabled) {
                std::cout << "Miny są teraz widoczne.\n";
            } else {
                std::cout << "Miny są teraz ukryte.\n";
            }
        } else if (command == "help") {
            printHelp();
        } else {
            std::cout << "Nieznana komenda. Użyj \"help\", aby uzyskać pomoc.\n";
        }
    }

    return 0;
}
