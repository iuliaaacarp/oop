//
// Created by iulia on 3/19/2026.
//

#include "song.h"

Duration::Duration(int minutes, int seconds) {
    this->minutes = minutes;
    this->seconds = seconds;
}

Song::Song(const std::string& artist, const std::string& title, int minutes, int seconds, const std::string& link) {
    this->artist = artist;
    this->title = title;
    this->duration = Duration{minutes, seconds};
    this->link = link;
}

std::string Song::getArtist() const {
    return this->artist;
}

std::string Song::getTitle() const{
    return this->title;
}

Song::Song() {
    this->artist = "";
    this->title = "";
    this->duration = Duration{};
    this->link = "";
}
