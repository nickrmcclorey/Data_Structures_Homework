#include "game.h"
#include <string>
using namespace std;

class VideoGame : public Game {
public:
    string username;

    void setUsername(string input);
    string getUsername();
    void Play();
    void Winner();
};