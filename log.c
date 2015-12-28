#include <stdio.h>
#include <time.h>
main ()
{
  time_t rawtime;
  struct tm *timeinfo;
  
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  
  FILE *fp =fopen("log.txt", "a"); //appending is important, but if you want to only last log, replace "a" with "w"
  if (fp == NULL)
    {
      printf("An error occured while opening the file.\n");
      exit(1);
    }
  
  const char *text ="The system was logged in at: ";
  fprintf("%s%s\n", text, asctime(timeinfo) );
  fclose(fp);
}
