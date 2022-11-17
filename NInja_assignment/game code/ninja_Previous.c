#include <stdio.h> //to use printf,scanf,fflush(stdout),ect...
#include <stdlib.h>
#include <windows.h> //To add the sound and Hide cursour...
#include <conio.h>
#include <string.h> //To use function of string librarey...

// defining The Functions...

void print_at_xy(int x, int y, char *val);       // To print anything at terminal...
void display_score();                            // To display the scrore...
void init();                                     // To Initilise the game veriable like score,position ,ect...
int zero_lives();                                // To check that lives are 0 or not...
void set_game_state_over();                      // To set the game_state veriable as GAME_STATE_OVER...
char get_input();                                // To get the input from keybord to jump,quit,restart...
void update_wall();                              // Controll motion of wall in Y direction
void increment_score();                          // score counter
void decrement_lives();                          // lives counter
void draw();                                     // To give instruction to draw the ninja, walls and spikes...
void draw_wall();                                // Draw both side BAR in wall
void draw_ninja();                               // Draw red NINJA
void clean_up();                                 // Game End message...
void display_message(const char *, int yOffset); // To display any kind of message
void update_ninja(char ch);                      // Controll the position on ninja(changes after colision)
int collides_with_spike();                       // To check whether ninja colides with spike or, not...
void display_count_down();                       // Display the 3,2,1 count down
void game_rules();                               // To display the game rules

HANDLE _output_handle;

void hidecursor() // To hide the cursour
{
    _output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(_output_handle, &info);
}

const int SCREEN_WIDTH = 12;  // set distance from left side of screen...
const int SCREEN_HEIGHT = 20; // Set distance of last wall from top of screen...
int lives;                    // lives count
int game_state;               // To se the game condition is palying or over
int GAME_STATE_OVER;          // Just A value to compare between game states...
int GAME_STATE_PLAYING;       // Just A value to compare between game states...
int GOAL_POINTS;              // increment in score after each JUMP(keybord hit)...
int WALL_SPEED;               // The rate at which the Y position of wall comes down...
int score;                    // current score count
char game_over_string[30];    // Text to print after end of game
char left_wall[60];           // charracter  array to make left wall
char right_wall[60];          // charracter array to make right wall
char ninja[2];                // Ninja Boady
int wall_y_pos;               //
int ninja_x;                  // initilize the ninja position at X=1...
int ninja_y;                  // initilize the ninja position at y=screenhight/2...
int NINJA_SPEED;              // speed or, space by which ninja shift after press of 'j' one time
int ninja_delta;              // responsible to what next change to be done in X position of ninja
int left_wall_spike;          // Drwa spike on left wall
int right_wall_spike;         // Drwa spike on right wall
int immunity_count_down;      // After starting each round immune time
float time;                   // To calculate the time of the game played...

int main()
{

    init();
    game_rules();
    printf("\ninit");
    system("@cls||clear");

    // 1000/30
    // game loop
    while (1)
    {

        if (immunity_count_down > 0)
        {
            immunity_count_down--;
        }

        char ch = get_input();

        // clear screen and quit
        if (game_state == GAME_STATE_OVER && ch == 'q')
        {
            system("@cls||clear");
            break;
        }
        else if (game_state == GAME_STATE_OVER && ch == 'r')
        {
            system("@cls||clear");
            main();
        }

        update_wall();
        update_ninja(ch);
        draw();
        if (collides_with_spike() && immunity_count_down <= 0)
        {
            Beep(243, 300);
            decrement_lives();
            immunity_count_down = 30;
        }

        if (zero_lives())
        {
            set_game_state_over();
            display_message(game_over_string, -2);
            display_message("'q' to quit... or, \n  'r' to restart the game", 0);
        }
        else
        {
            if (immunity_count_down <= 0)
            {
                time += 0.099999;
            }
        }
        Sleep(100);
    }

    clean_up();
}

void init()
{
    time = 0;
    score = 0;
    lives = 3;
    GOAL_POINTS = 10;
    GAME_STATE_OVER = 1;
    GAME_STATE_PLAYING = 2; // Just A value to compare between game states...
    WALL_SPEED = 1;

    ninja_x = 1;
    ninja_y = SCREEN_HEIGHT / 2; // initilize the ninja Y=screenhight/2...
    NINJA_SPEED = 6;
    ninja_delta = 0;
    left_wall_spike = 0;
    right_wall_spike = 0;
    immunity_count_down = 30;

    game_state = GAME_STATE_PLAYING;
    wall_y_pos = -30;
    strcpy(game_over_string, "GAME OVER");
    strcpy(ninja, "X"); // Ninja Body...

    strcpy(left_wall, "|||>|||||||||||||>>||||||>>||||||>>||||");
    strcpy(right_wall, "|||||||||<||||<||||||||<||||||<<||||||<");
    hidecursor();
}
void game_rules()
{
    system("@cls||clear");
    printf("\n\n==================Game Rules=====================\n\n");
    printf("*************************************************\n\n");
    printf(" 1. Press 'j' to jump right or,left.\n");
    printf(" 2. Don't touch the Spike.\n");
    printf(" 3. You have only 3 lives to play.\n");
    printf(" 4. If you touch spike 3rd time The game is over.\n\n");
    printf("*************************************************\n\n");
    Sleep(10000);
}
int zero_lives()
{
    if (lives == 0)
    {
        return 1;
    }
    return 0;
}

void set_game_state_over()
{
    game_state = GAME_STATE_OVER;
}

char get_input()
{
    char ch = 0;

    if (kbhit())
    {
        ch = getch();
    }

    return ch;
}

void increment_score()
{
    score += GOAL_POINTS;
}

void decrement_lives()
{
    lives--;
    Beep(200, 300);
}

void draw()
{
    draw_wall();
    draw_ninja();
    display_score();
    display_count_down();
}

void print_at_xy(int x, int y, char *val)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(_output_handle, coord);
    printf("%s", (const char *)val);
    fflush(stdout);
}

void display_score()
{
    char buffer[50] = {0}; // 50 Null characters...
    sprintf(buffer, "SCORE: %d :>-<: LIVES: %d :>-<: TIME: %0.3f", score, lives, time);
    print_at_xy(0, 0, buffer);
    fflush(stdout);
}

void display_message(const char *message, int yOffset)
{
    char buffer[100] = {0};
    strcpy(buffer, message);
    print_at_xy(SCREEN_WIDTH / 2 - strlen(message) / 2,
                (SCREEN_HEIGHT / 2 - 1) + yOffset, buffer);
    fflush(stdout);
}

void display_count_down()
{
    if (immunity_count_down > 0)
    {
        char buffer[3] = {0};
        char *countdown = itoa(immunity_count_down / 10, buffer, 10);
        strcpy(buffer, countdown);
        SetConsoleTextAttribute(_output_handle, FOREGROUND_BLUE);
        display_message(" GET READY!", -2);
        display_message(buffer, 0);
        SetConsoleTextAttribute(_output_handle, FOREGROUND_INTENSITY);
    }
}

void clean_up()
{

    Beep(234, 800);
    printf("\n\n\n\n\n\n\n\n=====================\n\nThanks for playing...\n\n=====================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n");
}

void update_wall()
{
    wall_y_pos += WALL_SPEED;
    if (wall_y_pos > 0)
    {
        wall_y_pos = -SCREEN_HEIGHT;
    }
}

void update_ninja(char ch)
{
    ninja_x += ninja_delta;
    if (ninja_x == 1 && ch == 'j' && game_state == GAME_STATE_PLAYING)
    {
        ninja_delta = NINJA_SPEED;
        ninja_x += ninja_delta;
        increment_score();
    }
    else if (ninja_x == SCREEN_WIDTH - 1 && ch == 'j' && game_state == GAME_STATE_PLAYING)
    {
        ninja_delta = -NINJA_SPEED;
        ninja_x += ninja_delta;
        increment_score();
    }
    else if (ninja_x <= 1)
    {
        ninja_delta = 0;
        ninja_x = 1;
    }
    else if (ninja_x >= SCREEN_WIDTH - 1)
    {
        ninja_delta = 0;
        ninja_x = SCREEN_WIDTH - 1;
    }

    if (immunity_count_down > 10 && lives < 3)
    {
        ninja_x = SCREEN_WIDTH / 2; // set the ninja position at mid of screen and
                                    // whenever the frame changes down Y by 1...
        ninja_y += 1;
        if (ninja_y >= SCREEN_HEIGHT)
        {
            ninja_y = SCREEN_HEIGHT;
        }
    }
    if (immunity_count_down < 10 && immunity_count_down > 1)
    {
        ninja_x = 1;
        ninja_y = SCREEN_HEIGHT / 2;
    }
}

int collides_with_spike()
{

    if (game_state == GAME_STATE_OVER)
    {
        return 0;
    }

    if (ninja_x == 1 && left_wall_spike == 1)
    {
        return 1;
    }
    else if (ninja_x == SCREEN_WIDTH - 1 && right_wall_spike == 1)
    {
        return 1;
    }

    return 0;
}

void draw_wall()
{
    char wall_row[SCREEN_WIDTH + 1];
    int wall_index = wall_y_pos * -1;
    left_wall_spike = 0;
    right_wall_spike = 0;
    for (int i = 2; i < 20; i++, wall_index++)
    {

        for (int j = 1; j < SCREEN_WIDTH; j++)
        {
            wall_row[j] = ' ';
        }

        wall_row[SCREEN_WIDTH + 1] = '\0';

        wall_row[0] = '|';
        wall_row[SCREEN_WIDTH] = '|';

        if (left_wall[wall_index] == '>')
        {
            wall_row[1] = '>';
            if (i == SCREEN_HEIGHT / 2)
            {
                left_wall_spike = 1;
            }
        }

        if (right_wall[wall_index] == '<')
        {
            wall_row[SCREEN_WIDTH - 1] = '<';
            if (i == SCREEN_HEIGHT / 2)
            {
                right_wall_spike = 1;
            }
        }

        print_at_xy(0, i, wall_row);
    }
}

void draw_ninja()
{

    if (ninja_y >= SCREEN_HEIGHT)
        return;

    SetConsoleTextAttribute(_output_handle, FOREGROUND_RED);
    print_at_xy(ninja_x, ninja_y, ninja);
    SetConsoleTextAttribute(_output_handle, FOREGROUND_INTENSITY);
}