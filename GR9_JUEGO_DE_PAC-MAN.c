//-----------CREADORES--------//
//----------ARIEL ZAPATA------//
//----------KEVIN RODRIGUEZ---//
//----------DORIAN MAZA-------//

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include<conio.h>

#define ROW 21
#define COL 72


enum move {UP,DOWN,LEFT,RIGHT,STOP}direction;
enum ghost_move {UP1,DOWN1,LEFT1,RIGHT1,STOP1} ghost1_dir,ghost2_dir;
//enum move ghost1_dir,ghost2_dir;

void move_car(enum move dir);
void ghost1_direction();
void ghost2_direction();
void ghost1_move(enum ghost_move g1_dir);
void ghost2_move(enum ghost_move g2_dir);

int car_1r,car_1c,car_2r,car_2c;
int ghost1_r, ghost1_c;
int ghost2_r,ghost2_c,ghost11,ghost22;

//EL OBJETIVO DEL JUEGO ES QUE EL PACMAN DEBE COMER MAS QUE LOS FANTASMAS
//SI EL PACMAN COME MAS GANAS EL JUEGO PERO
//SI LOS FANTASMAS COMEN MAS QUE EL PACMAN PIERDE EL JUEGO
//SI LOS FANTASMAS TOCAN EL PACMAN TAMBIEN SE PIERDE EL JUEGO
char grid[ROW][COL]= {
"_______________________________________________________________________",
"| + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + |",
"| + ******** + ******** + ******* + **** ****  ********  ****** *** + |",
"| + *      * + *      * + *  **** + *   *   *  *      *  *    * * * + |",
"| + *  **  * + *  **  * + *  *    o * ** ** *  *  **  *  *     *  * + |",
"| + *  ***** + *  **  * + *  *    + * * * * *  *  **  *  * ****   * + |",
"| + * * + +  + * *  * * + *  **** + * *   * *  * *  * *  * *  *   * + |",
"| + *** + +  + ***  *** + ******* + ***   ***  ***  ***  ***  ***** + |",
"| + + + + + + + + + + + + + + + +:V + + + + + + + + + + + + + + + + + |",
"| + *******  ******** + ********* + ******************************* + |",
"| + *******  ******** o ********* + * & @& @& @& @& @& @& @& @& @ * + |",
"| + *******  ******** + ********* + *            ************ & @ * + |",
"| + *******  ******** + ********* + *  FANTASMAS *    &     ******* + |",
"| + + o + + + + + *** + + + o + + + *     EN     *                  + |",
"| + *********** + *************** + *CONSTRUCCION*     @    ******* + |",
"| + *********** + *************** + *            ************ & @ * + |",
"| + + o + + *** + + + o +  ****** + * & @ && @ && @ && @ && @ & @ * + |",
"| + ***** + ***** + **** + ****** + * & @& @& @& @& @& @& @ & @ & * + |",
"| + ***** + ***** + **** + ****** + ******************************* + |",
"| + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + |",
"|_____________________________________________________________________|"};

void print_grid();

int main()
{
direction= STOP;
ghost1_dir = STOP1;
ghost2_dir = STOP1;
int count=20;
car_1r = 8;
car_1c =33;
car_2r = 8;
car_2c = 34;
ghost1_r=12;
ghost1_c=54;
ghost2_r=14;
ghost2_c=55;
char ch;
 print_grid();
ghost1_direction();
ghost2_direction();

 while(count)
 {
    if(_kbhit()){

       ch=getchar();
     switch(ch)
      {
        case 'd':

                direction=RIGHT;
                break;


        case 'a':

                direction=LEFT;
                break;


        case 'w':

                direction = UP;
                break;


        case 's':

                direction = DOWN;
                break;


        default:;

      }
    }

    if(grid[ghost1_r][ghost1_c]==grid[car_1r][car_1c]||grid[ghost1_r][ghost1_c]==grid[car_2r][car_2c]
       ||grid[ghost2_r][ghost2_c]==grid[car_1r][car_1c]||grid[ghost2_r][ghost2_c]==grid[car_2r][car_2c])
    {
        printf("\t\t    NO FUISTE LO SUFICIENTEMENTE RAPIDO\n");
        printf("\t\t\tMAS SUERTE PARA LA PROXIMA!!\n");
        printf("\n\t\t\t    FIN DEL JUEGO\n");

        Beep (480, 200);
Beep(1568, 200 );
Beep(1568, 200 );
Beep(1568, 200 );

Beep(739.99, 200);
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(783.99, 200 );

Beep(369.99, 200);
Beep(392, 200 );
Beep(369.99, 200);
Beep(392, 200 );
Beep(392, 400 );
Beep(196, 400 );

Beep(739.99, 200);
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );
Beep(83.99, 200 );
Beep(880, 200 );
Beep(830.61, 200);
Beep(880, 200 );
Beep(987.77, 400);

Beep(880, 200 );
Beep(783.99, 200);
Beep(698.46, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(880, 200 );
Beep(830.61, 200);
Beep(880, 200 );
Beep(987.77, 400);

Beep(1, 200 );

Beep(1108, 10);
Beep(1174.7, 200);
Beep(1480, 10 );
Beep(1568, 200 );

Beep(1, 200 );

Beep(739.99, 200);
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(783.99, 200 );
Beep(739.99, 200 );

Beep(783.99, 200 );
Beep(880, 200 );
Beep(830.61, 200);
Beep(880, 200 );
Beep(987.77, 400);

Beep(880, 200 );
Beep(783.99, 200);
Beep(698.46, 200 );

Beep(659.25, 200 );
Beep(698.46, 200 );
Beep(784, 200 );
Beep(880, 400 );
Beep(784, 200 );
Beep(698.46, 200);
Beep(659.25, 200 );

Beep(587.33, 200 );
Beep(659.25, 200 );
Beep(698.46, 200 );
Beep(784, 400 );
Beep(698.46, 200);
Beep(659.25, 200 );
Beep(587.33, 200 );

Beep(523.25, 200 );
Beep(587.33, 200 );
Beep(659.25, 200 );
Beep(698.46, 400 );
Beep(659.25, 200 );
Beep(587.33, 200 );
Beep(493.88, 200 );
Beep(523.25, 200 );

Beep(1, 400 );

Beep(349.23, 400);
Beep(392, 200 );
Beep(329.63, 200);
Beep(523.25, 200 );
Beep(493.88, 200 );
Beep(466.16, 200 );

Beep(440, 200 );
Beep(493.88, 200);
Beep(523.25, 200 );
Beep(880, 200 );
Beep(493.88, 200);
Beep(880, 200 );
Beep(1760, 200 );
Beep(440, 200 );

Beep(392, 200 );
Beep(440, 200 );
Beep(493.88, 200);
Beep(783.99, 200 );
Beep(440,  200 );
Beep(783.99, 200);
Beep(1568, 200 );
Beep(392, 200 );

Beep(349.23, 200 );
Beep(392, 200 );
Beep(440, 200 );
Beep(698.46, 200 );
Beep(415.2, 200 );
Beep(698.46, 200 );
Beep(1396.92, 200 );
Beep(349.23, 200 );

Beep(329.63, 200 );
Beep(311.13, 200 );
Beep(329.63, 200 );
Beep(659.25, 200 );
Beep(698.46, 400 );
Beep(783.99, 400 );

Beep(440, 200);
Beep(493.88, 200 );
Beep(523.25, 200 );
Beep(880, 200 );
Beep(493.88, 200 );
Beep(880,200 );
Beep(1760, 200);
Beep(440 ,200 );

Beep(392, 200 );
Beep(440, 200 );
Beep(493.88, 200 );
Beep(783.99, 200 );
Beep(440, 200 );
Beep(783.99, 200 );
Beep(1568, 200 );
Beep(392, 200 );

Beep(349.23, 200 );
Beep(392, 200 );
Beep(440, 00 );
Beep(698.46, 200 );
Beep(659.25 ,200 );
Beep(698.46, 200 );
Beep(739.99, 200 );
Beep(783.99, 200 );
Beep(392, 200 );
Beep(392, 200 );
Beep(392, 200 );
Beep(392, 200 );
Beep(196, 200 );
Beep(196, 200 );
Beep(196, 200 );

Beep(185, 200 );
Beep(196, 200 );
Beep(185,200 );
Beep(196, 200 );
Beep(207.65, 200);
Beep(220, 200 );
Beep(233.08 ,200);
Beep(246.94, 200 );
        break;
    }
    if(grid[13][28]==grid[car_2r][car_2c]||grid[10][22]==grid[car_2r][car_2c]||grid[13][6]==grid[car_2r][car_2c]
       ||grid[16][6]==grid[car_2r][car_2c]||grid[16][22]==grid[car_2r][car_2c]||grid[4][34]==grid[car_2r][car_2c])
    {
        Beep(1500,150);
    }
    if(grid[13][28]!='o'&&grid[10][22]!='o'&&grid[13][6]!='o'&&grid[16][6]!='o'&&grid[16][22]!='o'&&grid[4][34]!='o')
    {
        printf("\n\t\t\tFELICIDADES GANASTE!!\n");
        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(605,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(605,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(715,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(715,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(550,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(605,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(605,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(715,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(715,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(715,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);

        Beep(1210,200);
        Beep(825,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(1210,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);
        Beep(1430,200);
        Beep(825,200);
        Beep(1355,200);
        Beep(825,200);
        Beep(1210,200);
        Beep(825,200);
        Beep(1100,200);
        Beep(825,200);
        Beep(1100,200);
        break;
    }
    move_car(direction);
    ghost1_move(ghost1_dir);
    ghost2_move(ghost2_dir);
    Beep(400,150);
    system("cls");
    print_grid();

 }
return 0;
}

void print_grid()
{
    int i;

    for(i=0;i<ROW;i++)
    printf("%s\n",grid[i]);
    printf("EL OBJETIVO DEL JUEGO ES QUE EL PACMAN DEBE COMER MAS QUE LOS FANTASMAS\n");
    printf("**************SI EL PACMAN COME MAS GANAS EL JUEGO PERO****************\n");
    printf("*******SI LOS FANTASMAS COMEN MAS QUE EL PACMAN PIERDES EL JUEGO*******\n");
    printf("*****Y SI LOS FANTASMAS TOCAN EL PACMAN TAMBIEN SE PIERDS EL JUEGO*****\n");
    printf("**************TRUCO:COME LA COMIDA FAVORITA DE PACMAN******************\n");
    printf("_______________________________________________________________________\n");
    printf("_______________________________________________________________________\n");
    printf("Comandos para moverse:\n");
    printf("(w+enter)->Subir\n");
    printf("(s+enter)->Bajar\n");
    printf("(d+enter)->Derecha\n");
    printf("(a+enter)->Izquierda\n");
    printf("_______________________________________________________________________\n");
    printf("_______________________________________________________________________\n");
    //printf("\ng2:%d dir: %d\n",ghost22,ghost2_dir);
    //printf("\ng2:%d g2:%d\n",ghost2_r,ghost2_c);

}
void move_car(enum move dir)
{
    if(dir==UP)
    {
        if(grid[car_1r-1][car_1c]!= '*'&& grid[car_2r-1][car_2c]!='*'&&grid[car_1r-1][car_1c]!= '_'&& grid[car_2r-1][car_2c]!='_')
        {
           grid[car_1r][car_1c]=' ';
           grid[car_1r-1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r-1][car_2c]='V';
           car_1r--;
           car_2r--;
        }
    }
    else if(dir==DOWN)

    {
        if(grid[car_1r+1][car_1c]!= '*'&& grid[car_2r+1][car_2c]!='*'&&grid[car_1r+1][car_1c]!= '_'&& grid[car_2r+1][car_2c]!='_')
      {
           grid[car_1r][car_1c]=' ';
           grid[car_1r+1][car_1c]=':';
           grid[car_2r][car_2c]=' ';
           grid[car_2r+1][car_2c]='V';
           car_1r++;
           car_2r++;
      }
    }
    if(dir==LEFT)
    {
       if(grid[car_1r][car_1c-1]!= '*'&& grid[car_2r][car_2c-1]!='*'&&grid[car_1r][car_1c-1]!= '|'&& grid[car_2r][car_2c-1]!='|')
       {
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c-1]='V';
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c-1]=':';
           car_1c--;
           car_2c--;
      }
    }
    else if(dir==RIGHT)

    {
       if(grid[car_1r][car_1c+1]!= '*'&& grid[car_2r][car_2c+1]!='*'&&grid[car_1r][car_1c+1]!= '|'&& grid[car_2r][car_2c+1]!='|')
       {
           grid[car_2r][car_2c]=' ';
           grid[car_2r][car_2c+1]='V';
           grid[car_1r][car_1c]=' ';
           grid[car_1r][car_1c+1]=':';

           car_1c++;
           car_2c++;
       }
    }
}
void ghost1_direction()
{
    int ghost1;
    srand((unsigned) time(NULL));

    ghost1=(rand()%4)+1;


    if(ghost1==1)
        ghost1_dir=UP1;
        else if(ghost1==2)
            ghost1_dir=DOWN1;
    if(ghost1==3)
       ghost1_dir=LEFT1;
       else
        ghost1_dir=RIGHT1;
}

void ghost2_direction()
    {
        int ghost2;
        //srand((unsigned) time(NULL));
        ghost2=(rand()%4)+1;

        switch(ghost2)
        {
        case 1:
        case 3:


                ghost2_dir=LEFT1;
                break;

        case 2:
        case 4:

                ghost2_dir=RIGHT1;
                break;

        }

        ghost22=ghost2;
    }


void ghost1_move(enum ghost_move g1_dir)
{
 // Beep(200,200);
  int x;
  if(g1_dir==UP1)
  {

      if(grid[ghost1_r-1][ghost1_c]!= '*'||grid[ghost1_r-1][ghost1_c]!= '_')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r-1][ghost1_c]='&';
          ghost1_r--;

          if(grid[ghost1_r][ghost1_c]==grid[1][13]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][46])
          {
              x=rand()%2;
                switch (x)
                {
                case 0:

                        ghost1_dir = LEFT1;
                         break;


                case 1:

                        ghost1_dir = RIGHT1;
                        break;


                }
          }


          else if(grid[ghost1_r][ghost1_c]==grid[8][2])
            {
                x=rand()%2;
                switch (x)
                {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


                }
            }
         else if(grid[ghost1_r][ghost1_c]==grid[1][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][34])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }

         }

    }
  }
  else if (g1_dir==DOWN1)
  {
      if(grid[ghost1_r+1][ghost1_c]!= '*'||grid[ghost1_r-1][ghost1_c]!= '_')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r+1][ghost1_c]='&';
          ghost1_r++;
        if(grid[ghost1_r][ghost1_c]==grid[13][50]||grid[ghost1_r][ghost1_c]==grid[13][59])
          {
            ghost1_dir = RIGHT1;
          }
        else if(grid[ghost1_r][ghost1_c]==grid[8][13]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c]== grid[8][46]||grid[ghost1_r][ghost1_c] == grid[19][34])
           {
               x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;



            }
           }


           else if(grid[ghost1_r][ghost1_c]==grid[8][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][34])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
      }

  }
  if(g1_dir==LEFT1)
  {

      if(grid[ghost1_r][ghost1_c-1]!= '*'||grid[ghost1_r-1][ghost1_c]!= '|')
          {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c-1]='&';
          ghost1_c--;
          if(grid[ghost1_r][ghost1_c]==grid[12][50])
          {
            ghost1_dir = DOWN1;
          }

        else if(grid[ghost1_r][ghost1_c]==grid[1][13]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][46])
          {
              x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][13]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][46])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
         else if(grid[ghost1_r][ghost1_c]==grid[8][34])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][2])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

            }
         }

      }


  }
  else if (g1_dir==RIGHT1)
  {
      if(grid[ghost1_r][ghost1_c+1]!= '*'||grid[ghost1_r-1][ghost1_c]!='|')
      {
          grid[ghost1_r][ghost1_c]=' ';
          grid[ghost1_r][ghost1_c+1]='&';
          ghost1_c++;
        if(grid[ghost1_r][ghost1_c]==grid[12][59])
          {
                        ghost1_dir = DOWN1;
          }

        else if(grid[ghost1_r][ghost1_c]==grid[13][68])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    ghost1_dir = UP1;
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[1][13]||grid[ghost1_r][ghost1_c]==grid[1][24]||grid[ghost1_r][ghost1_c] == grid[1][46])
          {

            x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][13]||grid[ghost1_r][ghost1_c]==grid[8][24]||grid[ghost1_r][ghost1_c] == grid[8][46])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
          else if(grid[ghost1_r][ghost1_c]==grid[8][34])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(grid[ghost1_r][ghost1_c]==grid[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

            }
         }
      }

  }
}


void ghost2_move(enum ghost_move g2_dir)
{
 //Beep(200,250);
    int x;

    if(g2_dir==LEFT1)
    {

        if(grid[ghost2_r][ghost2_c-1]!='*'||grid[ghost2_r][ghost2_c-1]!='|')
        {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r][ghost2_c-1]='@';
          ghost2_c--;
             if(grid[ghost2_r][ghost2_c]==grid[14][50])
            {
                ghost2_dir = UP1;
            }
             else if(grid[ghost2_r][ghost2_c]==grid[12][50])
            {
                ghost2_dir = DOWN1;
            }
            else if(grid[ghost2_r][ghost2_c]==grid[19][34])
            {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
                {
                    case 0:
                    break;
                    case 1:
                    {
                        ghost2_dir = UP1;
                    break;
                    }

                }
           }
            else if(grid[ghost2_r][ghost2_c]==grid[19][2])
            {
                 x=rand()%2;
                 if(x==0||x==1)
                switch (x)
                {
                    case 0:
                        {
                            ghost2_dir= UP1;
                        break;
                        }

                    case 1:
                        {
                        ghost2_dir = RIGHT1;
                        break;
                        }

                }
            }
            if(grid[ghost2_r][ghost2_c]==grid[8][46]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][13])
            {
                x=rand()%2;
                if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = UP1;
                    break;
                    }

              }
            }
           else if(grid[ghost2_r][ghost2_c]==grid[8][34])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
              }

           }
           else if(grid[ghost2_r][ghost2_c]==grid[8][2])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    ghost2_dir = UP1;
                    break;
                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
              }

           }
           if(grid[ghost2_r][ghost2_c]==grid[1][2])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
             }
          }
          else if(grid[ghost2_r][ghost2_c]==grid[1][13]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c]==grid[1][46])
          {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir=LEFT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                        break;
                    }
             }
          }
        }
    }
      if (g2_dir==RIGHT1)
        {
            if(grid[ghost2_r][ghost2_c+1]!='*'||grid[ghost2_r][ghost2_c+1]!='|')
            {
                grid[ghost2_r][ghost2_c+1]='@';
                grid[ghost2_r][ghost2_c]=' ';
                ghost2_c++;
               if(grid[ghost2_r][ghost2_c]==grid[12][59])
            {
                ghost2_dir = DOWN1;
            }
            else if(grid[ghost2_r][ghost2_c]==grid[14][59])
            {
                ghost2_dir = UP1;
            }
            else if(grid[ghost2_r][ghost2_c]==grid[13][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                            ghost2_dir = DOWN1;
                        break;
                        case 1:
                        {
                            ghost2_dir = UP1;
                        break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[19][34])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                        break;
                        case 1:
                        {
                            ghost2_dir = UP1;
                        break;
                        }

                    }
                }
               else if(grid[ghost2_r][ghost2_c]==grid[19][68])
                 {
                  x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][46]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][13])
                {


                   x=rand()%2;
                   if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[8][34])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[8][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = UP1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[1][46]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c]==grid[1][13])
                {


                   x=rand()%2;
                   if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
        }

     }
     if (g2_dir==UP1)
     {

             if(grid[ghost2_r-1][ghost2_c]!='*'||grid[ghost2_r-1][ghost2_c]!='_')
            {
                grid[ghost2_r][ghost2_c]=' ';
                grid[ghost2_r-1][ghost2_c]='@';
                ghost2_r--;
                if(grid[ghost2_r][ghost2_c]==grid[12][50])
            {
                ghost2_dir = RIGHT1;
            }
            else if(grid[ghost2_r][ghost2_c]==grid[12][59])
            {
                ghost2_dir = LEFT1;
            }
            else if(grid[ghost2_r][ghost2_c]==grid[13][59])
                {

                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[8][2])
                {

                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }

                    }
                }
                else if (grid[ghost2_r][ghost2_c]==grid[8][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][34])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }

                if(grid[ghost2_r][ghost2_c]==grid[1][13]||grid[ghost2_r][ghost2_c]==grid[1][24]||grid[ghost2_r][ghost2_c] == grid[1][46])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(grid[ghost2_r][ghost2_c]==grid[1][2])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }
                    }
                }
        }
     }
     if (g2_dir==DOWN1)
     {
         if(grid[ghost2_r+1][ghost2_c]!='*'||grid[ghost2_r+1][ghost2_c]!='_')
      {
          grid[ghost2_r][ghost2_c]=' ';
          grid[ghost2_r+1][ghost2_c]='@';
          ghost2_r++;
        if(grid[ghost2_r][ghost2_c]==grid[14][59])
            {
                ghost2_dir = LEFT1;
            }
             else if(grid[ghost2_r][ghost2_c]==grid[14][50])
            {
                ghost2_dir = RIGHT1;
            }
        else if(grid[ghost2_r][ghost2_c]==grid[13][59])
            {
                 x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }
            }
           else if(grid[ghost2_r][ghost2_c]==grid[8][2])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {

                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
        if (grid[ghost2_r][ghost2_c]==grid[8][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][13]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][46])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[19][2])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                    ghost2_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
           if(grid[ghost2_r][ghost2_c]==grid[19][34])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                    ghost2_dir = LEFT1;
                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
           if (grid[ghost2_r][ghost2_c]==grid[19][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = UP1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(grid[ghost2_r][ghost2_c]==grid[8][13]||grid[ghost2_r][ghost2_c]==grid[8][24]||grid[ghost2_r][ghost2_c]==grid[8][46]||grid[ghost2_r][ghost2_c]==grid[19][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }


       }
     }
}
