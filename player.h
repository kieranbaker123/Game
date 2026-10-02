// player.h

#include<string>

class Player
{
private:
    float xpos;
    float ypos;
    float playerSpeed = 1;
    int playerSize = 10;

public:
    void move(char);
    int xPos();
    int yPos();
    void setx(int);
    void sety(int);
    void draw();
};
