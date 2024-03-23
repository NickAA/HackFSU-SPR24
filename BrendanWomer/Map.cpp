/*
Brendan Womer
23 mar 2024 - sat
Hackathon 
--create something, anything, and it's graded at 8pm.



text based adventure

-game

pl


*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


struct Gamedata {
    //[1] x     [1] y
    int curr_positionx;
    int curr_positiony;
    int map[9][9];
};

struct Player {
    int ID;
    string name;
    int health;
    int mana;
    int level;
    int dmgMod = 1 + (level*.20);
    // int currposition[1][1] = {0};
};

struct Equipment {
    //player weapon data
    string weapontype;
    int damagelow;
    int damageupper;

    //player armor data
    string armorType;
    int dmgMod;
};


void generatemap(int, int, Gamedata*);
bool game(Player*, Gamedata*);
void menu(Player*);
void map(Player*);
void printmap(Gamedata*);
void initmap(Gamedata*);
string getName();



int main() {
    Player *player = new Player;
    
    Gamedata *gamedata = new Gamedata;
    srand(time(0));
    menu(player);
    game(player, gamedata);


    return 0;
}



void initmap(Gamedata *gamedata) {
/* 
value[x][0] - (X) - means can't enter
value[x][1] - valid square
value[x][2] - uninintialized

        [0]  [1]  [3]  [4]  [5]  [6]  [7]  [8] 
        _-____-____-____-____-____-____-____-_
[1]|     [X]  [X]  [X]  [X]  [X]  [X]  [X] [X] 
                                         
[2]|     [X]  [S]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
        
[3]|     [X]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
         
[4]|     [X]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
                                            
[5]|     [X]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
                                 
[6]|     [X]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
                                  
[7]|     [X]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] [X] 
                               
[8]|     [X]  [X]  [X]  [X]  [X]  [X]  [X] [X] 
*/
    //the current tile being looked at
    int currtile[0][0];

    cout << "\n--here--\n";
    //will be a temp variable used to check the neighboring tiles
    int tileabove, tilebelow, tileleft, tileright;
    int map[9][9];

    //sets all values of map matrix to 2 -- this will be the arbritary value indicating a square hasnt been generated.    //starting from 0 -> 8
    for (int r = 0; r < 9; r++) {
        
        //for the bottom and top rows, set value to 0, meaning cannot enter - invalid tile.
        for (int c=0; c < 9; c++ ) {

            if ((c==0 || c==8)) {
                gamedata->map[r][c] = -1;
                // cout << gamedata->map[r][c] << "\t";
            }

            else if (r == 0 || r == 8) {
                gamedata->map[r][c] = -1;
                // cout << gamedata->map[r][c] << "\t";
            }
            else { 
                
                gamedata->map[r][c] = 2;
                // cout << gamedata->map[r][c] << "\t";
            }

        }
    }   

    
    // gamedata->curr_positionx = 1;
    // gamedata->curr_positiony = 1;


    //set starting and endpoint.
    gamedata->map[1][1] = 1;
    gamedata->map[7][7] = 1;


    //homemmade wave fcn?
    printmap(gamedata);
    cout << (rand()%2) << "\t" << (rand()%2) <<"\t" << (rand()%2) << endl;
    for (int r = 1; r < 8; r++) {
        for (int c = 1; c < 8; c++) {
            // cout << "ebfore";
            generatemap(r, c, gamedata);
        }
    }
    printmap(gamedata);
    cout << "----here3----\n";
    // printmap(gamedata);
}

void printmap(Gamedata *gamedata){

    cout << "inside print map\n";
    for (int r = 0; r < 9; r++) {
        //for the bottom and top rows, set value to 0, meaning cannot enter - invalid tile.
        for (int c=0; c < 9; c++ ) {
            cout << gamedata->map[r][c] << "\t";
        }
        cout << "--"<< r << endl;
    }   

}

void generatemap(int r, int c, Gamedata *gamedata) {
    bool validneighbor = true;
    //from the arguments, take x and y from the tile currently indexed, then check whether or not the surrounding tiles are valid for generation
    cout<< "result: "<< gamedata->map[r][c];
    if (r == 1 && c == 1) 
        gamedata->map[1][1] = 1;
    else if (r == 7 && c == 7) 
        gamedata->map[7][7] = 1;

    if (gamedata->map[r][c] > -1 && gamedata->map[r][c] < 3) { 
        do{        
            // if(gamedata->map[r][c-1] > -1 || gamedata->map[r][c+1] > -1 || gamedata->map[r+1][c] > -1 || gamedata->map[r+1][c] != -1){ 
            //while loop will run until at least 1 adjacent tile is valid.
            // while (gamedata->map[r][c-1] == 2 || gamedata->map[r][c+1] == 2 || gamedata->map[r+1][c] ==2 || gamedata->map[r+1][c] ==2 ) {
            if (gamedata->map[r][c-1] != -1)
                gamedata->map[r][c-1] = (rand()%2);
            if (gamedata->map[r][c+1] != -1)
                gamedata->map[r][c+1] = (rand()%2);
            if (gamedata->map[r-1][c] != -1)
                gamedata->map[r-1][c] = (rand()%2);
            if (gamedata->map[r+1][c] == 2 || (gamedata->map[r+1][c] == 0 && validneighbor == false))
                gamedata->map[r+1][c] = (rand()%2);   
            
            if (gamedata->map[r][c] == 1)
                if (gamedata->map[r][c-1] == 1 || gamedata->map[r][c+1] == 1 || gamedata->map[r+1][c] ==1 || gamedata->map[r+1][c] == 1)
                    validneighbor = true;
            else
                validneighbor = false;

        } while (validneighbor == true);
    }
    // printmap(gamedata);
}
    // if(gamedata->map[r][c-1] <= 1 && gamedata->map[r][c+1] <= 1 && gamedata->map[r+1][c] <=1 && gamedata->map[r+1][c] <= 1)

    



// void initgame(Player *player, Gamedata *Gamedata) {
// }

bool game(Player *player, Gamedata *gamedata) {
    bool keeprunning = 1;
    initmap(gamedata);


    //will ONLY BE == 0 IF PLAYER WINS OR EXITS
    return keeprunning;
}

void map(Player *player){




}

void playerturn(Player *player) {



}

void menu(Player *player) {
    cout << "---Welcome to generic adventure game---\n" << "--------Press enter to continue--------" <<endl ;
    cin.ignore(256, '\n');
    // //will have more options if able to include features
    // player->name = getName();
    cout << "\n\n As you slowly open your eyes, the world around you is a blur of green foliage and dancing shadows. The gentle rustle of leaves and the distant call of unseen creatures echo through the air.\n Blinking away the haze of sleep, you realize you're lying on the damp forest floor, surrounded by towering trees whose branches reach towards the sky like skeletal fingers." <<endl;
    cout << "\n Your head throbs with a dull ache, and as you sit up, you notice a strange sensation washing over you—a profound sense of disorientation.\n You can't remember how you ended up here or even who you are. It's as if your memories have been swallowed by the darkness of the forest." << endl;
    cout << "\n But amid the confusion, there's a glimmer of reassurance. Strapped to your side is a short sword, its blade gleaming softly in the dappled sunlight filtering through the canopy above.\n And draped over your shoulders is a set of basic leather armor, worn but serviceable." << endl;
    cout << "\n With a sense of urgency tinged with uncertainty, you rise to your feet, clutching the hilt of the sword tightly in your hand. \n The forest stretches out before you, mysterious and foreboding, yet somehow beckoning you forward.\n" << endl;
}




string getName() {
    string name;
    cout << "What is your name?\n";
    cin >> name;
    
    return name;
}
