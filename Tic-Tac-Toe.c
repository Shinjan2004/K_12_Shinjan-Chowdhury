 #include <stdio.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void print_board() {
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

int check_win() {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col;
    int player = 1;
    int turn = 0;
    while (1) {
        print_board();
        printf("Player %d's turn.\n", player);
        printf("Enter row and column (e.g. 1 2): ");
        scanf("%d %d", &row, &col);
        if (!is_valid_move(row-1, col-1)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        board[row-1][col-1] = (player == 1) ? 'X' : 'O';
        if (check_win()) {
            print_board();
            printf("Player %d wins!\n", player);
            break;
        }
        turn++;
        if (turn == 9) {
            print_board();
            printf("Tie game!\n");
            break;
        }
        player = (player == 1) ? 2 : 1;
    }
    return 0;
}
