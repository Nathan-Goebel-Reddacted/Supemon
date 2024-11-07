#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct Supemon;

typedef struct {
char name[10];
void (*effect)(int, struct Supemon *, struct Supemon *);
}move;


typedef struct {
char name[10];
int level;
unsigned int xp;
int hp[2];
unsigned int attack[2];
unsigned int defence[2];
unsigned int evasion[2];
unsigned int accuracie[2];
unsigned int speed;
unsigned int move_id[2];
}Supemon;


Supemon Dex(int id);
char* get_move_name(unsigned int id);
void move_effect(unsigned int id, Supemon *target, Supemon *launcher);

typedef struct {
    char name[50];
    char description[255];
    int buy_price;
    int sell_price;
} Item;

#endif  // HEADER_H_INCLUDED
