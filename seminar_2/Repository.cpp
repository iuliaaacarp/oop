//
// Created by iulia on 3/19/2026.
//

#include "Repository.h"

void Repository::add(const Song& song) {
    this->songs.add(song);
}

int Repository::getSize() {
    return this->songs.getSize();
}