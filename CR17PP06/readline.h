#ifndef READLINE_H
#define READLINE_H

/************************************************************
* read_line: Skips leading space characters, then reads the *
*            remainder of the input line and stores it in   *
*            str. Truncates the input if it's length exceeds*
*            n. Returns the number of characters stored.    *
*************************************************************/

int read_line(char str[], int n);

#endif
