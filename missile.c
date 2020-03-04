#include "missile.h"
#include <stdio.h>
#include "main.h"
#include "robot.h"

int explose(missile *m) { m->parent->nb_missiles--; }
