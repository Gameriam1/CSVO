
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

 //void initCurses();
//void endCurses();
/*
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
     if (input == 'c') { // this part will force a refresh
         clear();
         //refresh(); //might be a better function here
         printw("Forced Refresh \n",time);
         //printw("%c",input);
     } 
        input = wgetch(stdscr);
//        move(y,0); //move cursor to current line start
//        clrtoeol(); //clear to EoL
//        move(y,x); //move cursor back //may not be needed with EOL
      
        clear();
        printw("Time left: %d\n",time);
        printw("%c",input);
        if (input != 'c'){
         time--;
        }
    }

    //game is over
    endCurses();
    return 0;
} */

/*
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
*/
class Player{
    public:
    Player (WINDOW * win, int t, int y, char c);
    void myup();
    void mydown();
    void myleft();
    void myright();
    int getmv();
    void display();

    private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW *curwin;

};

Player::Player(WINDOW * win, int y, int x, char c) {
curwin= win;
yLoc = y;
xLoc = x;
getmaxyx(curwin, yMax, xMax);
keypad(curwin, true);
character = c;
}

void Player::myup(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc <1)
        yLoc = 1;

}

void Player::mydown(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
        yLoc = yMax-2;
        
}

void Player::myleft(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc <1)
    xLoc = 1;
}

void Player::myright(){
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
        xLoc = xMax-2;

}

int Player::getmv(){
    int choice = wgetch(curwin);
    switch(choice){
        case KEY_UP:
        myup();
        break;
        case KEY_DOWN:
        mydown();
        break;
        case KEY_LEFT:
        myleft();
        break;
        case KEY_RIGHT:
        myright();
        break;
        default:
        break;

    }
    return choice;
}

void Player::display(){
mvwaddch(curwin, yLoc, xLoc, character);
}


int main(int argc, char **argv){ 
    //incurses start
    initscr();
    noecho();
    cbreak();

//get screen size
int yMax, xMax;

getmaxyx(stdscr, yMax, xMax);

//creates the window for our input
WINDOW * playwin =newwin(20,50, (yMax/2)-10,10);
box(playwin, 0, 0);
refresh();
wrefresh(playwin);

//adds the player
Player * p = new Player(playwin, 1, 1, '@');

do {
    p-> display();
    wrefresh(playwin);
} while(p->getmv() != 'x');

//make sure programs wait before exiting
//getch(); // not need at that moment
endwin();

return 0;
}

