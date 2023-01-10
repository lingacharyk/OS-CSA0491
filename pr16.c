    #include <stdio.h>
    int main () { 
      FILE *fp;
      int c;
      fp = fopen("file.txt","w+");
      fputs("This is study.com", fp);
      // We are using fseek() to shift the file pointer to the 7th position.
      fseek( fp, 7, SEEK_SET );
     
    //Now we overwrite C programming in the 7th position
      fputs(" C Programming", fp);
     
    //Now we print the current position of the file pointer using ftell()
      printf("The current position of the file pointer is: %ld\n", ftell(fp));
    //We take the file pointer to the beginning of the file.
      rewind(fp);
     
    //Now we verify if rewind() worked using ftell().
      printf("The current position of the file pointer is: %ld\n", ftell(fp));
      while(1) { 
       c = fgetc(fp);
       if( feof(fp) ) { 
        break;
       }
       printf("%c", c);
      }
      fclose(fp);
      return(0);
    }
