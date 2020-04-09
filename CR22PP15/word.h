#ifndef WORD_H
#define WORD_H

/***********************************************************
 * read_word: Reads the next word from the input stream    *
 *            and stores it in word. Makes word empty if no*
 *            word could be read because of end-of-file.   *
 *            Truncates the word if its length exceeds len.*
 *            Returns of the word.                         *
 ***********************************************************/

int read_word(FILE *input, char *word, int len);

#endif
