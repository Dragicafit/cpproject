#include <missile.h>
#include <stdio.h>


int explose(missile* m) {
	m->parent->nb_missiles--;
}