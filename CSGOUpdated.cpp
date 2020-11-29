
/*
 * The actual in main
 */
//#include <string>
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
class CharMap {
  public:
    CharMap();
    CharMap(char *arg);
    CharMap(char** c, std::string m, int w, int h) : 
        map(c), mapName(m), width(w), height(h){}
    ~CharMap();
    void print();
    char ** map;
    std::string mapName;
    int width;
    int height;
};



class Player : public  CharMap {
    public:
    Player (WINDOW * win, CharMap height, CharMap width, char c);
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



Player::Player(WINDOW * win,  CharMap height, CharMap width, char c) {
curwin= win;
yLoc =  CharMap::height;
xLoc = CharMap::width;
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
   // printw("choose Team: \n ", "cheese");
    

//	srand(time(NULL)); //Comment out to always have the same RNG for debugging
    CharMap *map = (argc == 2) ? new CharMap(argv[1]) : NULL; //Read in input file
    if(map == NULL){printf("Invalid Map File\n"); return 1;}  //close if no file given
    initCurses(); // Curses Initialisations
    map->print();




//get screen size
int yMax, xMax;

getmaxyx(stdscr, yMax, xMax);

//creates the window for our input

WINDOW * playwin =newwin(6,10, (yMax/2)-10,1);
box(playwin, 0, 0);
refresh();
wrefresh(playwin);

//adds the player
Player * p = new Player(playwin, CharMap::width(), CharMap::height(), '@');

do {
    p-> display();
    wrefresh(playwin);
} while(p->getmv() != 'x');

//make sure programs wait before exiting
//getch(); // not need at that moment
endwin();

delete map; map = NULL;
    printw("\ngg ez\n");
    endCurses(); //END CURSES



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
	getch(); //Make user press any key to close
	endwin();
}


//CharMap Functions
CharMap::CharMap(char *arg){
    char temp;
    std::ifstream fin(arg);
    fin >> mapName;
    fin >> height;
    fin >> temp;
    fin >> width;
    map = new char*[height]; //Allocate our 2D array
    for(int i=0; i<height; i++){
        map[i] = new char[width];
        for(int j=0; j<width; j++) //Read into our array while we're at it!
            fin >> (map[i][j]) >> std::noskipws; //dont skip whitespace
        fin >> std::skipws; //skip it again just so we skip linefeed
    }
    //for(int i=0; i<height; i++){ //Uncomment if you have issues reading
    //    for(int j=0; j<width; j++) printf("%c", map[i][j]); printf("\n");};
}

CharMap::~CharMap(){
    if(map == NULL) return;
    for(int i=0; i<height; i++)
        delete [] map[i];
    delete [] map;
}

void CharMap::print(){ //call only after curses is initialized!
    printw("Read Map: '%s' with dimensions %dx%d!\n", 
            mapName.c_str(), height, width);
    //Note the c_str is required for C++ Strings to print with printw
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++)
            printw("%c", map[i][j]);
        printw("\n");
    }   
}



/*
struct Bullet {
    Vector3 Position;
    Vector3 Rotation;
}
struct {
    struct { 
        Vector3 Position;
        Vector3 Rotation;
    } Ship;
    Vector<Bullet*> Bullets;
} Scene;

void Update(void) {
    if (Key.IsPressed(Space)) {
        CreateNewBullet();
    }
}

void UpdateBullets(void) {
    for (Bullet bullet in Scene.Bullets)
    {
        // Delete bullets here if not longer used
        // and move all others
    }
}
void Draw(void) {
    // Draw spaceship here
    ....
    // Draw bullets
    for (Bullet bullet in Scene.Bullets) {
        DrawBullet(bullet);
    }
}
*/
