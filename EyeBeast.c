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

static Image emptyImg, heroImg, chaserImg, blockImg, boundaryImg, invalidImg;

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
	EMPTY, HERO, CHASER, BLOCK, BOUNDARY
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
// factored common fields
	ActorKind kind;
	int x, y;
	Image image;
	bool isTasty;
	union {
// specific fields for each kind
		Hero hero;
		Chaser chaser;
		Block block;
		Boundary boundary;
	} u;
} ActorStruct, *Actor;

#define WORLD_SIZE_X	31
#define WORLD_SIZE_Y	18
#define N_MONSTERS		5
#define N_BLOCKS		110

typedef struct {
	Actor world[WORLD_SIZE_X][WORLD_SIZE_Y];
	Actor hero;
	Actor monsters[N_MONSTERS];
} GameStruct, *Game;

// 10 frames per second
int frame; // TODO podemos ter esta variavel global aqui?

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
		tyAlertDialog("Game over", "You lost!");
		tyQuit();
		//comandRestart(); TODO
}

/******************************************************************************
 * heroAnimation - The hero moves using the cursor keys
 * INCOMPLETE!
 ******************************************************************************/
void heroAnimation(Game g, Actor a)
{
	int dx = tyKeyDeltaX(), dy = tyKeyDeltaY();
	int nx = a->x + dx, ny = a->y + dy;
	if (cellIsEmpty(g, nx, ny))
		actorMove(g, a, nx, ny);
	else{
		switch (g->world[nx][ny]->kind){
			case CHASER:
				LoseGame();
				break;
			case BLOCK:
				pushBlock(g, g->world[nx][ny], dx, dy);
				break;
			default: break;
		}
	}
}

void pushBlock(Game g, Actor a, int dx, int dy) {
	Actor block = a;
	while(!cellIsEmpty(g, block->x+dx, block->y+dy)){
		block = g->world[block->x+dx][block->y+dy];
		switch(block->kind){
			case BLOCK:
				break;
			default:
				return; 
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
}

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

void chaserAnimation(Game g, Actor a){
	int nx;
	int ny;
	int heroX = g->hero->x;
	int heroY = g->hero->y;

	if(heroX > a->x){
		nx = a->x + 1;
	} else if (heroX < a->x){
		nx = a->x - 1;
	}
	else {
		nx = a->x;
	}
	
	if(heroY > a->y){
		ny = a->y + 1;
	} else if (heroY < a->y){
		ny = a->y - 1;
	}
	else {
		ny = a->y;
	}

	if(g->world[nx][ny] != NULL){
		if(g->world[nx][ny]->isTasty){
			LoseGame();
		}
	}

	while(!cellIsEmpty(g, nx, ny)){
		nx = a->x + (tyRand(3) - 1);
		ny = a->y + (tyRand(3) - 1);
	}

	actorMove(g, a, nx, ny);
}

/******************************************************************************
 * actorAnimation - The actor behaves according to its kind
 * INCOMPLETE!
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
 * COMPLETE!
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
 * COMPLETE!
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
 * COMPLETE! This code is to change
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

void isGameWon(Game g){
	int numMonsters = sizeof(g->monsters) / sizeof(Actor);
	for(int i = 0; i < numMonsters; i++){
		Actor* adjacent = getAdjacentCells(g, g->monsters[i]->x, g->monsters[i]->y);
		for(int j = 0; j < 8; j++){
			if(adjacent[j] != NULL)
				return;
		}
	}
	tyAlertDialog("You won", "You win!!!");
	tyQuit();
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
 * INCOMPLETE!
******************************************************************************/
void gameAnimation(Game g) {
	actorAnimation(g, g->hero); 
	
	if(frame % 10 == 0){
		for(int i = 0 ; i < N_MONSTERS ; i++) 
			actorAnimation(g, g->monsters[i]);	
		isGameWon(g);
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
	frame = frame + 1;
}

/****************************************************************************** 
 * tyHandleStart - Program initialization
 ******************************************************************************/
void tyHandleStart(void)
{
	tySecondsSetZero();
	tySetSpeed(5);
	frame = 0;
	game = gameInit(game);
}
