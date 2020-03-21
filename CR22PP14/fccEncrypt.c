#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 30

int ccEncrypt_file(FILE *input_stream, const char *output_filename, int shift);
int is_ccEncrypted(const char *filename);

/***********************************************************
 * main: Prompts user for name of file to be encrypted.    *
 *       Prompts user for shift amount. Indicates          *
 *       successful operation, otherwise prints console    *
 *       error message(s) corresponding to nature          *
 *       of error(s).                                      *
 ***********************************************************/

int main(void)
{
	char input_fname[NAME_LEN];
	char *output_fname;
	FILE *fp_in;
	int key;

	printf("Enter name of file to be encrypted: ");
	read_line(input_fname, NAME_LEN);

	if (is_ccEncrypted(input_fname))
	{
		fprintf(stderr, "Error: \"%s\" is an encrypted file\n", input_fname);
		exit(EXIT_FAILURE);
	}

	if ((fp_in = fopen(input_fname, "r")) == NULL)
	{
		fprintf(stderr, "Error: can't open \"%s\"\n", input_fname);
		exit(EXIT_FAILURE);
	}

	printf("Enter shift amount: ");
	scanf("%d", &key);
	while (key < 1 || key > 25)
	{
		fprintf(stderr, "Error: please enter shift amount within range (1-25): ");
		scanf("%d", &key);
	}

	output_fname = strcat(input_fname, ".enc");

	if (ccEncrypt_file(fp_in, output_fname, key))
	{
		fprintf(stderr, "Caesar Cipher encrypted file contents output to\n");
                fprintf(stderr, "\"%s\"; up to point of termination\n", output_fname);
        }
        else
        {
                printf("Operation Successful: Caesar Cipher encryted file contents\n");
                printf("output to \"%s\"\n", output_fname);
        }

	fclose(fp_in);
	return 0;
}

/***********************************************************
 * ccEncrypt_file: Caesar Cipher encrypts contents of file *
 *                 passed as an open FILE pointer. Shift   *
 *                 amount and output filename specified    *
 *                 as arguments corresponding to           *
 *                 parameters. If read/write errors occur, *
 *                 prints console error message indicating *
 *                 how much data has been encrypted and    *
 *                 returns non-zero value. Otherwise,      *
 *                 returns zero. Also prints error message *
 *                 and terminates program if output file   *
 *                 can't be opened or created.             *
 *                 Dependent on headers <stdio.h> and      *
 *                 <stdlib.h>.                             *
 ***********************************************************/

int ccEncrypt_file(FILE *input_stream, const char *output_filename, int shift)
{
	int ch_cnt = 1, line_cnt = 1, error_cnt = 0;
	FILE *output_stream;
	int ch;

	if ((output_stream = fopen(output_filename, "w")) == NULL)
	{
		fprintf(stderr, "Error: can't create \"%s\"\n", output_filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(input_stream)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			ch = ((ch - 'a') + shift) % 26 + 'a';
		if (ch >= 'A' && ch <= 'Z')
			ch = ((ch - 'A') + shift) % 26 + 'A';
		if (putc(ch, output_stream) == EOF)
		{
			fprintf(stderr, "Error: write error encountered\n");
			error_cnt++;
			break;
		}

		if (ch == '\n')
		{
			ch_cnt = 1;
			line_cnt++;
		}
		ch_cnt++;
	}
	if (ferror(input_stream))
	{
		fprintf(stderr, "Error: read error encountered\n");
		error_cnt++;
	}

	if (error_cnt != 0)
		fprintf(stderr, "Point of Termination: Row-%d  Col-%d\n", line_cnt, ch_cnt);

	fclose(output_stream);
	return error_cnt;
}

/***********************************************************
 * is_ccEncrypted: Tests whether filename extension is     *
 *                 .enc. If so, returns one; otherwise,    *
 *                 returns zero.                           *
 ***********************************************************/

int is_ccEncrypted(const char *filename)
{
	const char *p = filename;

	while (*p)
		p++;
	p -= 4;

	if (strcmp(p, ".enc") == 0)
		return 1;
	return 0;
}
