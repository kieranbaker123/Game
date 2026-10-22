// enemy.h

Class Enemy
{
    Private:
        float hitPoints = 20;
        float x = 100;
        float y = 100;
        int velocity = 2;
        float angle = 0;
        int attackDmg = 1;
        bool attacking = 0;        
        int attackTimer = 0;
        float attackRange = 12;

    Public:

        bool shouldAttack(int,int);
        void continueAttack();
        void move(int,int);
        void attack();
        void draw();
        int getX();
        int getY();

}
