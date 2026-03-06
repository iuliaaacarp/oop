#include "planet.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *createPlanet(char *name, char *type, double dist){
    Planet *p = malloc(sizeof(Planet));
    if (p == NULL) return p;
    p->name = malloc((strlen(name) + 1)* sizeof(char));
    if (p->name == NULL) {
        free(p);
        return NULL;
    }
    strcpy(p->name, name);
    p->type = malloc((strlen(name) + 1) * sizeof(char));
    if (p->type == NULL) {
        free(p);
        return NULL;
    }
    strcpy(p->type, type);
    p->distanceToEarth = dist;
    return p;
}

void destroyPlanet(Planet *p) {
    if (p == NULL) return;
    free(p->type);
    free(p->name);
    free(p);
}

char *getType(Planet *p) {
    if (p == NULL) return NULL;
    return p->type;
}

void testPlanet() {
    Planet *p = createPlanet("Jupiter", "gas", 3.5);

    assert(strcmp(p->name, "Jupiter") == 0);
    assert(strcmp(p->type, "gas") == 0);

    destroyPlanet(p);
}
