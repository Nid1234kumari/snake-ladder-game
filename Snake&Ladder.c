//Snake and Ladder Game in C

#include<stdio.h>
#include<stdlib.h>

struct Element
{
  int val;//1 to 100
  char player1;//' ' or player symbol
  char player2;//' ' or player symbol
  char snake;// ' ' or 'Ö' (153) or '▒' (177) or '¿' (168)
  char ladder;// ' ' or '╦' (203) or '╫' (215) or '╩' (202)
};

typedef struct Element Element;


int dice()
{
  int val = 0;
  srand(time(0));//seed the random generator with time
  val = rand()%6 +1;
  if(val == 6)
  {
    val += rand()%6 +1;
    if(val == 12)
    {
      val += rand()%6 +1;
      if(val == 18)
        return 0;
    }
  }
  return val;
}

void initializeSnakes(Element board[], int s)
{//8 snakes planned
  //snake 1 : 99,82,79,62,59
  board[98].snake = 153; //'Ö'
  board[81].snake = 177; //'▒'
  board[78].snake = 177; //'▒'
  board[61].snake = 177; //'▒'
  board[58].snake = 168; //'¿'

  //snake 2 : 63,58,43,38,23,18
  board[62].snake = 153; //'Ö'
  board[57].snake = 177; //'▒'
  board[42].snake = 177; //'▒'
  board[37].snake = 177; //'▒'
  board[22].snake = 177; //'▒'
  board[17].snake = 168; //'¿'

  //snake 3 : 37,24,17,4
  board[36].snake = 153; //'Ö'
  board[23].snake = 177; //'▒'
  board[16].snake = 177; //'▒'
  board[3].snake = 168; //'¿'

  //snake 4 : 75,66,55,46,35,26,15,6
  board[74].snake = 153; //'Ö'
  board[65].snake = 177; //'▒'
  board[54].snake = 177; //'▒'
  board[45].snake = 177; //'▒'
  board[34].snake = 177; //'▒'
  board[25].snake = 177; //'▒'
  board[14].snake = 177; //'▒'
  board[5].snake = 168; //'¿'


  //snake 5 : 96,85,76,65,56,45
  board[95].snake = 153; //'Ö'
  board[84].snake = 177; //'▒'
  board[75].snake = 177; //'▒'
  board[64].snake = 177; //'▒'
  board[55].snake = 177; //'▒'
  board[44].snake = 168; //'¿'

  //snake 6 : 28,13,8
  board[27].snake = 153; //'Ö'
  board[12].snake = 177; //'▒'
  board[7].snake = 168; //'¿'

  //snake 7 : 51,50,31,30,11
  board[50].snake = 153; //'Ö'
  board[49].snake = 177; //'▒'
  board[30].snake = 177; //'▒'
  board[29].snake = 177; //'▒'
  board[10].snake = 168; //'¿'

  //snake 8 : 89,72,69,52,49
  board[88].snake = 153; //'Ö'
  board[71].snake = 177; //'▒'
  board[68].snake = 177; //'▒'
  board[51].snake = 177; //'▒'
  board[48].snake = 168; //'¿'

}

void initializeLadders(Element board[], int s)
{//8 ladders planned
  //ladder8 : 80,61,60,41,40
  board[79].ladder= 203; //'╦'  '╩' (202)
  board[60].ladder = 215; //'╫'
  board[59].ladder = 215; //'╫'
  board[40].ladder = 215; //'╫'
  board[39].ladder = 202; //'╩'

  //ladder7 : 43,38,23,18
  board[42].ladder= 203; //'╦'  '╩' (202)
  board[37].ladder = 215; //'╫'
  board[22].ladder = 215; //'╫'
  board[17].ladder = 202; //'╩'

  //ladder6 : 98,83,78,63,58
  board[97].ladder= 203; //'╦'  '╩' (202)
  board[82].ladder = 215; //'╫'
  board[77].ladder = 215; //'╫'
  board[62].ladder = 215; //'╫'
  board[57].ladder = 202; //'╩'

  //ladder5 : 25,16,5
  board[24].ladder= 203; //'╦'  '╩' (202)
  board[15].ladder = 215; //'╫'
  board[4].ladder = 202; //'╩'


  //ladder4 : 74,67,54,47
  board[73].ladder= 203; //'╦'  '╩' (202)
  board[66].ladder = 215; //'╫'
  board[53].ladder = 215; //'╫'
  board[46].ladder = 202; //'╩'

  //ladder3 : 33,28,13
  board[32].ladder= 203; //'╦'  '╩' (202)
  board[27].ladder = 215; //'╫'
  board[12].ladder = 202; //'╩'

  //ladder2 : 69,52,49,32
  board[68].ladder= 203; //'╦'  '╩' (202)
  board[51].ladder = 215; //'╫'
  board[48].ladder = 215; //'╫'
  board[31].ladder = 202; //'╩'

  //ladder1 : 92,89,72
  board[91].ladder= 203; //'╦'  '╩' (202)
  board[88].ladder = 215; //'╫'
  board[71].ladder = 202; //'╩'



}

void initializeBoard(Element board[], int s)
{
  int i;
  for(i = 0; i<s; i++)
  {
    board[i].val = i+1;
    board[i].player1 = ' ';
    board[i].player2 = ' ';
    board[i].snake = ' ';
    board[i].ladder = ' ';
  }
}//initializeBoard



void printElement(Element e)
{
  printf("%3d", e.val);
  printf("%c", e.player1);
  printf("%c", e.player2);
  printf("%c", e.snake);
  printf("%c ", e.ladder);


}
void drawBoard(Element board[], int s)
{
  int i ,j, x,y;
  x = 100;
  y = x - 10;

  for(i= 1; i<11; i++ )
  {
    printf("\n");

    if(i%2 == 1)
    {//rev print say 100 to 91
      for(j = x; j>y; j--)
        printElement(board[j-1]);

      x = x - 19;//100 ka 81
      y = x+ 10;//90 ka 91
    }
    else
    {//print say 81 to 90
      for(j = x; j<y; j++)
        printElement(board[j-1]);

      x = x -1;//81 ka 80
      y = x - 10;//90 ka 70
    }//else
  }//for

}

int bitBySnake(int pos)
{
  switch(pos)
  {
    case 99:
      printf("\n Bit by Snake at 99, player drops to 59");
      return 59;
    case 63:
      printf("\n Bit by Snake at 63, player drops to 18");
      return 18;
    case 37:
      printf("\n Bit by Snake at 37, player drops to 4");
      return 4;
    case 75:
      printf("\n Bit by Snake at 75, player drops to 6");
      return 6;
    case 96:
      printf("\n Bit by Snake at 96, player drops to 45");
      return 45;
    case 28:
      printf("\n Bit by Snake at 28, player drops to 8");
      return 8;
    case 51:
      printf("\n Bit by Snake at 51, drops to 11");
      return 11;
    case 89:
      printf("\n Bit by Snake at 89, drops to 49");
      return 49;

    default:
      return pos;
  }

}

int advanceByLadder(int pos)
{
  switch(pos)
  {
    case 40:
      printf("\n Got Ladder at 40, player advances to 80");
      return 80;
    case 18:
      printf("\n Got Ladder at 18, player advances to 43");
      return 43;
    case 58:
      printf("\n Got Ladder at 58, player advances to 98");
      return 98;
    case 5:
      printf("\n Got Ladder at 5, player advances to 25");
      return 25;
    case 47:
      printf("\n Got Ladder at 47, player advances to 74");
      return 74;
    case 13:
      printf("\n Got Ladder at 13, player advances to 33");
      return 33;
    case 32:
      printf("\n Got Ladder at 32, player advances to 69");
      return 69;
    case 72:
      printf("\n Got Ladder at 72, player advances to 92");
      return 92;
    default:
      return pos;

  }


}

void play()
{
  int end = 0;
  char p1, p2, dummy;
  int pos1, pos2, current;
  int flag;

  Element board[100];
  initializeBoard(board, 100);
  initializeSnakes(board,100);
  initializeLadders(board, 100);

  //set the players
  printf("\n Enter player1 symbol ");
  fflush(stdin);
  scanf("%c", &p1);

  flag = 0;
  do
  {
    printf("\n Enter player2 symbol ");
    fflush(stdin);
    scanf("%c", &p2);
    if(p1 == p2)
    {
      printf("Symbol taken by player 1");
      flag = 1;
    }
    else
      flag = 0;
  }while(flag == 1);


  flag = 1;
  pos1 = pos2 = 1;
  do
  {
    drawBoard(board, 100);
    if(flag == 1)
    {//player1 plays
      printf("\n Player1 press any key to dice ");
      fflush(stdin);
      dummy = getch();
      current = dice();
      printf("\n Dice value : %d", current);
      if(pos1 + current > 100)
      {
        printf("\n Dice void, as you need %d", 100-pos1);
      }
      else
      {
        //erase the old position
        board[pos1-1].player1=' ';
        pos1+=current;
        pos1 = advanceByLadder(pos1);
        pos1 = bitBySnake(pos1);
        printf("\n Position : %d", pos1);
        //update board
        board[pos1-1].player1=p1;
      }
      flag++;
    }
    else if(flag == 2)
    {//player2 plays
      printf("\n Player2 press any key to dice ");
      fflush(stdin);
      dummy = getch();
      current = dice();
      printf("\n Dice value : %d", current);

      if(pos2 + current > 100)
      {
        printf("\n Dice void, as you need %d", 100-pos2);
      }
      else
      {
        //erase the old position
        board[pos2-1].player2=' ';
        pos2+=current;
        pos2 = advanceByLadder(pos2);
        pos2 = bitBySnake(pos2);
        printf("\n Position : %d", pos2);
        //update board
        board[pos2-1].player2=p2;
      }

      flag--;
    }

    if(pos1 == 100)
    {
      drawBoard(board, 100);
      printf("\n\n Player1 (%c) wins", p1);
      end = 1;
    }
    if(pos2 == 100)
    {
      drawBoard(board, 100);
      printf("\n\n Player2 (%c) wins", p2);
      end = 1;
    }


  }while(end == 0);
}

int main()
{
  play();
  return 0;
}
