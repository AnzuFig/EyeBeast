/*
max width = 80 columns
tab = 4 spaces
01234567890123456789012345678901234567890123456789012345678901234567890123456789
*/

/*	Linguagens e Ambientes de ProgramaÃ§Ã£o - Projeto de 2021/2022

	Eye Beast

	Program written in C/C ++ over the wxWidget platform.
	The wxWidget platform runs on Windows, MacOS and Linux.

	This file is only a starting point fo your work. The entire file can
	be changed, starting with this comment.


 AUTHORS IDENTIFICATION
	Student 1: 60313, Francisco Freitas
	Student 2: 60288, Guilherme Figueira

Comments:

?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????


 Place here the names and numbers of the authors, plus some comments, as
Â asked in the listing of the project. Do not deliver an anonymous file with
 unknown authors.
*/

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* IDENTIFICATION */

#define APP_NAME	"Eye Beast"

#define AUTHOR1		"Francisco Freitas (60313)"
#define AUTHOR2		"Guilherme Figueira (60288)"

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* INCLUDES */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "wxTiny.h"


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* STRINGS */

#define MAX_STRING	256
#define MAX_LINE	1024

typedef char String[MAX_STRING];
typedef char Line[MAX_LINE];


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* IMAGES */

/******************************************************************************
 * The images are specified in the XPM format [http://en.wikipedia.org/wiki/X_PixMap]
 * After created, each image is represented by an integer in the wxTiny library.
 ******************************************************************************/

typedef int Image;

static Image emptyImg, heroImg, chaserImg, chaserFrozenImg, blockImg, boundaryImg, invalidImg, bonusPlaceImg;

/* XPM */
static tyImage empty_xpm = {
"16 16 2 1",
"   c None",
".  c #FFFFFF",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................"};

/* XPM */
static tyImage hero_xpm = {
"16 16 3 1",
"   c None",
".  c #FFFFFF",
"+  c #000000",
"................",
"...+++...+++....",
"..+...+.+...+...",
".+.....+.....+..",
".+...+++++...+..",
".+...+++++...+..",
".+...+++++...+..",
".+.....+.....+..",
"..+...+.+...+...",
"...+++...+++....",
"................",
".....+++++......",
"....+.....+.....",
"................",
"................",
"................"};


/* XPM */
static tyImage chaser_xpm = {
"16 16 3 1",
"   c None",
".  c #FFFFFF",
"+  c #000000",
"................",
"...+++...+++....",
"..++.++.+.+++...",
".+..+++++++..+..",
".+...+++++...+..",
".+...+++++...+..",
".+...+++++...+..",
"..+...+.+...+...",
"...+++...+++....",
"................",
"................",
"....+++++++.....",
"................",
"................",
"................",
"................"};

/* XPM */
static tyImage chaserFrozen_xpm = {
"16 16 3 1",
"   c None",
".  c #8DFFF7",
"+  c #36A9E7",
"++++++++++++++++",
"+..+++...+++...+",
"+.++.++.+.+++..+",
"++..+++++++..+.+",
"++...+++++...+.+",
"++...+++++...+.+",
"++...+++++...+.+",
"+.+...+.+...+..+",
"+..+++...+++...+",
"+..............+",
"+..............+",
"+...+++++++....+",
"+..............+",
"+..............+",
"+..............+",
"++++++++++++++++"};

/* XPM */
static tyImage bonusPlace_xpm= {
"16 16 3 1",
"   c None",
".	c #FFFFFF",
"+	c #13AE4B",
"................",
"................",
"..+..........+..",
"...++......++...",
"....++....++....",
".....++..++.....",
"......++++......",
".......++.......",
"......++++......",
".....++..++.....",
"....++....++....",
"...++......++...",
"..+..........+..",
"................",
"................",
"................"};

/* XPM */
static tyImage block_xpm = {
"16 16 3 1",
"   c None",
".  c #000000",
"+  c #FFFFFF",
"................",
"................",
"..............+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"................",
"..+.+.+.+.+.+.+.",
"................"};

/* XPM */
static tyImage boundary_xpm = {
"16 16 3 1",
"   c None",
".  c #000000",
"+  c #FFFFFF",
"................",
"................",
"..............+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"....+.+.+.+.+...",
"...+.+.+.+.+..+.",
"................",
"..+.+.+.+.+.+.+.",
"................"};

/* XPM */
static tyImage invalid_xpm = {
"16 16 2 1",
"   c None",
".  c #FFFFFF",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................",
"................"};


/******************************************************************************
 * imagesCreate - Converts all the XPM images to the type Image
 ******************************************************************************/
void imagesCreate(void)
{
	emptyImg = tyCreateImage(empty_xpm);
	heroImg = tyCreateImage(hero_xpm);
	chaserImg = tyCreateImage(chaser_xpm);
	blockImg = tyCreateImage(block_xpm);
	boundaryImg = tyCreateImage(boundary_xpm);
	invalidImg = tyCreateImage(invalid_xpm);
	bonusPlaceImg = tyCreateImage(bonusPlace_xpm);
	chaserFrozenImg = tyCreateImage(chaserFrozen_xpm);
}


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* ACTORS */

/******************************************************************************
 * Constants, types and functions for all kinds of actors
 ******************************************************************************/

#define ACTOR_PIXELS_X	16
#define ACTOR_PIXELS_Y	16

typedef enum {
	EMPTY, HERO, CHASER, BLOCK, BOUNDARY, BONUS_PLACE
} ActorKind;

typedef struct {
// specific fields can go here, but probably none will be needed
} Hero;

typedef struct {
// specific fields can go here, but probably none will be needed
} Chaser;

typedef struct {
// specific fields can go here, but probably none will be needed
} Block;

typedef struct {
// specific fields can go here, but probably none will be needed
} Boundary;

typedef struct {
// specific fields can go here, but probably none will be needed
} BonusPlace;

typedef struct {
// factored common fields
	ActorKind kind;
	int x, y;
	Image image;
	bool isTasty;
	bool isFrozen;
	union {
// specific fields for each kind
		Hero hero;
		Chaser chaser;
		Block block;
		Boundary boundary;
		BonusPlace bonusPlace;
	} u;
} ActorStruct, *Actor;

#define WORLD_SIZE_X	31
#define WORLD_SIZE_Y	18
#define N_MONSTERS		5
#define N_BLOCKS		110
#define MONSTER_ANIM_DELAY	10
#define N_BONUS_CELLS_PER_CHUNK	4
#define N_BONUS_CHUNK	2
#define BONUS_MOVE_DELAY	9999999 //TODO change

typedef struct {
	Actor world[WORLD_SIZE_X][WORLD_SIZE_Y];
	Actor hero;
	Actor monsters[N_MONSTERS];
	Actor bonusCells[N_BONUS_CELLS_PER_CHUNK * N_BONUS_CHUNK];
} GameStruct, *Game;

// 10 frames per second
int frame;
int timeSinceBonus;

/******************************************************************************
 * actorImage - Get the screen image corresponding to some kind of actor
 ******************************************************************************/
Image actorImage(ActorKind kind)
{
	switch( kind ) {
		case EMPTY:		return emptyImg;
		case HERO:		return heroImg;
		case CHASER:	return chaserImg;
		case BLOCK:		return blockImg;
		case BOUNDARY:	return boundaryImg;
		case BONUS_PLACE: return bonusPlaceImg;
		default:		return invalidImg;
	}
}

/******************************************************************************
 * cellSet - Useful function to update one cell in the matrix and in the screen
 ******************************************************************************/
void cellSet(Game g, Actor a, int x, int y, Image img)
{
	tyDrawImage(img, x * ACTOR_PIXELS_X, y * ACTOR_PIXELS_Y);
	g->world[x][y] = a;	
}

/******************************************************************************
 * cellIsEmpty - Check in the matrix if a cell is empty (if contains NULL)
 ******************************************************************************/
bool cellIsEmpty(Game g, int x, int y)
{
	return g->world[x][y] == NULL;
}

/******************************************************************************
 * actorShow - Install an actor in the matrix and in the screen
 ******************************************************************************/
void actorShow(Game g, Actor a)
{
	cellSet(g, a, a->x, a->y, a->image);
}

/******************************************************************************
 * actorHide - Removes an actor from the matrix and from the screen
 ******************************************************************************/
void actorHide(Game g, Actor a)
{
	cellSet(g, NULL, a->x, a->y, emptyImg);
}

/******************************************************************************
 * actorMove - Move an actor to a new position
 * pre: the new position is empty
 ******************************************************************************/
void actorMove(Game g, Actor a, int nx, int ny)
{
	actorHide(g, a);
	a->x = nx;
	a->y = ny;
	actorShow(g, a);
}

/******************************************************************************
 * actorNew - Creates a new actor and installs it in the matrix and the screen
 ******************************************************************************/
Actor actorNew(Game g, ActorKind kind, int x, int y)
{
	Actor a = malloc(sizeof(ActorStruct));
	a->kind = kind;
	a->x = x;
	a->y = y;
	a->image = actorImage(kind);
	a->isFrozen = false;
	actorShow(g, a);
	switch(kind){
		case HERO:
			a->isTasty = true;
			break;
		default:
			a->isTasty = false;
			break;
	}
	return a;
}

void LoseGame(){
		tyAlertDialog("", "Dead Meat!!!");
		comandRestart();
		//tyQuit();
}

// Returns true if sucessful, false otherwise
bool pushBlock(Game g, Actor a, int dx, int dy) {
	Actor block = a;
	bool canContinue = true;
	while(!cellIsEmpty(g, block->x+dx, block->y+dy) && canContinue){
		block = g->world[block->x+dx][block->y+dy];
		switch(block->kind){
			case BLOCK:
				break;
			case BONUS_PLACE:
				block = g->world[block->x-dx][block->y-dy];
				canContinue = false;
				break;
			default:
				return false; 
		}
	}
	while(tyDistance(block->x, block->y, a->x, a->y) != 0){
		int tempBlockX = block->x-dx;
		int tempBlockY = block->y-dy;
		actorMove(g, block, block->x+dx, block->y+dy);
		block = g->world[tempBlockX][tempBlockY];
	}
	int tempHeroX = a->x-dx;
	int tempHeroY = a->y-dy;
	actorMove(g, a, a->x+dx, a->y+dy);
	actorMove(g, g->world[tempHeroX][tempHeroY], tempHeroX+dx, tempHeroY+dy);
	return true;
}

/******************************************************************************
 * heroAnimation - The hero moves using the cursor keys
 ******************************************************************************/
void heroAnimation(Game g, Actor a)
{
	int dx = tyKeyDeltaX(), dy = tyKeyDeltaY();
	int nx = a->x + dx, ny = a->y + dy;
	if (cellIsEmpty(g, nx, ny)){
		actorMove(g, a, nx, ny);
		replaceBonus(g, nx - dx, ny - dy);
	}
	else{
		switch (g->world[nx][ny]->kind){
			case CHASER:
				actorHide(g, a);
				LoseGame();
				break;
			case BLOCK:
				pushBlock(g, g->world[nx][ny], dx, dy);
				if(nx-dx != a->x || ny-dy != a->y){
					replaceBonus(g, nx - dx, ny - dy);
				}
				break;
			case BONUS_PLACE:
				actorMove(g, a, nx, ny);
				replaceBonus(g, nx - dx, ny - dy);
				break;
			default: break;
		}
	}
}

// Returns the bonus actor if cell is bonus
Actor cellIsBonus(Game g, int x, int y){
	int numBonus = N_BONUS_CHUNK * N_BONUS_CELLS_PER_CHUNK;
	for(int i = 0; i < numBonus; i++){
		Actor bonus = g->bonusCells[i];
		if(bonus->x == x && bonus->y == y){
			return bonus;
		}
	}
	return NULL;
}

void replaceBonus(Game g, int x, int y){
	Actor bonus = cellIsBonus(g, x, y);
	if(bonus != NULL){
		actorShow(g, bonus);
	}
}

/******************************************************************************
 * areAllBonusFilled - Verifies if all the bonus spots have a block on top
 ******************************************************************************/
bool areAllBonusFilled(Game g){
	int numBonus = N_BONUS_CHUNK * N_BONUS_CELLS_PER_CHUNK;
	int x;
	int y;
	for(int i = 0; i < numBonus; i++){
		x = g->bonusCells[i]->x;
		y = g->bonusCells[i]->y;
		switch(g->world[x][y]->kind){
			case BLOCK:
				break;
			default:
				return false;
		}
	}
	return true;
}

/******************************************************************************
 * getAdjacentCells - Returns all the adjacent cell (actors) in an Actor array
 ******************************************************************************/
Actor* getAdjacentCells(Game g, int cx, int cy){
	int arraySize = 8;
	int count = 0;
	Actor *adjacentCells = malloc(sizeof(Actor) * arraySize);
	for(int x = cx - 1; x <= cx + 1; x++){
		for(int y = cy - 1; y <= cy + 1; y++){
			if(!(x == cx && y == cy)){
				adjacentCells[count++] = g->world[x][y];
			}
		}
	}
	return adjacentCells;
}

/******************************************************************************
 * isStuck - Verifies if all the adjacent cells given by the actor array are not
 * empty.
 ******************************************************************************/
bool isStuck (Game g, Actor* adjacentBlocks){
	for(int i = 0; i < 8; i++){
		if(adjacentBlocks[i] == NULL){
			return false;
		}
		switch(adjacentBlocks[i]->kind){ // Blocks that don't count
			case BONUS_PLACE:
				return false;
				break;
			default: break;
		}
	}
	return true;
}


/******************************************************************************
 * chaserAnimation - The chaser tries to reach the player in a straight line.
 * If there is an obstacle, it moves to a random adjacent cell
 ******************************************************************************/
void chaserAnimation(Game g, Actor a){
	int x = a->x;
	int y = a->y;
	int nx;
	int ny;
	int heroX = g->hero->x;
	int heroY = g->hero->y;
	
	if(heroX > x){
		nx = x + 1;
	} else if (heroX < x){
		nx = x - 1;
	}
	else {
		nx = x;
	}
	
	if(heroY > y){
		ny = y + 1;
	} else if (heroY < y){
		ny = y - 1;
	}
	else {
		ny = y;
	}

	if(g->world[nx][ny] != NULL){
		if(g->world[nx][ny]->isTasty){
			actorMove(g, a, nx, ny);
			replaceBonus(g, x, y);
			LoseGame();
		}
		if(g->world[nx][ny]->kind == BONUS_PLACE){
			actorMove(g, a, nx, ny);
			replaceBonus(g, x, y);
			return;
		}
	}
	
	if(!isStuck(g, getAdjacentCells(g, x, y))){
		while(!cellIsEmpty(g, nx, ny)){
			nx = x + (tyRand(3) - 1);
			ny = y + (tyRand(3) - 1);
			if(g->world[nx][ny] != NULL && g->world[nx][ny]->kind == BONUS_PLACE){
				actorMove(g, a, nx, ny);
				replaceBonus(g, x, y);
				return;
			}
		}
	}

	actorMove(g, a, nx, ny);
	replaceBonus(g, x, y);
}

/******************************************************************************
 * actorAnimation - The actor behaves according to its kind
 ******************************************************************************/
void actorAnimation(Game g, Actor a)
{
	switch( a->kind ) {
		case HERO: heroAnimation(g, a); break;
		case CHASER: chaserAnimation(g, a); break;
		default: break;
	}
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* GAME */

/******************************************************************************
 * gameClearWorld - Clears the matrix and the screen
 ******************************************************************************/
void gameClearWorld(Game g)
{
	for(int y = 0; y < WORLD_SIZE_Y ; y++)
		for(int x = 0; x < WORLD_SIZE_X ; x++ )
			cellSet(g, NULL, x, y, emptyImg);
}

/******************************************************************************
 * gameInstallBoundaries - Install the boundary blocks
 ******************************************************************************/
void gameInstallBoundaries(Game g)
{
	for(int y = 0; y < WORLD_SIZE_Y ; y++)
		for(int x = 0; x < WORLD_SIZE_X ; x++)
			if( x == 0 || x == WORLD_SIZE_X - 1
			|| y == 0 || y == WORLD_SIZE_Y - 1 ) {
				actorNew(g, BOUNDARY, x, y);
			}
}

/******************************************************************************
 * gameInstallBlocks - Install the movable blocks
 ******************************************************************************/
void gameInstallBlocks(Game g)
{
	
	for(int x = 0; x < N_BLOCKS; x++){
		int nx;
		int ny;
		do{
			nx = 1 + tyRand(WORLD_SIZE_X - 2); // Generates a random integer between 1 and WORLD_SIZE_X 
			ny = 1 + tyRand(WORLD_SIZE_Y - 2); // Generates a random integer between 1 and WORLD_SIZE_Y
		} while(!cellIsEmpty(g, nx, ny));
		actorNew(g, BLOCK, nx, ny);
	}
}

/******************************************************************************
 * gameInstallMonsters - Install the monsters
 ******************************************************************************/
void gameInstallMonsters(Game g)
{	
	for(int i = 0; i < N_MONSTERS; i++){
		int nx;
		int ny;
		int heroX = g->hero->x;
		int heroY = g->hero->y;
		do{
			nx = 1 + tyRand(WORLD_SIZE_X - 2); // Generates a random integer between 1 and WORLD_SIZE_X 
			ny = 1 + tyRand(WORLD_SIZE_Y - 2);; // Generates a random integer between 1 and WORLD_SIZE_Y	
		} while(!cellIsEmpty(g, nx, ny) || tyDistance(heroX, heroY, nx, ny) <= 4 );
		g->monsters[i] = actorNew(g, CHASER, nx, ny);
	}
	
}

/******************************************************************************
 * gameInstallHero - Install the hero
 ******************************************************************************/
void gameInstallHero(Game g)
{	
	int x;
	int y;
	do{
		x = 1 + tyRand(WORLD_SIZE_X - 2);	
		y = 1 + tyRand(WORLD_SIZE_Y - 2);
	} while(!cellIsEmpty(g, x, y));
	g->hero = actorNew(g, HERO, x, y);
}


/******************************************************************************
 * installBonusChunk - Install a chunk of bonus cells.
 * 	If possible, the chunk should try to have 4 bonus spots.
 ******************************************************************************/
void installBonusChunk(Game g, int nChunk){
	int x;
	int y;
	int tempX;
	int tempY;
	int count = nChunk * N_BONUS_CELLS_PER_CHUNK;
	int randIndex;
	do{
		x = 1 + tyRand(WORLD_SIZE_X - 2);	
		y = 1 + tyRand(WORLD_SIZE_Y - 2);
	} while(!cellIsEmpty(g, x, y) || isStuck(g, getAdjacentCells(g, x, y)));

	g->bonusCells[count++] = actorNew(g, BONUS_PLACE, x, y); //First bonus cell

	for(int i = 1; i < N_BONUS_CELLS_PER_CHUNK; i++){ // The rest of the bonus cells
		Actor* adjacent = getAdjacentCells(g, x, y);
		if(isStuck(g, adjacent)){
			return;
		}
		do{
			tempX = x + (tyRand(3) - 1); 
			tempY = y + (tyRand(3) - 1);
		}while(!cellIsEmpty(g, tempX, tempY));
		x = tempX;
		y = tempY;
		g->bonusCells[count++] = actorNew(g, BONUS_PLACE, x, y);
	}
}

/******************************************************************************
 * gameInstallBonus - Install ALL the bonus spots
 ******************************************************************************/
void gameInstallBonus(Game g){
	for(int i = 0; i < N_BONUS_CHUNK; i++){
		installBonusChunk(g, i);
	}
}

/******************************************************************************
 * isGameWon - Verifies if the game is won, ie. all the monsters are stuck
 ******************************************************************************/
void isGameWon(Game g){
	int numMonsters = sizeof(g->monsters) / sizeof(Actor);
	for(int i = 0; i < numMonsters; i++){
		Actor* adjacent = getAdjacentCells(g, g->monsters[i]->x, g->monsters[i]->y);
		if(!isStuck(g, adjacent)){
			return;
		}
	}
	tyAlertDialog("", "You win!!!");
	tyQuit();
}

/******************************************************************************
 * moveBonus - Moves the bonus chunks to another random place
 ******************************************************************************/
void moveBonus(Game g){
	int numBonus = N_BONUS_CHUNK * N_BONUS_CELLS_PER_CHUNK;
	for(int i = 0; i < numBonus; i++){
		switch(g->world[g->bonusCells[i]->x][g->bonusCells[i]->y]->kind){
			case BONUS_PLACE:
				actorHide(g, g->bonusCells[i]);
				break;
			default:
				break;
		}
	}
	gameInstallBonus(g);
}

/******************************************************************************
 * gameInit - Initialize the matrix and the screen
 ******************************************************************************/
Game gameInit(Game g)
{
	if (g == NULL)
		g = malloc(sizeof(GameStruct));
	imagesCreate();
	gameClearWorld(g);
	gameInstallBoundaries(g);
	gameInstallBlocks(g);
	gameInstallHero(g); 
	gameInstallMonsters(g);
	gameInstallBonus(g);
	return g;
}

/******************************************************************************
 * gameRedraw - Redraws the entire scenario. This function is called by
 * tyHandleRedraw in very specific circumstances. It should not be used anywhere
 * else because you don't want to be constantly redrawing the whole scenario.
 ******************************************************************************/
void gameRedraw(Game g)
{
	for(int y = 0; y < WORLD_SIZE_Y; y++)
		for(int x = 0; x < WORLD_SIZE_X; x++) {
			Actor a = g->world[x][y];
			if( !cellIsEmpty(g, x, y) )
				actorShow(g, a);
		} 
}

/******************************************************************************
 * gameAnimation - Sends animation events to all the animated actors
 * This function is called every tenth of a second (more or less...)
******************************************************************************/
void gameAnimation(Game g) {
	actorAnimation(g, g->hero);
	if(frame % BONUS_MOVE_DELAY == 0){
		moveBonus(g);
	}
	if(frame % MONSTER_ANIM_DELAY == 0){
		 for(int i = 0 ; i < N_MONSTERS ; i++)
		 	if(!g->monsters[i]->isFrozen){
				actorAnimation(g, g->monsters[i]);
			}
		isGameWon(g);
	}
	
}

void checkIfBonus(Game g){
	if(areAllBonusFilled(g)){
		tyAlertDialog("You did it!", "The monsters will be frozen for some time!\nTake advantage of it!");
		for(int i = 0; i < N_MONSTERS; i++){
			g->monsters[i]->isFrozen = true; // TODO only for a few seconds
			g->monsters[i]->image = chaserFrozenImg;
		}
		timeSinceBonus = frame;
		moveBonus(g);
	}
	if((frame - timeSinceBonus) == 100){
		for(int i = 0; i < N_MONSTERS; i++){
			g->monsters[i]->isFrozen = false; // TODO only for a few seconds
			g->monsters[i]->image = chaserImg;
			//g->monsters[i]->image = chaserFrozen_xpm; (Segmentation fault)
		}
		timeSinceBonus = 0;
	}
}


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* STATUS BAR */

/******************************************************************************
 * The function status populates the status bar, at the bottom of the window
 ******************************************************************************/

#define STATUS_ITEMS	5

void status(void)
{
	String s;
	sprintf(s, "TIME = %d seg.", tySeconds());
	tySetStatusText(4, s);
}



/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/* MENU COMMANDS */

/******************************************************************************
 * Each function handles one menu command
 ******************************************************************************/

void comandAbout(void)
{
	tyAlertDialog("About", "%s\n%s\n\n%s\n%s",
		APP_NAME,
		"(Reimplementation of the original game of Chuck Shotton)",
		AUTHOR1,
		AUTHOR2);


}

void comandRestart(void)
{
	tyHandleStart();
}

void comandFinish(void)
{
	tyAlertDialog("Quit", "See you later!");
	tyQuit();
}


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/


/* FUNCTIONS REQUIRED BY THE FRAMEWORK wxTiny */

/******************************************************************************
 * Section with all the "root" "functions required by the wxTiny support system. 
 * 
 * There is no function "main" in a wxTiny program, as the main function is
 * hidden within the wxTiny library. The most important thing you need to know
 * is that the function "tyHandleStart" is called when the program begins,
 * and that function "tyHandleTime" is called periodically 10 times per second,
 * to make the program progress. In some sense, both this function make a kind
 * of main function.
 * 
 * More information about the wxTiny functions in the file "wxTiny.h".
 ******************************************************************************/

static Game game = NULL; // defined here to be available to the "root" functions

/****************************************************************************** 
 * tyAppName - specify the name of the app
 ******************************************************************************/
tyStr tyAppName(void)
{
	return APP_NAME;
}

/****************************************************************************** 
 * tyWidth - specify the width of the window
 ******************************************************************************/
int tyWidth(void)
{
	return WORLD_SIZE_X * ACTOR_PIXELS_X;
}

/****************************************************************************** 
 * tyHeight - specify the height of the window
 ******************************************************************************/
int tyHeight(void)
{
	return WORLD_SIZE_Y * ACTOR_PIXELS_Y;
}

/****************************************************************************** 
 * tyStatusItems - specify the number of slots available in the status bar
 ******************************************************************************/
int tyStatusItems(void)
{
	return STATUS_ITEMS;
}

/****************************************************************************** 
 * tyMenus - specify the menus
 ******************************************************************************/
tyStr tyMenus(void)
{
	return ":+Menu"
			":&About\tCtrl-A"
			":-"
			":&Restart\tCtrl-R"
			":-"
			":&Quit\tCtrl-Q";
}

/****************************************************************************** 
 * tyHandleMenuCommand - Handles the menu commands
 ******************************************************************************/
void tyHandleMenuCommand(tyStr command)
{
	if( strcmp(command, "About") == 0 )
		comandAbout();
	else if( strcmp(command, "Restart") == 0 )
		comandRestart();
	else if( strcmp(command, "Quit") == 0 )
		comandFinish();
	else
		tyFatalError("Unknown command: \"%s\"", command);
}

/****************************************************************************** 
 * tyHandleRedraw - redraws the window
 *
 * Automatically called in rare situations, for example if the game window is
 * minimized and then maximized
 ******************************************************************************/
void tyHandleRedraw(void)
{
	gameRedraw(game);
}

/****************************************************************************** 
 * tyHandleTime - Called periodically, around 10 time per second
 * 
 * This function does the following: animate the actors; update the status bar;
 *	possibly more things
 ******************************************************************************/
void tyHandleTime(void)
{
	status();
	gameAnimation(game);
	checkIfBonus(game);
	frame++;
}

/****************************************************************************** 
 * tyHandleStart - Program initialization
 ******************************************************************************/
void tyHandleStart(void)
{
	tySecondsSetZero();
	tySetSpeed(4);
	frame = 0;
	timeSinceBonus = 0;
	game = gameInit(game);	
}
