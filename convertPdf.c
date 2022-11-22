#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define TAILLE_MAX 100000

char * trouver_titre(char *fichier){

	 char * ch;
	 char * ligne;
	 ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
	 ch = (char *) malloc(TAILLE_MAX * sizeof(char));
	
	 //printf("%s",fichier);
	 //snprintf(ch, TAILLE_MAX,"resultat/%s",fichier);
	 char * lien;
	 lien = (char *) malloc(TAILLE_MAX * sizeof(char));
	  strcat(lien, "resultat/");
	  strcat(lien, fichier);
	 // printf("le lien est : %s",lien);
	 FILE * file = fopen(lien, "r");
	 //printf("%s",ch);
	 int i  =0;
	 char * resultat;
	 resultat = (char*) malloc(TAILLE_MAX);
	 while(fgets(ligne, TAILLE_MAX, file) != NULL){
	  //printf("bilal\n");  
	     i++; 
	        if(strstr(ligne, ",") || strstr(ligne, "/") || strstr(ligne, "\\") || i==3){
                       break;
                 }     
	  	else {
	  	    strcat(resultat, ligne);
	  	    strcat(resultat, " ");
	  	}
	}
	return resultat;
}


void listerPdf(){
   FILE* fichier = NULL;
   char * ch;
   ch = (char *) malloc(TAILLE_MAX * sizeof(char));
   char * chaine; // Chaîne vide de taille TAILLE_MAX
   chaine = (char *) malloc(TAILLE_MAX * sizeof(char));
  system("ls listepdf/>tst.txt ");
  system("rm -r resultat");
  system("mkdir resultat");
  

    fichier = fopen("tst.txt", "r");
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            snprintf(ch,TAILLE_MAX,"pdftotext listepdf/%s",chaine);
            system(ch);
        }
 
        fclose(fichier);
    }
    system("mv listepdf/*.txt resultat/");
    system("rm tst.txt");
}

void trouver_abstract(char * fichier){
      
       FILE * file = fopen(fichier, "r");
       char * ligne;
       ligne = (char *) malloc(TAILLE_MAX * sizeof(char));
       char * para;
       para = (char*) malloc(10000000* sizeof(char));
       int condition = 0;
       while(fgets(ligne, TAILLE_MAX, file) != NULL){
          //    char * ligneOrigine = ligne;
           //   char * ligneCopie = retirerEspace(ligne);
            
           if(strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION") || strstr(ligne, "introduction")){
                exit(0);
           }
           
           if(strstr(ligne, "Abstract") || strstr(ligne, "ABSTRACT") ||strstr(ligne, "abstract") ||  condition == 1){
                printf("%s",ligne);
                condition = 1;
           }
         
       }
}

int main()
{   
       char * chaine; // Chaîne vide de taille TAILLE_MAX
       chaine = (char *) malloc(TAILLE_MAX * sizeof(char));
   

       listerPdf();
       system("ls resultat/>test.txt ");
       FILE* fichier = fopen("test.txt", "r");
    
    
  
        while (fscanf(fichier, "%[^\n] ", chaine) != EOF) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
                char * c ;
                c = (char*)malloc(TAILLE_MAX * sizeof(char));
                c = chaine;
                
                
                
                FILE * file = fopen(chaine, "rw");
                char * a = trouver_titre(c);
                printf("%s\n",a);
                
                char * res1 ;
                res1 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(res1,TAILLE_MAX,"echo %s>%s",a,chaine);
                system(res1);
		fclose(file);
		
		
               // trouver_titre(c);
       		
       		//trouver_abstract(ch);
       		

        }
        
        fclose(fichier);
     
}

/*char * retirerEspace(char * chaine){
 
 
  int i;
  int j = -1;
  for (i = 0; chaine[i]; i++)
    if (chaine[i] != ' ')
        chaine[++j] = chaine[i];
        chaine[++j] = '\0';
 
  return chaine
  
}
}*/











