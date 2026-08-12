#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char ** argv) {

  openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
 
  if(argc!=3) {
    syslog(LOG_ERR, "Invalid number or arguments %d", argc);
    printf("Usage: %s <file to write> <string to write>\n", argv[0]);
    return 1;
  }

  printf("File=%s\n", argv[1]);
  printf("String=%s\n", argv[2]);

  syslog(LOG_DEBUG,  "Writing %s to %s" , argv[2], argv[1]);
  FILE *out=fopen(argv[1],"wt");
  if(!out) {
     syslog(LOG_ERR,  "Cannot open file %s for writing\n" , argv[1]);
     return 1;
  } else {
    if(fprintf(out,"%s\n", argv[2]) < 0) {
       syslog(LOG_ERR,  "fprintf for file %s has failed\n" , argv[1]);
       fclose(out);
       return 1;
    }
    syslog(LOG_DEBUG,  "Writing %s to %s completed" , argv[2], argv[1]);
    fclose(out);
  }
  
  return 0;
}
