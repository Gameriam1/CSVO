/*
 * The actual in main
 */
#include <string>
#include <iostream>
#include<fstream>       //File Streams
#include<ncurses.h>     //N Curses Library
#include<stdlib.h>      //srand
#include<time.h>        //time
#include <stdio.h>

#include<string> //to_string c++ 11 function
#include<vector> //vectors, obviously, lol.
using namespace std;

void initCurses();
void endCurses();

int main() {
    char input;
    int x,y; //window pos
    initCurses();
    getyx(stdscr,y,x);
    while (input != 'q')
    {
        input = wgetch(stdscr);
        move(y,0); //move cursor to current line start
        clrtoeol(); //clear to EoL
//        move(y,x); //move cursor back //may not be needed with EOL
        printw("%c",input);
    }
    endCurses();
    return 0;
}

void initCurses(){
    // Curses Initialisations
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw("Welcome - Press Q to Exit\n");
}
void endCurses(){
    refresh();
//    getch(); //Make user press any key to close
    endwin();
}