/* Das Beispielprogramm dateiinfo.c ermittelt Informationen ueber die 
   als Argument angegebenen Dateinamen */ 

#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

/* Die Elemente in der Struktur stat haben nachstehende Bedeutung:

Datentyp:     Element:      Bedeutung:

dev_t         st_dev        device 
ino_t         st_ino        inode 
mode_t        st_mode       protection 
nlink_t       st_nlink      number of hard links 
uid_t         st_uid        user ID of owner 
gid_t         st_gid        group ID of owner 
dev_t         st_rdev       device type (if inode device) 
off_t         st_size       total size, in bytes 
unsigned long st_blksize    blocksize for filesystem I/O 
unsigned long st_blocks     number of blocks allocated 
time_t        st_atime      time of last access 
time_t        st_mtime      time of last modification 
time_t        st_ctime      time of last change 

*/

int main(int argc, char** argv) 
{ 
  int i, err; 
  mode_t typ, perm;
  struct stat buf; 
  char* ptr;
  char perms[10];
  
  for (i = 1; i < argc; i++) {   /* Schleife ueber alle Argumente */
    printf("%s: ", argv[i]);     /* Ausgabe des Dateinamens       */

    err = lstat(argv[i], &buf);  /* Ermittlung der Informationen ueber die
                                    Datei argv[i], der Rueckgabewert ist 0 
                                    bei Erfolg, sonst < 0, 
                                    in buf stehen die Informationen */
 
    if (err < 0) {                           /* Abfrage auf Fehler */
      fprintf(stderr, "Fehler in lstat\n");   /* Fehlermeldung ausgeben */
      continue;                         /* weiter mit dem naechsten Argument */
    }

    /* Ermittlung des Dateityps */
    
    typ = buf.st_mode >> 12;             /* die unteren Bits rausschieben, nur 
                                          die oberen 4 Bits werden benoetigt  */
    switch (typ) { 
      case 010: printf("Regulaere Datei,"); break;
      case 004: printf("Verzeichnis, "); break;
      case 002: printf("Zeichen-Geraetedatei, "); break; 
      case 006: printf("Block-Geraetedatei, "); break; 
      case 001: printf("FIFO, "); break; 
      case 012: printf("Symbolischer Link, "); break; 
      case 014: printf("Socket, "); break;
      default:  printf("unbekannter Typ,");
    }

    perms[0] = '-';
    if(buf.st_mode && S_IRUSR) perms [1] = 'r'; else perms [1] = '-';
    if(buf.st_mode && S_IWUSR) perms [2] = 'w'; else perms [2] = '-';
    if(buf.st_mode && S_IXUSR) perms [3] = 'x'; else perms [3] = '-';

    if(buf.st_mode && S_IRGRP) perms [4] = 'r'; else perms [4] = '-';
    if(buf.st_mode && S_IWGRP) perms [5] = 'w'; else perms [5] = '-';
    if(buf.st_mode && S_IXGRP) perms [6] = 'x'; else perms [6] = '-';

    if(buf.st_mode && S_IROTH) perms [7] = 'r'; else perms [7] = '-';
    if(buf.st_mode && S_IWOTH) perms [8] = 'w'; else perms [8] = '-';
    if(buf.st_mode && S_IXOTH) perms [9] = 'x'; else perms [9] = '-';

    printf("Zugriffsrechte: %s\n", perms); /* Rechte als Oktalzahl ausgeben */
  } 
  return 0;
}