#include <iostream>

int main() {
    int xs, ys, xt, yt;
    std::cin >> xs >> ys;
    std::cin >> xt >> yt;

    int relx {xt-xs};
    int rely {yt-ys};
    std::string path {};


    if (relx == 0 ) { std::cout << (rely>0 ? "N\n" : "S\n");}
    else if (rely == 0) { std::cout << (relx>0 ? "E\n" : "W\n");}
    else {
        if ( abs(relx) > abs(rely) ) {
            (relx > 0) ? path += "E\n" : path += "W\n";
        } else if ( abs(rely) > abs(relx) ) {
            (rely > 0) ? path += "N\n" : path += "S\n";
        }

        (rely > 0) ? path += "N" : path += "S";
        (relx > 0) ? path += "E" : path += "W";
    }
    
    return 0;

    return 0;
}