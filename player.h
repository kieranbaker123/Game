// player.h

#include<string>

class Player
{
private:
    int xpos;
    int ypos;

public:
    void move(char);
    int xPos();
    int yPos();
    void setx(int);
    void sety(int);

};
