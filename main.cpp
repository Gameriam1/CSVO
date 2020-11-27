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
    int time = 115;
    int x,y; //window pos
    string test;

    //Do map stuff, use standard IO
    cin>>test;
    cout<<test;

    //do game setup

    //init curses window
    initCurses();
    getyx(stdscr,y,x);

    //game loop
    while (input != 'q' && time != 0)
    {
        input = wgetch(stdscr);
//        move(y,0); //move cursor to current line start
//        clrtoeol(); //clear to EoL
//        move(y,x); //move cursor back //may not be needed with EOL
        clear();
        printw("Time left: %d\n",time);
        printw("%c",input);
        time--;
    }

    //game is over
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
    printw("\nRound over\n");
    getch(); //Make user press any key to close
    endwin();
}