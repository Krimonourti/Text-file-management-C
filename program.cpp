#include<stdio.h>
#include<windows.h>
#include<myconio.h>
#include<conio.h>
 
 //declaration functon prototypes
  void cadre(int, int, int, int);
  void menu(void);
  void Saisir(void);
  void affichage(void);
  void statistique(void);
  void rname(void);
  void delet(void);
  void generate(void);
  
 	 FILE*f;
 	 char oldName[50]= "texte.txt";
 	
	
  
  //deuxiem partie 
  main()
  {
  	//resize the windows width and hight
  	system("MODE 55,22");
  	menu();
  	gotoxy(5,22);
	system("pause");
  }
  
  	//3eme partie
  	
  	//cadre
 	 void cadre(int ch, int lh, int cb, int lb)
  	{
	  	gotoxy(ch, lh);printf("%c",218);
			for(int i=ch+1; i<=cb-1 ; i++) 
			{
				gotoxy(i,lh);printf("%c",196);
			}
		gotoxy(cb,lh);printf("%c",191);
			for(int i=lh+1;i<=lb-1 ; i++)
			{
				gotoxy(ch,i);printf("%c",179);gotoxy(cb,i);printf("%c",179);
			}
		gotoxy(ch,lb);printf("%c",192);
			for(int i=ch+1 ; i<cb+1 ; i++){gotoxy(i,lb);printf("%c",196);}
		gotoxy(cb,lb);printf("%c",217);
	}
	void menu()
	{
		
	    textcolor(4);
		textbackground(WHITE);
		int choix;
		do
		{
			system("cls");
			cadre(5,2,50,4);
			gotoxy(1,3);printf("        MINI APP 3 - GESTION DE FICHIERS TEXTES");
			
			cadre(5,5,50,14);
			gotoxy(6,6);printf(" 1. Creer un fichier texte");
			gotoxy(6,7);printf(" 2. Afficher le contenu");
			gotoxy(6,8);printf(" 3. Statistique du fichier");
			gotoxy(6,9);printf(" 4. Renommer le fichier");
			gotoxy(6,10);printf(" 5. Supprimer le fichier");
			gotoxy(6,11);printf(" 6. Generer les fichiers des tables");
			gotoxy(6,12);printf(" 0. Quitter");
			cadre(5,18,50,20);
			gotoxy(6,19);printf("        Realisee par : Abdelkarim Nourti");
			
			    cadre(5,15,50,17);
				gotoxy(6,16);printf("Entrez votre choix : ");
				scanf("%d",&choix);
				
				if(choix==1) Saisir();
				else if(choix==2) affichage();				 
				else if(choix==3) statistique();
				else if(choix==4) rname();
				else if(choix==5) delet();
				else if(choix==6) generate();
			
				 
			
		}while(choix!=0);
		
		
	}
	void affichage()
	{
			system("cls");
			
			cadre(5,2,50,4);
			gotoxy(1,3);
			printf("           MINI APP 3 > Afichage");
			
			f =fopen(oldName,"r");
			cadre(5,5,50,17);
			gotoxy(6,6);
			char chaine[1000] = ""; // Chaîne vide de taille TAILLE_MAX
 
 
    				if (f != NULL)
   				 {
       				 fgets(chaine,1000, f); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        			  printf("%s", chaine); // On affiche la chaîne
 
        				fclose(f);
    			}
    			else
    			printf("le fichier n'existe pas");
			
			
			cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			getch();
		
	}
	void Saisir(void)
	{
		system("cls");
			char text[100];
			f =fopen(oldName,"w");
			
			
			  	cadre(5,2,50,4);
			gotoxy(1,3);
			printf("           MINI APP 3 > Saisir");
			
			cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			  
			  
			if(f==NULL)
			{
				
				puts("le fichier nexiste pas....");
				getch();
			}
			else
			{
				
		
			
			cadre(5,5,50,17);
			gotoxy(6,6);
			printf("Entrez le text : ");
			fflush(stdin);
			gets(text);
			  if (f != NULL)
    		{
       				 fputs(text, f);
        			
    		}		
			}
		
		
			
			fclose(f);
		
	}
	void statistique()
	{
	
		
				system("cls");
		
		
			cadre(5,2,50,4);
			gotoxy(1,3);
			printf("           MINI APP 3 > Statistique");
			
				cadre(5,5,50,17);
				
					cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			
			f = fopen(oldName,"r");
			
				if(f==NULL)
			{
				
				gotoxy(6,6);	puts("le fichier n'existe pas....");
				gotoxy(6,7);getch();
			}
			else
			{
				
				
			//la taile de fichier
			int taille;
			char carcourant;
			fseek(f,0,SEEK_END); // aler a la fin de fichier
			taille = ftell(f);
		
			// nombre de ligne:
			rewind(f);
			int nbrligne = 0;
			carcourant = fgetc(f);
			while(carcourant!=EOF)
			{
				if(carcourant == '\n') nbrligne++;
				carcourant = fgetc(f);
			}
			
			// nombre de character
			
				// nombre de ligne:
			rewind(f);
			int nbrchar = 0;
			carcourant = fgetc(f);
			while(carcourant!=EOF)
			{
				if(carcourant != '\n' && carcourant !=' ') nbrchar++;
				carcourant = fgetc(f);
			}
			
				
					gotoxy(6,6);
			 printf("Nombre de caracter: %d",nbrchar);
			 	gotoxy(6,8);
			printf("nombre de ligne : %d",nbrligne);
				gotoxy(6,10);
				printf("la taille de fichier est : %d",taille);
				gotoxy(6,11);
				getch();
			fclose(f);
			}
			
		
	}
	void rname()
	{
		system("cls");
		
		
			cadre(5,2,50,4);
			gotoxy(1,3);
			printf("           MINI APP 3 > Renommer");
			
				cadre(5,5,50,17);
				
					cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			
		
			
				if(f==NULL)
			{
				
				gotoxy(6,6);	puts("le fichier n'existe pas....");
				gotoxy(6,7);getch();
			}
			else
			{
						char newName[50];
			
			gotoxy(6,6);
			printf("Saisir un nouveau nom: ");
			fflush(stdin);
			gets(newName);
			
		 if (rename(oldName, newName) == 0)
    	{
    			textcolor(2);
        		gotoxy(6,10); printf("File renamed successfully.\n");
        		textcolor(4);
        		printf("%c",7);
        		oldName[0] = '\0';
        		strcpy(oldName,newName);
        		getch();
    	}
    	else
    	{
       	  gotoxy(6,10);
			printf("Unable to rename files..");
			getch();
    	}
				
			}
		
			fclose(f);
		
		
	}
	  void delet()
	  {
	  	
	  		
	  		system("cls");
		
		
			cadre(5,2,50,4);
			gotoxy(1,3);
			printf("           MINI APP 3 > Supprimer");
			
				cadre(5,5,50,17);
				
					cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			
		
			
				if(f==NULL)
			{
				
				gotoxy(6,6);	puts("le fichier n'existe pas....");
				gotoxy(6,7);getch();
			}
			else
	  		
	  		{
	  			int status;
  			char rep;
 			cadre(5,5,50,17);
			gotoxy(6,6);
  			printf("Vouler-vous suprimmer le fichier ? (O/n) : \n");
  			gotoxy(48,6);scanf(" %c",&rep);
 			if(rep=='o')
 			{
 				status = remove(oldName);
 				if (status == 0)
  				{
			  		textcolor(2);
    				gotoxy(6,8);printf("%s file deleted successfully.\n", oldName);
    				textcolor(4);
    				
    				getch();
    			}
    				else
  			{
    			gotoxy(6,8);printf("Unable to delete the file\n");
    			gotoxy(6,9);perror("error occurred");
    			gotoxy(6,10);getch();
  			}
			 }
			 else
			 printf("file not deleted");
			}
			 
		
 			
 			
  		
  			
  		
 
  		
  		
			 	  
	  }
	  void generate()
	  {
	  	system("cls");
	  	int nbr;
	  	
	  		cadre(5,2,50,4);
			gotoxy(1,3);
			printf("     MINI APP 3 > Generer les fichiers des tables");
			
			
				cadre(5,18,50,20);
			gotoxy(6,19);
			printf("	  Message : Appuyer sur 'Entrer' SVP!");
			
			cadre(5,5,50,17);
			gotoxy(6,6);	
	  	puts("enter  un nombre : ");
	  		gotoxy(25,6);scanf("%d",&nbr);
	  		
	  		
	  	
			
	  	
	  	FILE*files[nbr];
	  	char filename[20];
		
	  	for(int i = 1; i<=nbr;i++)
	  	{
	  	
    		sprintf(filename, "table%d.txt", i);
    		files[i] = fopen(filename, "w");
    		
    		for(int j = 1;j<=10;j++)
    		{
    			fprintf(files[i],"%d * %d = %d \n",i,j,i*j);
			}
    			fclose(files[i]);
		}
		
			textcolor(2);
        		gotoxy(6,10); printf("Table Created successfully.\n");
        		textcolor(4);
		gotoxy(26,6);getch();
	  }


	
	

