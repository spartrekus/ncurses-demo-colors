

////////////////////////////////////////////////////////////////////////////////////
// demo of darker and brighter colors for the Linux console terminal (/dev/ttyX)
// Author: Spartrekus
////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

void quit(void)
{
  endwin();
}


void colornorm(void)
{
    attroff(  A_REVERSE );
    attroff( A_BOLD );
    attroff( A_BLINK );
    attroff( A_UNDERLINE );
    color_set( 7, NULL ); 
}

int main(void)
{
  initscr();			
  curs_set( 0 );
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);

  init_pair(8, COLOR_BLACK, COLOR_YELLOW);
  color_set( 7 , NULL ); attroff( A_REVERSE ); mvprintw( 2,2, "Darker  ;  Brighter (bold)" );

  int x = 5; int i = 1;
  for( i = 0; i <= 7 ; i++)  //ncurses as by default 8 colors
  { 
    colornorm(); 

    color_set( i , NULL );
    mvprintw( x, x , "%d ", i );

    attron( A_REVERSE );
    attroff( A_BOLD );
    color_set( i , NULL );
    printw( "%d", i );

    attroff( A_REVERSE );
    attron(  A_BOLD );
    color_set( i , NULL );
    printw( " ; %d", i );

    colornorm(); printw( " " );

    // reverse and bold
    color_set( i , NULL );
    attron( A_REVERSE );
    attroff( A_BOLD ); //for the console
    attron(  A_BLINK ); //for the console
    printw( " R%d", i );

    x += 2; 
    colornorm(); printw( " " );
    color_set( 7 , NULL ); printw( " (#.%d)", i );
  } 

  refresh();
  x += 2; 
  attroff( A_REVERSE );
  color_set( 7, NULL ); mvprintw(  x, 5 , "<Press Key>" );
  getch(); 

  curs_set( 1 );
  endwin();			/* End curses mode		  */
  return(0);
}

