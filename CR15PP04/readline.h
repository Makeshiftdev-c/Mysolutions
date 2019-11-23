#ifndef READLINE_H
#define READLINE_H

/************************************************************
* read_line: Reads series of characters and stores them in  *
*            str, up to n - 1 character; terminates when a  *
*            newline character is read; formats array of    *
*            characters into a string by inserting null     *
*            character upon termination; returns length     *
*            of string.                                     *
*************************************************************/

int read_line(char str[], int n);

#endif
