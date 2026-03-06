#pragma once

typedef struct{
    char *name;
    char *type;
    double distanceToEarth;
} Planet;

/* Creates a planet
 - Input: name, type - arrays of characters
                dist - double
 - Output: the planet that has been created
*/


void *createPlanet(char *name, char *type, double dist);

void destroyPlanet(Planet *p);

char *getType(Planet *p);

void testPlanet();
