#ifndef READNUMS_H
#define READNUMS_H

/***********************************************************
 * read_numbers: Reads digits from input and stores them   *
 *               in str; ignores non-numeric characters.   *
 *               Truncates the sequence if its length      *
 *               exceeds n. Returns the number of digits   *
 *               stored. Returns EOF is end-of-file is     *
 *               detected.                                 *
 ***********************************************************/

int read_numbers(FILE *source, char str[], int n);

#endif
