/*
 * $Id: pkgfootprint.c,v 1.6 2012/05/31 10:39:00 han Exp $
 *
 * Simple c code to parse output from ``tar tzvf tarball.tgz'' into a
 * ``footprint''
 *
 * Written by Han Boetes <hboetes@gmail.com>, released in public domain.
 */
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int ch, infield = 0, fieldcount = 1, skiptab = 0;

	for (;;)
	{
		ch = getchar();
		switch (ch)
		{
		case EOF:
			exit(0);
		case ',':
			/* Check if we found a device. */
			if (fieldcount == 5) {
				fieldcount--;
				skiptab = 1;
			}
			break;
		case ' ':
			if (infield == 1)
			{
				infield = 0;
				switch (fieldcount)
				{
				case 1:
					putchar('\t');
					break;
				case 3:
					putchar('/');
					break;
				case 4:
					if (skiptab == 0)
						putchar('\t');
					else
						skiptab = 0;
					break;
				case 9:
					putchar(' ');
					break;
				case 10:
					putchar(' ');
					break;
				case 11:
					putchar(' ');
					break;
				default:
					;
				}
				fieldcount++;
			}
			break;
		case '\n':
			fieldcount = 1;
			putchar(ch);
			break;
		default:
			infield = 1;
			if (fieldcount == 1 ||
			    fieldcount == 3 ||
			    fieldcount == 4 ||
			    fieldcount >= 9)
				putchar(ch);
		}
	}
}
