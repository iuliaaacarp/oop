#include <iostream>
#include "song.h"
#include "DynamicArray.h"
#include "Repository.h"

int main() {
    {
        Song s{"Lady Gaga", "Shallow", 3, 40, "https//ladygaga"};
        std::cout << s.getArtist() << " "<< s.getTitle() << std::endl;
        /*
        DynamicArray d{2};
        d.add(3);
        d.add(1);
        d.add(2);
        std::cout << d.getSize();

        DynamicArray d2{d}; // they point to the same point in memory --> CRASH
        std::cout << d2.getSize() << std::endl;

        DynamicArray d3{10};
        d3.add(3);
        d3.add(1);
        // d3 = d; by default is not ok

        d3.operator = (d);
        std::cout << d3.getSize() << std::endl;
        */
        Repository repository{};
        repository.add(s);
        std::cout << "Repository size:" <<repository.getSize() << std::endl;
    }
    return 0;
}
