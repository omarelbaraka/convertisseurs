#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define TAILLE_MAX 100000

void listerPdf(){
   
	   char * ch;
	   ch = (char *) malloc(TAILLE_MAX * sizeof(char));
	   
	   char * chaine; 
	   chaine = (char *) malloc(TAILLE_MAX * sizeof(char));
	   
	   system("ls listepdf/>tst.txt "); // mettre les non des fichier.pdf dans un fichier "tst.txt"
	   system("rm -fr resultat");  // supprimer le dossier resultat si il existe
	   system("mkdir resultat");  // créer un nouveau dossier resultat
  
        // on ouvre le fichier "tst.txt"
        FILE* fichier = fopen("tst.txt", "r");
        /*
              parcourir le fichier "tst.txt" et à chaque fois on prend le non d'un
              fichier pdf et on le converti à un fichier.txt on gardant leur nom
        */
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) 
        {
            snprintf(ch,TAILLE_MAX,"pdftotext listepdf/%s",chaine);
            system(ch);
        }
 
        fclose(fichier);
    
        system("mv listepdf/*.txt resultat/"); // deplacer les fichier.txt dans le dossier resultat
        system("rm tst.txt"); // supprimer le fichier "tst.txt"
}

void listerPdfWithOptionLayout(){
   
	   char * ch;
	   ch = (char *) malloc(TAILLE_MAX * sizeof(char));
	   
	   char * chaine; 
	   chaine = (char *) malloc(TAILLE_MAX * sizeof(char));
	   
	   system("ls listepdf/>tst.txt "); // mettre les non des fichier.pdf dans un fichier "tst.txt"
	   system("rm -fr resultatLayout");  // supprimer le dossier resultat si il existe
	   system("mkdir resultatLayout");  // créer un nouveau dossier resultat
  
        // on ouvre le fichier "tst.txt"
        FILE* fichier = fopen("tst.txt", "r");
        /*
              parcourir le fichier "tst.txt" et à chaque fois on prend le non d'un
              fichier pdf et on le converti à un fichier.txt on gardant leur nom
        */
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) 
        {
            snprintf(ch,TAILLE_MAX,"pdftotext -layout listepdf/%s",chaine);
            system(ch);
        }
 
        fclose(fichier);
    
        system("mv listepdf/*.txt resultatLayout/"); // deplacer les fichier.txt dans le dossier resultat
        system("rm tst.txt"); // supprimer le fichier "tst.txt"
}




/*
   la fonction trouver titre prend le nom d'un fichier comme argument et renvoi
   leur titre
*/
char * trouver_titre(char *fichier){

	 char * ch;
	 ch = (char *) malloc(TAILLE_MAX * sizeof(char));
	 
	 char * ligne;
	 ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
	 
	
	  char * lien;
	  lien = (char *) malloc(TAILLE_MAX * sizeof(char));
	  strcat(lien, "resultat/");
	  strcat(lien, fichier);
	  
	  FILE * file = fopen(lien, "r");
	
	 int i  =0;
	 char * resultat;
	 resultat = (char*) malloc(TAILLE_MAX);
	 while(fgets(ligne, TAILLE_MAX, file) != NULL){
	     i++; 
	        if(strstr(ligne, ",") || strstr(ligne, "/") || strstr(ligne, "\\") || i==3){
                if(i==1){
                    if(strstr(ligne, "FROM") || strstr(ligne, "from") || strstr(ligne, "From")){
                        fgets(ligne, TAILLE_MAX, file);
                        if(strstr(ligne, "a") || strstr(ligne, "o") || strstr(ligne, "i")){
                            strcat(resultat, ligne);
                             }else{
                                fgets(ligne, TAILLE_MAX, file);
                                strcat(resultat, ligne);
                                 }
                                  break;
                             }
                             strcat(resultat, ligne);
                              break;
                        }
                        break;
                    }
             else {
             char * newLigne;
            newLigne = (char*)malloc(TAILLE_MAX * sizeof(char));
	  	    int taille = strlen(ligne);
             strncpy(newLigne, ligne, taille-1);
              strcat(resultat, newLigne);
              strcat(resultat, " ");
	  	}
	}
	return resultat;
}



char * trouver_abstract(char * fichier){

          char * buffer;
          buffer = (char*)malloc(TAILLE_MAX * sizeof(char));
       
          char * lien;
	  lien = (char *) malloc(TAILLE_MAX * sizeof(char));
	  strcat(lien, "resultat/");
	  strcat(lien, fichier);
      
       FILE * file = fopen(lien, "r");
       char * ligne;
       ligne = (char *) malloc(TAILLE_MAX * sizeof(char));
       
        int condition = 1;
       while(fgets(ligne, TAILLE_MAX, file) != NULL){
            
        char * newLigne;
        newLigne = (char*)malloc(TAILLE_MAX * sizeof(char));
        
         /*  if((strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION") || strstr(ligne, "introduction")||strstr(ligne, "I NTRODUCTION")) && condition==0){
                     char * ch;
                     ch = (char*)malloc(TAILLE_MAX * sizeof(char));
                     
                     char * pars;
                     pars = (char*)malloc(TAILLE_MAX * sizeof(char));
                     
                     snprintf(ch,TAILLE_MAX,"pdftotext -layout listepdf/%s particulier.txt",fichier);
                     system(ch);
                     
                     char * lien2;
	             lien2 = (char *) malloc(TAILLE_MAX * sizeof(char));
		     strcat(lien2, "resultat/particulier.txt");
		     FILE * filep = fopen(lien2, "r");
		     int nbLigneVide = 0;
                     while(fgets(pars, TAILLE_MAX, filep) != NULL){
                              char c;
                              c = pars[0];
                              if(nbLigneVide >= 2){
                                 int b = 1;
                                    while(b == 1){
		                           if((strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION") || strstr(ligne, "introduction")||strstr(ligne, "I NTRODUCTION"))){
		                                    return buffer;
		                           }
		                           else{
						strcat(buffer, ligne);
						strcat(buffer, " ");
		                            }
                                    }   
                              }
                              if(c == '\n') nbLigneVide++;
                              
                              else{
                                 nbLigneVide = 0;
                              }
                     }
           }*/
        
           if((strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION") || strstr(ligne, "introduction")||strstr(ligne, "I NTRODUCTION"))){
                   break;
           }
           
           if(strstr(ligne, "Abstract") || strstr(ligne, "ABSTRACT") || condition ==0 ){
                 condition = 0;
                int taille = strlen(ligne);
                strncpy(newLigne, ligne, taille-1);
                strcat(buffer, newLigne);
                strcat(buffer, " ");
           }
         
       }
            return buffer;
}

char * trouver_auteurs(char * nomFichier){
          char * buffer;
          buffer = (char*)malloc(TAILLE_MAX * sizeof(char));
       
          char * lien;
	  lien = (char *) malloc(TAILLE_MAX * sizeof(char));
	  strcat(lien, "resultatLayout/");
	  strcat(lien, nomFichier);
      
       FILE * file = fopen(lien, "r");
       char * ligne;
       ligne = (char *) malloc(TAILLE_MAX * sizeof(char));
       
        int condition = 1;
        int numLigne = 1;
       while(fgets(ligne, TAILLE_MAX, file) != NULL){
            char * newLigne;
            newLigne = (char*)malloc(TAILLE_MAX * sizeof(char));
            
            char c;
            c = ligne[0];
            
           if((c=='\n' ||  strstr(ligne, "Department") || strstr(ligne, "from") || strstr(ligne, "abstract")) && condition==0){
                   break;
           }
           
           if((strstr(ligne, ",") || strstr(ligne, "\\") || condition==0 || strstr(ligne, "and")) && numLigne >=2 ){
                  condition = 0;
                  // on fait la concatination des lignes et on supprime les retours à la ligne
                  int taille = strlen(ligne);
	          strncpy(newLigne, ligne, taille-1);
                  strcat(buffer, newLigne);
                  strcat(buffer, " ");
                  if( strstr(ligne, "and")) break;
           }
           numLigne++;
         
       }
         //   printf("les auteurs sont : %s \n",buffer);
             return buffer;
}


char* trouver_biblio(char * fichier){
 
 char * lien;
 lien = (char *) malloc(TAILLE_MAX * sizeof(char));
 strcat(lien, "resultat/");
 strcat(lien, fichier);


 FILE * file = fopen(lien, "r");
 char * ligne;
 ligne = (char *) malloc(TAILLE_MAX * sizeof(char));

 char * para;
 para = (char *) malloc(TAILLE_MAX * sizeof(char));
 
 int condition = 0;
 while (fscanf(file, "%[^\n] ", ligne) != EOF){
 // char * ligneOrigine = ligne;
 // char * ligneCopie = retirerEspace(ligne);
 

 
 if(strcmp( ligne,"References")== 0 ||strcmp( ligne,"REFERENCES")== 0 ||strcmp( ligne,"references")== 0 ||strcmp( ligne,"R EFERENCES")== 0 ||condition == 1 ){
 strcat(para,ligne);
 condition=1;
 
 }
 } 
 return para;
}
void execute(int x)
{   
         system("rm -fr resume_fichier");  // supprimer le dossier resume_fichier si il existe
	 system("mkdir resume_fichier");  // créer un nouveau dossier resume_fichier
	 
         char * chaine; 
         chaine = (char *) malloc(TAILLE_MAX * sizeof(char));
   

         listerPdf(); // converti tous les fichier pdf en txt et les mettre dans un dossier "resultat"
         listerPdfWithOptionLayout();
         system("ls resultat/>test.txt ");  // crée un fichier "test.txt" qui contient les non de tous les fichier.txt
         FILE* fichier = fopen("test.txt", "r");
  
        while (fscanf(fichier, "%[^\n] ", chaine) != EOF) // lecture du fichier qui contient les non des fichiers .txt
        {   
              //creer un nouveau fichier
                char * buffer3;
                char * saut;
                buffer3 = (char*)malloc(TAILLE_MAX * sizeof(char));
                saut = (char*)malloc(TAILLE_MAX * sizeof(char));
                if(x==1)
                {
                snprintf(buffer3,TAILLE_MAX,"touch -f %s",chaine);
                system(buffer3);
                
                // enlever l'extension .txt de fichier
                char * nom;
                nom = (char*)malloc(TAILLE_MAX * sizeof(char));
                nom = strdup(chaine);
                nom = strtok(nom,".");
                
                // ajouter le nom original du fichier (.pdf)
                char * buffer2;
                buffer2 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer2,TAILLE_MAX,"echo le nom est : \"%s.pdf\" > %s ",nom,chaine);
                snprintf(saut,TAILLE_MAX,"echo >> %s ",chaine);
                system(buffer2);
                system(saut);
                
                char * titre = trouver_titre(chaine);         // mettre le titre du fichier dans titre
                char * biblio = trouver_biblio(chaine);         // mettre la biblio du fichier dans titre
                char * abstract = trouver_abstract(chaine);  // mettre le resumé du fichier dans abstract
                char * auteurs = trouver_auteurs(chaine);  // mettre les auteur du fichier dans auteurs
                
                // ajouter le titre du fichier
                char * buffer;
                buffer = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer,TAILLE_MAX,"echo le titre est : \"%s\" >> %s",titre,chaine);
                system(buffer);
                system(saut);
                
                // ajouter les auteurs du fichier
                char * buffer8;
                buffer8 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer8,TAILLE_MAX,"echo les auteur sont : \"%s\" >> %s",auteurs,chaine);
                system(buffer8);
                system(saut);
                
                // ajouter l'abstract du fichier
                char * buffer1;
                buffer1 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer1,TAILLE_MAX,"echo  \"%s\" >> %s",abstract,chaine);
                system(buffer1);
                system(saut);
                
                // ajouter la biblio du fichier
                char * buffer11;
                buffer11 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer11,TAILLE_MAX,"echo  \"%s\" >> %s",biblio,chaine);
                system(buffer11);
                system(saut);

                // deplacer les fichier.txt dans le dossier resultat
                char * res;
                res = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(res,TAILLE_MAX,"mv %s resume_fichier",chaine);
                system(res); 



                }else if(x==2)
                {


                 // enlever l'extension .txt de fichier et mettre xml
                chaine = strtok(chaine,".");
                strcat(chaine,".xml");
                snprintf(buffer3,TAILLE_MAX,"touch -f %s",chaine);
                system(buffer3);
                
                // enlever l'extension du fichier
                char * nom;
                nom = (char*)malloc(TAILLE_MAX * sizeof(char));
                nom = strdup(chaine);
                nom = strtok(nom,".");
                char * bufferx;
                bufferx = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(bufferx,TAILLE_MAX,"echo \"<article>\" > %s",chaine);
                system(bufferx);
                
                // ajouter le nom original du fichier (.pdf)
                char * buffer2;
                buffer2 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer2,TAILLE_MAX,"echo \" <preamble> %s.pdf </preamble>\" >> %s",nom,chaine);
                system(buffer2);
                
                chaine = strtok(chaine,".");
                strcat(chaine,".txt");
                char * titre = trouver_titre(chaine);         // mettre le titre du fichier dans titre
                char * biblio = trouver_biblio(chaine);         // mettre la biblio du fichier dans titre
                char * auteurs = trouver_auteurs(chaine);
                char * abstract = trouver_abstract(chaine);  // mettre le resumé du fichier dans abstract
                chaine = strtok(chaine,".");
                strcat(chaine,".xml");
                
                // ajouter le titre du fichier
                char * buffer;
                buffer = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer,TAILLE_MAX,"echo \" <titre> %s </titre>\" >> %s",titre,chaine);
                system(buffer);
                system(saut);
                
                // ajouter les auteurs du fichier
                char * buffer8;
                buffer8 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer8,TAILLE_MAX,"echo \" <auteur> %s </auteur>\" >> %s",auteurs,chaine);
                system(buffer8);
                 system(saut);
                
                // ajouter l'abstract du fichier
                char * buffer1;
                buffer1 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer1,TAILLE_MAX,"echo \" <abstract> %s </abstract>\" >> %s",abstract,chaine);
                system(buffer1);
                 system(saut);
                 
                // ajouter la biblio du fichier
                char * buffer11;
                buffer11 = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(buffer11,TAILLE_MAX,"echo \" <biblio> %s </biblio>\" >> %s",biblio,chaine);
                system(buffer11);
                 system(saut);
                 
                // structurer le fichier xml
                char * bufferxx;
                bufferxx= (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(bufferxx,TAILLE_MAX,"echo \"</article>\" >> %s",chaine);
                system(bufferxx);
                
                // deplacer les fichier dans le dossier resultat
                char * ress;
                ress = (char*)malloc(TAILLE_MAX * sizeof(char));
                snprintf(ress,TAILLE_MAX,"mv %s resume_fichier",chaine);
                system(ress);
                }
        }
                fclose(fichier);  
                system("rm test.txt "); 
                
}

int main()
{
    printf("veillez choisir la sortie de votre fichier tapez :\n-t pour une fichier text ou \n-x pour un fichier xml\n");
    char *x;
    x = (char*)malloc(3 * sizeof(char));
    scanf("%s",x);
    if(strcmp(x,"-t")==0){
        execute(1);
    }else if(strcmp(x,"-x")==0){
        execute(2);
    }else
        printf("non valide");
}
