#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ncurses.h>

#define MAXX 120
#define MAXY 37
#define TRIANGLE_WIDTH 30
#define TRIANGLE_Height 15

void draw_circle(int center_x, int center_y, double radius, char fillch){
    for (int x = (radius + 1) * (-1.0); x < radius + 1;x++){
        for (int y = (radius + 1) * (-1.0); y < radius + 1;y++){
            double dist = sqrt((double)(x * x) + (double)(y * y * 4));
            if(dist<=radius){
                //draw
                mvaddch(center_y + y, center_x + x, fillch);
            }
        }
    }
}

void draw_rectangle(int leftx, int topy, int width, int height, char fillch){
    for (int x = leftx; x < leftx + width;x++){
        for (int y = topy; y < topy + height;y++){
            mvaddch(y, x, fillch);
        }
    }
}

int main(int argc, char **argv){

    if(argc<1){
        printf("usage: %s <your name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char btnch = ' ';
    char triangletopch = '\\';
    char trianglebottomch = '/';
    char bkgndch = '|';

    char *yourname = NULL;
    if(argc>1){
        yourname = argv[1];
    }

    //Initialize curses
    WINDOW *ui = initscr();
    if(ui==NULL) return false;

    //draw rectangle
    draw_rectangle(0, 0, MAXX, MAXY, bkgndch);

    //round the vorners
    double radius = 16.9;
    double xoffs = 8;
    double yoffs = 4;

    //top left
    draw_circle(radius + xoffs, yoffs + radius / 2, radius, btnch);
    //top right
    draw_circle(MAXX - (radius + xoffs), yoffs + radius / 2, radius, btnch);
    //bottom right
    draw_circle(MAXX - (radius + xoffs), MAXY - (yoffs + radius / 2), radius, btnch);
    //bottom left
    draw_circle(radius + xoffs, MAXY - (yoffs + radius / 2), radius, btnch);

    draw_rectangle(radius + xoffs, yoffs, MAXX - ((xoffs + radius) * 2), MAXY - (yoffs * 2), btnch);
    draw_rectangle(xoffs, yoffs + (radius / 2), MAXX - (xoffs * 2) + 1, MAXY - ((yoffs + (radius / 2) * 2)), btnch);

    //draw play triangle
    
    int midx = (MAXX / 2) + 3;
    int midy = MAXY / 2;

    int trileft = midx - (TRIANGLE_WIDTH / 2);
    for (int x = 0; x < TRIANGLE_WIDTH;x++){
        double yrise = (((double)TRIANGLE_Height / 2.0) * ((double)TRIANGLE_WIDTH - x) / ((double)TRIANGLE_WIDTH));

        for (int y = 0; y < yrise;y++){

            color_set(1, NULL);
            mvaddch(midy - y, trileft + x, triangletopch);
            mvaddch(midy + y, trileft + x, trianglebottomch);
        }
    }

        char celebration_string[MAXX];
    if(yourname){
        snprintf(celebration_string, MAXX, "  %s -- 25000 subscibers!  ", yourname);
    }
    else{
        snprintf(celebration_string, MAXX, "  25000 subsctibers!  ");
    }
    mvaddstr(MAXY, midx - (strlen(celebration_string) / 2), celebration_string);

    //wait until ketpressed
    getch();

    //clean up the ui
    delwin(ui);
    endwin();

    return EXIT_SUCCESS;
}