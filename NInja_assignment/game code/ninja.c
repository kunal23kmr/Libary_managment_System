#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

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
void game_mode();                                //
void player_name();
void score_board();
void leader_board();
void names();
void time_hs();
void swap();
void clear_screen();
FILE *f;
FILE *f2;
FILE *f3;
FILE *f4;
FILE *f5;
FILE *g;
FILE *g2;
FILE *g3;
FILE *g4;
FILE *g5;
FILE *t;
FILE *t2;
FILE *t3;
FILE *t4;
FILE *t5;
HANDLE _output_handle;

void hidecursor() // To hide the cursor
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
float WALL_SPEED;             // The rate at which the Y position of wall comes down...
int score;                    // current score count
int HighScore1;               // highest score count
int HighScore5;
int HighScore4;
int HighScore3;
int HighScore2;
char game_over_string[30]; // Text to print after end of game
char left_wall[60];        // charracter  array to make left wall
char right_wall[60];       // charracter array to make right wall
char ninja[2];             // Ninja Body
int wall_y_pos;            //
int ninja_x;               // initilize the ninja position at X=1...
int ninja_y;               // initilize the ninja position at y=screenhight/2...
int NINJA_SPEED;           // speed or, space by which ninja shift after press of 'j' one time
int ninja_delta;           // responsible to what next change to be done in X position of ninja
int left_wall_spike;       // Drwa spike on left wall
int right_wall_spike;      // Drwa spike on right wall
int immunity_count_down;   // After starting each round immune time
int m, s, ms;
int level;
char name[50];
char name1[50];
char name2[50], name3[50], name4[50], name5[50];
float time;
float time1, time2, time3, time4, time5;
int temp1, temp2, temp3, temp4;
char emp1[100], emp2[100], emp3[100], emp4[100];
float mp1, mp2, mp3, mp4;
int main()
{
    score_board();
    time_hs();
    names();
    init(); // initializes all the values
    game_rules();
    game_mode();
    player_name();
    printf("\ninit");
    system("cls");

    // 1000/30
    // game loop
    while (1)
    {

        if (immunity_count_down > 0)
        {
            immunity_count_down--;
        }

        clear_screen();

        char ch = get_input();

        // clear screen and quit
        if (game_state == GAME_STATE_OVER && ch == 'q')
        {
            system("cls");
            break;
        }
        else if (game_state == GAME_STATE_OVER && ch == 'r')
        {
            system("cls");
            main();
        }
        else if (game_state == GAME_STATE_OVER && ch == 'l')
        {
            system("cls");
            leader_board();
            system("pause");
            break;
        }

        clear_screen();
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
            if (score > HighScore1)
            {
                printf("  NEW HIGHSCORE %d!!!!\n", score);
                system("pause");
                system("cls");
                f = fopen("highscore1.txt", "w");
                temp1 = HighScore1;
                fprintf(f, "%d", score);
                fclose(f);
                g = fopen("name1.txt", "w");
                swap(emp1, name1);
                fprintf(g, "%s", name);
                fclose(g);
                t = fopen("time1.txt", "w");
                mp1 = time1;
                fprintf(t, "%f", time);
                fclose(t);
                t = fopen("time1.txt", "r");
                t2 = fopen("time2.txt", "r");
                t3 = fopen("time3.txt", "r");
                t4 = fopen("time4.txt", "r");
                t5 = fopen("time5.txt", "r");
                g = fopen("name1.txt", "r");
                g2 = fopen("name2.txt", "r");
                g3 = fopen("name3.txt", "r");
                g4 = fopen("name4.txt", "r");
                g5 = fopen("name5.txt", "r");
                f = fopen("highscore1.txt", "r");
                f2 = fopen("highscore2.txt", "r");
                f3 = fopen("highscore3.txt", "r");
                f4 = fopen("highscore4.txt", "r");
                f5 = fopen("highscore5.txt", "r");
                temp2 = HighScore2;
                temp3 = HighScore3;
                temp4 = HighScore4;
                HighScore2 = temp1;
                HighScore3 = temp2;
                HighScore4 = temp3;
                HighScore5 = temp4;
                swap(emp2, name2);
                swap(emp3, name3);
                swap(emp4, name4);
                swap(name2, emp1);
                swap(name3, emp2);
                swap(name4, emp3);
                swap(name5, emp4);
                mp2 = time2;
                mp3 = time3;
                mp4 = time5;
                time2 = mp1;
                time3 = mp2;
                time4 = mp3;
                time5 = mp4;
            }
            else if (score > HighScore2 && score < HighScore1)
            {

                f2 = fopen("highscore2.txt", "w");
                temp2 = HighScore2;
                fprintf(f2, "%d", score);
                fclose(f2);
                g2 = fopen("name2.txt", "w");
                swap(emp2, name2);
                fprintf(g2, "%s", name);
                fclose(g2);
                t2 = fopen("time2.txt", "w");
                mp2 = time2;
                fprintf(t2, "%f", time);
                fclose(t2);
                t2 = fopen("time2.txt", "r");
                t3 = fopen("time3.txt", "r");
                t4 = fopen("time4.txt", "r");
                t5 = fopen("time5.txt", "r");
                g2 = fopen("name2.txt", "r");
                g3 = fopen("name3.txt", "r");
                g4 = fopen("name4.txt", "r");
                g5 = fopen("name5.txt", "r");
                f2 = fopen("highscore2.txt", "r");
                f3 = fopen("highscore3.txt", "r");
                f4 = fopen("highscore4.txt", "r");
                f5 = fopen("highscore5.txt", "r");
                temp3 = HighScore3;
                temp4 = HighScore4;
                HighScore3 = temp2;
                HighScore4 = temp3;
                HighScore5 = temp4;
                swap(emp3, name3);
                swap(emp4, name4);
                swap(name3, emp2);
                swap(name4, emp3);
                swap(name5, emp4);
                mp3 = time3;
                mp4 = time4;
                time3 = mp2;
                time4 = mp3;
                time5 = mp4;
                system("cls");
            }
            else if (score > HighScore3 && score < HighScore2)
            {
                f3 = fopen("highscore3.txt", "w");
                temp3 = HighScore3;
                fprintf(f3, "%d", score);
                fclose(f3);
                g3 = fopen("name3.txt", "w");
                swap(emp3, name3);
                fprintf(g3, "%s", name);
                fclose(g3);
                t3 = fopen("time3.txt", "w");
                mp3 = time3;
                fprintf(t3, "%f", time);
                fclose(t3);
                t3 = fopen("time3.txt", "r");
                t4 = fopen("time4.txt", "r");
                t5 = fopen("time5.txt", "r");
                g3 = fopen("name3.txt", "r");
                g4 = fopen("name4.txt", "r");
                g5 = fopen("name5.txt", "r");
                f3 = fopen("highscore3.txt", "r");
                f4 = fopen("highscore4.txt", "r");
                f5 = fopen("highscore5.txt", "r");
                temp4 = HighScore4;
                HighScore4 = temp3;
                HighScore5 = temp4;
                swap(emp4, name4);
                swap(name4, emp3);
                swap(name5, emp4);
                mp4 = time4;
                time4 = mp3;
                time5 = mp4;
                system("cls");
            }
            else if (score > HighScore4 && score < HighScore3)
            {
                f4 = fopen("highscore4.txt", "w");
                temp4 = HighScore4;
                fprintf(f4, "%d", score);
                fclose(f4);
                g4 = fopen("name4.txt", "w");
                swap(emp4, name4);
                fprintf(g4, "%s", name);
                fclose(g4);
                t4 = fopen("time4.txt", "w");
                mp4 = time4;
                fprintf(t4, "%f", time);
                fclose(t4);
                t4 = fopen("time4.txt", "r");
                t5 = fopen("time5.txt", "r");
                g4 = fopen("name4.txt", "r");
                g5 = fopen("name5.txt", "r");
                f4 = fopen("highscore4.txt", "r");
                f5 = fopen("highscore5.txt", "r");
                HighScore5 = temp4;
                swap(name5, emp4);
                time5 = mp4;
                system("cls");
            }
            else if (score > HighScore5 && score < HighScore4)
            {
                f5 = fopen("highscore5.txt", "w");
                fprintf(f5, "%d", score);
                fclose(f5);
                g5 = fopen("name5.txt", "w");
                fprintf(g5, "%s", name);
                fclose(g5);
                t5 = fopen("time5.txt", "w");
                fprintf(t5, "%f", time);
                fclose(t5);
            }
            display_message("  Press:'q' to quit... or, \n 'r' to restart the game or,\n 'l' to see leaderboard", 0);
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
    score = 0;
    lives = 3;
    GOAL_POINTS = 10;
    GAME_STATE_OVER = 1;
    GAME_STATE_PLAYING = 2;
    // WALL_SPEED = 1;

    ninja_x = 1;
    ninja_y = SCREEN_HEIGHT / 2;
    NINJA_SPEED = 6;
    ninja_delta = 0;
    left_wall_spike = 0;
    right_wall_spike = 0;
    immunity_count_down = 30;

    game_state = GAME_STATE_PLAYING;
    wall_y_pos = -20;
    strcpy(game_over_string, " GAME OVER\n");
    strcpy(ninja, "X");

    strcpy(left_wall, "|||>|||||||||||||>>||||||>>||||||>>||||");
    strcpy(right_wall, "|||||||||<||||<||||||||<||||||<<||||||<");
    hidecursor();
}
void game_rules()
{
    system("@cls||clear");
    printf("\n\n==================GAME RULES=====================\n\n");
    printf("*************************************************\n\n");
    printf("1. Press 'j' to jump right or,left.\n");
    printf("2. Don't touch the Spike.\n");
    printf("3. You have only 3 lives to play.\n");
    printf("4. If you touch spike 3rd time The game is over.\n\n");
    printf("*************************************************\n\n");
    system("pause");
}
void game_mode()
{
    printf("enter '1' for easy level\n");
    printf("enter '2' for medium level\n");
    printf("enter '3' for hard level\n");
    printf("enter your choice: ");
    scanf("%d", &level);
    switch (level)
    {
    case 1:
        WALL_SPEED = 1;
        break;
    case 2:
        WALL_SPEED = 1.000000001;
        break;
    case 3:
        WALL_SPEED = 1.0000001;
        break;
    }
}
void player_name()
{
    printf("enter player name: ");
    scanf(" %s", &name);
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
    SetConsoleCursorPosition(_output_handle, coord); // it tells console where to place cursor position
    printf("%s", (const char *)val);
    fflush(stdout);
}

void display_score()
{
    char buffer[100] = {0};
    sprintf(buffer, "SCORE: %4d LIVES: %d HighScore: %d TIME: %0.3f", score, lives, HighScore1, time);
    print_at_xy(0, 0, buffer);
    fflush(stdout);
}
void time_hs()
{
    t = fopen("time1.txt", "r");
    fscanf(t, "%f", &time1);
    fclose(t);
    t2 = fopen("time2.txt", "r");
    fscanf(t2, "%f", &time2);
    fclose(t2);
    t3 = fopen("time3.txt", "r");
    fscanf(t3, "%f", &time3);
    fclose(t3);
    t4 = fopen("time4.txt", "r");
    fscanf(t4, "%f", &time4);
    fclose(t4);
    t5 = fopen("time5.txt", "r");
    fscanf(t5, "%f", &time5);
    fclose(t5);
}
void names()
{
    g = fopen("name1.txt", "r");
    fscanf(g, "%s", &name1);
    fclose(g);
    g2 = fopen("name2.txt", "r");
    fscanf(g2, "%s", &name2);
    fclose(g2);
    g3 = fopen("name3.txt", "r");
    fscanf(g3, "%s", &name3);
    fclose(g3);
    g4 = fopen("name4.txt", "r");
    fscanf(g4, "%s", &name4);
    fclose(g4);
    g5 = fopen("name5.txt", "r");
    fscanf(g5, "%s", &name5);
    fclose(g5);
}
void score_board()
{
    f = fopen("highscore1.txt", "r");
    fscanf(f, "%d", &HighScore1);
    fclose(f);
    f2 = fopen("highscore2.txt", "r");
    fscanf(f2, "%d", &HighScore2);
    fclose(f2);
    f3 = fopen("highscore3.txt", "r");
    fscanf(f3, "%d", &HighScore3);
    fclose(f3);
    f4 = fopen("highscore4.txt", "r");
    fscanf(f4, "%d", &HighScore4);
    fclose(f4);
    f5 = fopen("highscore5.txt", "r");
    fscanf(f5, "%d", &HighScore5);
    fclose(f5);
}

void leader_board()
{
    t = fopen("time1.txt", "r");
    t2 = fopen("time2.txt", "r");
    t3 = fopen("time3.txt", "r");
    t4 = fopen("time4.txt", "r");
    t5 = fopen("time5.txt", "r");
    g = fopen("name1.txt", "r");
    g2 = fopen("name2.txt", "r");
    g3 = fopen("name3.txt", "r");
    g4 = fopen("name4.txt", "r");
    g5 = fopen("name5.txt", "r");
    f = fopen("highscore.txt", "r");
    f2 = fopen("highscore2.txt", "r");
    f3 = fopen("highscore3.txt", "r");
    f4 = fopen("highscore4.txt", "r");
    f5 = fopen("highscore5.txt", "r");
    printf("#########################################################################################\n");
    printf("#                                                                                       #\n");
    printf("#                                     Leader Board                                      #\n");
    printf("#                                                                                       #\n");
    printf("#########################################################################################\n\n\n");
    printf("=========================================================================================\n");
    printf("|         SR.NO.                  NAME                  SCORE                TIME       |\n");
    printf("=========================================================================================\n\n");
    printf("	      %2d                     %7s                    %5d                 %5f\n", 01, name1, HighScore1, time1);
    printf("	      %2d                     %7s                    %5d                 %5f\n", 02, name2, HighScore2, time2);
    printf("	      %2d                     %7s                    %5d                 %5f\n", 03, name3, HighScore3, time3);
    printf("	      %2d                     %7s                    %5d                 %5f\n", 04, name4, HighScore4, time4);
    printf("	      %2d                     %7s                    %5d                 %5f\n", 05, name5, HighScore5, time5);
} 

void clear_screen()
{
    time_hs();
    names();
    score_board();
    char buffer[] = "                                                                 ";
    int i;
    for (i = 0; i < 3; i++)
    {
        print_at_xy(0, i, buffer);
    }
}

void display_message(const char *message, int yOffset)
{
    char buffer[100] = {0};
    strcpy(buffer, message);
    print_at_xy(SCREEN_WIDTH / 2 - strlen(message) / 2,
                (SCREEN_HEIGHT / 2 - 1) + yOffset, buffer);
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
    printf("Thanks for playing.");
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
        ninja_x = SCREEN_WIDTH / 2;
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
    int i, j;
    for (i = 2; i < 20; i++, wall_index++)
    {

        for (j = 1; j < SCREEN_WIDTH; j++)
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
void swap(char *str1, char *str2)
{
    char *tem = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(tem, str1);
    strcpy(str1, str2);
    strcpy(str2, tem);
    free(tem);
}
