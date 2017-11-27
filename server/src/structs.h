//structs
#ifndef STRUCTS_H
#define STRUCTS_H
#include "msg.h"
#include <pthread.h>
#define BUF_LEN 10
#define LIMIT 2


typedef struct game
{
	char board[9];
	enum
	{
		O,
		X,
		DRAW,
		none
	} winner;
} game;


struct buffer
{
	int readIdx; //id odczytane
	int writeIdx; //id zapisane
	uint8_t player[BUF_LEN]; //numer gracza do ktorego ma zostac wyslana wiadomosc
	message_t messages[BUF_LEN];
};

struct clientSession
{
	pthread_t process;
	int notEmpty;
	int finished;
	int fd;
};

game GAME;
struct buffer IPCbuffer;
struct clientSession connections[LIMIT];
#endif
