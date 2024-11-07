#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"  // NOLINT

move movedex();

Supemon Dex(int id) {
    Supemon Supmander;
    snprintf(Supmander.name, sizeof(Supmander.name), "Supmander");
    Supmander.level = 1;
    Supmander.xp = 0;
    Supmander.hp[0] = 10; Supmander.hp[1] = 10;
    Supmander.attack[0] = 1; Supmander.attack[1] = 1;
    Supmander.defence[0] = 1; Supmander.defence[1] = 1;
    Supmander.evasion[0] = 1; Supmander.evasion[1] = 1;
    Supmander.accuracie[0] = 2; Supmander.accuracie[1] = 2;
    Supmander.speed = 1;
    Supmander.move_id[0] = 1;
    Supmander.move_id[1] = 3;

    Supemon Supasaur;
    snprintf(Supasaur.name, sizeof(Supasaur.name), "Supasaur");
    Supasaur.level = 1;
    Supasaur.xp = 0;
    Supasaur.hp[0] = 9; Supasaur.hp[1] = 9;
    Supasaur.attack[0] = 1; Supasaur.attack[1] = 1;
    Supasaur.defence[0] = 1; Supasaur.defence[1] = 1;
    Supasaur.evasion[0] = 3; Supasaur.evasion[1] = 3;
    Supasaur.accuracie[0] = 2; Supasaur.accuracie[1] = 2;
    Supasaur.speed = 2;
    Supasaur.move_id[0] = 2;
    Supasaur.move_id[1] = 4;

    Supemon Supirtle;
    snprintf(Supirtle.name, sizeof(Supirtle.name), "Supirtle");
    Supirtle.level = 1;
    Supirtle.xp = 0;
    Supirtle.hp[0] = 9; Supirtle.hp[1] = 9;
    Supirtle.attack[0] = 1; Supirtle.attack[1] = 1;
    Supirtle.defence[0] = 1; Supirtle.defence[1] = 1;
    Supirtle.evasion[0] = 3; Supirtle.evasion[1] = 3;
    Supirtle.accuracie[0] = 2; Supirtle.accuracie[1] = 2;
    Supirtle.speed = 2;
    Supirtle.move_id[0] = 2;
    Supirtle.move_id[1] = 5;

    switch (id) {
    case 1:return Supmander; break;
    case 2:return Supasaur; break;
    case 3:return Supirtle; break;
    default:return Supmander;
    }
}

