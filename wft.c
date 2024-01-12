/* wft.c A program which searches through text files to find matches for the given text
*   index file contains a list of files to search
*   a file searched needs to have lines starting with "#String " to allow wft to search for "String"
* if the X command, EG "wft Spaghetti X "is used exact matches will be looked for 
* by default  searching for  12345 will print text from a line of longer text e.g. #12345678 
*
* The default installation has three files, Recpies.txt for instructions to cook. e.g #Hotdogs 
* There is also  Items.txt which is for data about items that can be purchased e.g. #TinnedSoup 
* There is also Inventory.txt which is meant to allow tracking of where items are stored e.g. #Fridge 
*
*  Version
*/ 


#include <stdio.h>
#include <string.h>


char RecordMarker = '#';
char indexFile[200] = "indexFile";

int parseIndexFile(char *filename, char *text);
int scanFile(char *filename, char *text);

int main (int argc, char **argv){

  
  if (argc > 2) {
    char Buffer[100];
    sprintf(Buffer,"%s ", argv[1]);  /* #Keyword<space> is format for files */
    parseIndexFile(indexFile,Buffer);
  }
  else if (argc == 2){
    parseIndexFile(indexFile,argv[1]); /*#12345 will be printed on keyword 12*/
  }
  else{
    printf(" Usage wft name [x] where name is keyword to lookup. x means exact search \n");


    printf("wft - whats for tea? version 1.0 12thJan2024 \n");
    printf("Copyright(C) 2024 - CommandLineCoder \n\n");

    printf("This program is free software: you can redistribute it and/or modify\n");
    printf("it under the terms of the GNU General Public License as published by\n");
    printf("the Free Software Foundation, either version 3 of the License, or\n");
    printf("(at your option) any later version.\n\n");

    printf("This program is distributed in the hope that it will be useful,\n");
    printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
    printf("GNU General Public License for more details.\n\n");

    printf("You should have received a copy of the GNU General Public License\n");
    printf("along with this program.  If not, see <https://www.gnu.org/licenses/>.\n\n");


  }
}

int parseIndexFile(char *filename, char *text){
  FILE *file = 0;
  char filenameBuffer[1024];
  file = fopen(filename,"r");

  if (file != 0){
    while (!(feof(file))){
      fgets(&filenameBuffer[0],1024,file);
      int filenameLength = strlen(filenameBuffer);
      if (filenameLength > 2) {
        filenameBuffer[filenameLength-1] = 0;
        if (scanFile(filenameBuffer,text) == 0){
          printf("\n could not open file \n %s\n", filenameBuffer);
        }
      }
    }
    fclose(file);
    return 1; /* return success */
  }
  else {
    return 0;
  }
}

int scanFile(char *filename, char *text){
  FILE *file = 0;
  char lineBuffer[1024];
  file= fopen(filename,"r");
  char isPrintingLines = 0;

  if (file != 0){
    while (!feof(file)){
      fgets(&lineBuffer[0],1024,file);
      if (lineBuffer[0] == RecordMarker){
        isPrintingLines = 0;
        if (strncmp(&lineBuffer[1],text,strlen(text)) == 0){
          isPrintingLines = 1;
          printf("%s\n", filename);
        }

      }
      if (isPrintingLines){
        printf("%s",lineBuffer);
      }
    }





   fclose(file);
   return 1; /* return false */
  }
  else {
   return 0; /* return false */
  }


}

