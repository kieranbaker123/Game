// player.h

#include<string>

class Player
{
private:
    float xpos;
    float ypos;

public:
    void move(char);
    int xPos();
    int yPos();
    void setx(int);
    void sety(int);

};
