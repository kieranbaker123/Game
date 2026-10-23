// enemy.h

class Enemy
{
    private:
        float hitPoints = 20;
        float x = 100;
        float y = 100;
        float speed = 2;
        float angle = 0;
        int attackDmg = 1;
        int attackTimer = 0;
        float attackRange = 12;

    public:

        Enemy(float,float);
        bool shouldAttack(int,int);
        void continueAttack();
        void move(int,int);
        void attack();
        void draw();
        int getX();
        int getY();
};
