#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NB_BATEAU 4
#define ID_CORVETTE 1
#define ID_DESTROYER 2
#define ID_CROISEUR 3
#define ID_PORTEAVION 4
#define MAP_ITEMS 6
#define MAP_H 9
#define MAP_W 12



int main()
{
    system("cls");
    Title();

    int mdj = 0;

    Color(0, 15);
    printf("Choisissez le mode de jeu : \n");
    Color(15, 0);
    printf("1-IA vs IA \n2-Joueur vs IA \n3-Joueur vs Joueur \n4-Charger une partie \n5-Comment jouer ? \nAutre-Exit\n");
    scanf("%d", &mdj);

    switch(mdj)
    {
    case 1:
        IA_IA();
        break;
    case 2:
        Joueur_IA();
        break;
    case 3:
        Joueur_Joueur();
        break;
    case 4:
        Load(); // WORK IN PROGRESS
    case 5:
        HTP();
        break;
    default:
        return;
        break;
    }



}


static FILE  *save;
static char name[256];

void Save(int mode, int msg, int tour, int compteur1, int compteur2, int map_j1[MAP_H][MAP_W], int map_j2[MAP_H][MAP_W], int tab_j1[MAP_H][MAP_W], int tab_j2[MAP_H][MAP_W]) // parametre pour savoir si on affiche un message a l'ecran ou non.
{

    if(msg == 0)
    {
        printf("Le jeu sauvegarde automatiquement la partie. \nChoisissez le nom de votre partie : \n");
        scanf("%s", name);
    }

    save = fopen(name, "w+");
    fprintf(save, "%d%d%d%d", mode, tour, compteur1, compteur2);

    int i, j;

    for(i = 0;i<MAP_H;i++)
    {
        for(j = 0;j<MAP_W;j++)
        {
            fprintf(save, "%d", map_j1[i][j]);
        }
    }
    for(i = 0;i<MAP_H;i++)
    {
        for(j = 0;j<MAP_W;j++)
        {
            fprintf(save, "%d", map_j2[i][j]);
        }
    }
    for(i = 0;i<MAP_H;i++)
    {
        for(j = 0;j<MAP_W;j++)
        {
            fprintf(save, "%d", tab_j1[i][j]);
        }
    }
    for(i = 0;i<MAP_H;i++)
    {
        for(j = 0;j<MAP_W;j++)
        {
            fprintf(save, "%d", tab_j2[i][j]);
        }
    }


    fclose(save);
}



void Load()
{
    printf("Saisissez le nom de la sauvegarde a charger : \n");
    scanf("%s", name);

    char mode;

    mode = fgetc(save);
    printf("%c", mode);

    if(mode == '0')
    {
        printf("test");
    }

}




void Title() // FONCTION POUR AFFICHER LE GROS TITRE EN ROUGE A L'ECRAN
{
    char string[] = "111110011111001111100111110010000001111100111110010001001001111121000100100010000100000010000100000010000001000000100010010010001211111001111100001000000100001000000111100010000001000100100111112100010010001000010000001000010000001000000111110011111001001210001001000100001000000100001000000100000000001001000100100121111100100010000100000010000111110011111001111100100010010012";
    //char string2[] = "0000000000000,,.=czzttzzz==+..,,200000000,,sS5t:::::::::::::::::ttZt>.200000,aEEtt::::::::::::::::::::::::::t3>.2000,#5ttttz::;;;;;;;;;;;;;;;;;:::::::::::t3>.200/Etttt35SEEEERQE5F***I1::::0::::::::::::t3x.20/E3333EEtt3E7XE5P`000000;E::::..00000:::::::::::t3s,2JE53EEEEEEtz3k..00000000;5zzzz::::..000000:::::::::::!3x,2|E3EEEEEEEEEzzZ5sc..;;z5ttttttttzzz:::..000000:::::::::::7t.,2|E3EEEEEEEEEEEEEzzzzzztttttt3333ttttzzz:::..000000::::::::::/2{EEEEEEEEEEEEEEEEEEEEEEEEttttt333333ttttzzz:::..000000:::::ySx.wgEh.,20EEEEEEEEEEEEEEEEEEEEEEEEEEEEttt33333333ttttzzz:::..00000:Ztztt35::::3e.,20IEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEtt3Ftt55E33tttzzzz:::..:Ettztzt::::::::zF200EEEEEEEEEEEEEEEEEEZl.00`'00QEE55z:;z;;::Xt333tttzzz::t::ZtZF0000::::;F200QEEEEEEEEEEEEEEES5::.0000000}QZE5EL00`%.0I3333333ttt1zztzZ...000000;F20000VEEEE535EEEEEE1::::.0000000fUEE[[.000JL:Jttt333333ttttttzz:::..00;F:.200000EEEE33333EESF:::::..000000000000000]tgEEEEEttt3tt333tttttzzz::y.00:..20000000\EEEE333331:::::::::........0000.y5EEEEEEEEEEEtS53333333tttt/000000:..200000000QEEEEttttZ5sz::::::;izzzzzzz3@EEEEEEEEEE5SEES55Ettt333333Z00000000::..200000000004EEEEtttttt3ZEEEEEEEEEEEEEEEEEEEEEEEE5EEEZE3EEEEEtttttZ0::..0000::::.2000000000000`*EEEEEEtttttt33335EEEEEEEEEEEEEEEE5EEEEESEEEEEEEEEEF000::::::::::::.2000000000000000`*4EEEEEEtttttt33335EEEEEEEEEEESEEEEEZEEEEEEEEE5F:::::::::::::::::.20000000000000000000`*EEEEEEEttttt333335EEEEEESEE5EEZEEEEEEEEE5L0::::00::::::::::::.200000000000000000000000`*GEEEEEEttttt333335EZEEEEEZEEEEEEEEE5F0:::::::.::::::::::::.2000000000000000000000000000`*EEEEEE3ttttt33EE33E5EEEEEEEEEES0000::::::::::::::::::::20000000000000000000000000000000*QEEEEE3t3EEESE5E35EEEEEEEZ0000000::::::::::::::::::..200000000000000000000000000000000000*EEE5F4EEE3Et33335EEEZ.00000000:::::::::::::::::;z.....2000000000000000000000000000000000000000`000EEEtttttt33QE.::::.0000::::::::::;:::::::::::::!.200000000000000000000000000000000000000000000JEEEEEE3ttQF00'::::...00000::::::c=!::::00:=zzc:::2000000000000000000000000000000000000000000000004EEEE3F00000000:=::!::::::::::..0':...0000000::200000000000000000000000000000000000000000000000000`V`000000000000000000000000:!tt:=.::.0000:Sz.20000000000000000000000000000000000000000000000000000000000000000000000000000000000000:::000000====2";
    //char string3[] = "           ,ww.         2          [1.}3         2           \EF          2        ***$EF***       2           {E[          2           {E[          2           |E[          2   JEk,    |E[    ,yEL  2    \EEF    {E[   }EE7   2       \Ew.,AE5..aEF     2        `*GEEEDP`       2";
    int i;


for(i = 0;i<378;i++)
    {
        if(string[i] == '0')
        {
            Color(0, 0);
            printf("%c", string[i]);
        }else if(string[i] == '2'){
            f();
        }else{
            Color(12, 12);
            printf("%c", string[i]);
        }
    }

    f();



    Color(15,0);
}


void HTP() //fonction tutoriel
{
    system("cls");
    printf("Il y a 3 modes de jeu : IA versus IA, IA versus JOUEUR, et JOUEUR versus JOUEUR \n");
    printf("Appuyez sur Entree pour continuer...\n");
    fflush(stdin);
    getchar();
    printf("Dans chaque mode de jeu, chaque joueur a 2 cartes : \nL'une affichant ses bateaux, et l'autre les tirs qu'il a effectue. \n");
    printf("Dans chaque tableau, les differents elements sont representes par des couleurs et des lettres : \n");
    printf("Appuyez sur Entree pour continuer...\n");
    getchar();
    //*************************
    Color(11, 11);
    printf("   ");
    Color(15, 0);
    printf(" pour l'eau \n");
    //*************************
    Color(0, 10);
    printf(" 1 ");
    Color(15, 0);
    printf(" pour le corvette \n");
    //*************************
    Color(0, 13);
    printf(" 2 ");
    Color(15, 0);
    printf(" pour le destroyer \n");
    //*************************
    Color(0, 14);
    printf(" 3 ");
    Color(15, 0);
    printf(" pour le croiseur \n");
    //*************************
    Color(0, 8);
    printf(" 4 ");
    Color(15, 0);
    printf(" pour le porte-avion \n");
    //*************************
    Color(0, 15);
    printf(" 9 ");
    Color(15, 0);
    printf(" pour un tir dans l'eau \n");
    //*************************
    Color(0, 4);
    printf(" 5 ");
    Color(15, 0);
    printf(" pour un tir reussi \n");
    //*************************
    printf("Appuyez sur Entree pour continuer...\n");
    getchar();

    printf("Pour gagner, un joueur doit couler tous les bateaux\n de l'adversaire.\n");
    f();f();
    printf("Appuyez sur Entree pour revenir au menu\n");
    getchar();
    main();
}





void Joueur_Joueur()
{

    int map_j1[MAP_H][MAP_W] = {0}; //CHAQUE JOUEUR A 2 TABLEAUX : 1 POUR SES BATEAUX, ET L'AUTRE POUR LES TIRS EFFECTUES
    int map_j2[MAP_H][MAP_W] = {0};
    int tab_j1[MAP_H][MAP_W] = {0};
    int tab_j2[MAP_H][MAP_W] = {0};

    //Save(0, 0, 21, 21, map_j1, map_j2, tab_j1, tab_j2);

    int size[6] = {1,3,3,4,4,6};

    int x;int y;int h = 0;
    int i = 0;int j = 0;int tour = 0;

    printf("Vous avez choisi le mode Joueur VS Joueur \nAppuyez sur Entree");
    fflush(stdin);
    getchar();

    system("cls");
    int placementAuto = 0;

    if(tour == 0)
    {
        printf("JOUEUR 1 \nVoulez-vous placer vos bateaux aleatoirement ? \n0 : OUI \n1 : NON \n");
        scanf("%d", &placementAuto);

        if(placementAuto == 1)
        {

            printf("Joueur 1 : Place tes bateaux, moussaillon ! \n");
            PrintMap(map_j1, "");

            while(i < 6)
            {
                printf("Placement du bateau numero %d. Taille : %d case(s)\n", i+1, size[i]);

                x=50000000;y=50000000000;h=0;//POUR ETRE SUR DE RENTRER DANS LA BOUCLE WHILE
                int correct=0;


                while((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1)
                {
                    correct = 0;
                    printf("Saisissez une coordonnee X entre 0 et %d \nX : ", MAP_W-1);
                    scanf("%d", &x);
                    printf("Saisissez une coordonnee Y entre 0 et %d \nY : ", MAP_H-1);
                    scanf("%d", &y);

                    if(size[i] > 1)
                    {
                        printf("Saisissez l'orientation du bateau : 0 pour vertical et 1 pour horizontal \n");
                        scanf("%d", &h);
                    }


                    int k = 0;
                    for(j=0;j<size[i];j++)
                    {
                        while(correct == 0 && k<size[j])
                        {
                            if(h == 0)
                            {
                                if(map_j1[y][x+j-1] != 0)
                                {
                                    correct = 1;
                                }else{
                                    correct = 0;
                                }
                            }else{
                                if(map_j1[y+j-1][x] != 0)
                                {
                                    correct = 1;
                                }else{
                                    correct = 0;
                                }
                            }
                            k++;
                        }
                    }

                    if((x+size[i]+1 > MAP_W && h == 0) || (y+size[i]+1 > MAP_H && h != 0) || correct == 1)
                    {

                        printf("Coordonnees incorrects, reeessayez \n");
                    }

                }




                    if(h!=0)
                    {
                        switch(i)
                        {
                        case 0:
                            map_j1[y][x] = 1;
                            break;
                        case 1:
                            for(j=0;j<3;j++)
                            {
                                map_j1[y+j][x] = 2;
                            }
                            break;
                        case 2:
                            for(j=0;j<3;j++)
                            {
                                map_j1[y+j][x] = 2;
                            }
                            break;
                        case 3:
                            for(j=0;j<4;j++)
                            {
                                map_j1[y+j][x] = 3;
                            }
                            break;
                        case 4:
                            for(j=0;j<4;j++)
                            {
                                map_j1[y+j][x] = 3;
                            }
                            break;
                        case 5:
                            for(j=0;j<6;j++)
                            {
                                map_j1[y+j][x] = 4;
                            }
                            break;
                        }
                    }else{
                        switch(i)
                        {
                        case 0:
                            map_j1[y][x] = 1;
                            break;
                        case 1:
                            for(j=0;j<3;j++)
                            {
                                map_j1[y][x+j] = 2;
                            }
                            break;
                        case 2:
                            for(j=0;j<3;j++)
                            {
                                map_j1[y][x+j] = 2;
                            }
                            break;
                        case 3:
                            for(j=0;j<4;j++)
                            {
                                map_j1[y][x+j] = 3;
                            }
                            break;
                        case 4:
                            for(j=0;j<4;j++)
                            {
                                map_j1[y][x+j] = 3;
                            }
                            break;
                        case 5:
                            for(j=0;j<6;j++)
                            {
                                map_j1[y][x+j] = 4;
                            }
                            break;
                        }
                    }
                i++;
                PrintMap(map_j1, "");
            }

        }

        if(placementAuto == 0)
        {
            PlacementCorvette(map_j1);
            PlacementCroiseur(map_j1);
            PlacementCroiseur(map_j1);
            PlacementDestroyer(map_j1);
            PlacementDestroyer(map_j1);
            PlacementPorteAvion(map_j1);
            PrintMap(map_j1, "");
            printf("Appuyez sur Entree \n");
            fflush(stdin);
            getchar();
        }

        tour = 1;
    }


    i=0;j=0;


    if(tour != 0)
    {
        system("cls");

        printf("JOUEUR 2 \nVoulez-vous placer vos bateaux aleatoirement ? \n0 : OUI \n1 : NON \n");
        scanf("%d", &placementAuto);

        if(placementAuto == 1)
        {

            system("cls");
            printf("Joueur 2 : Place tes bateaux, moussaillon ! \n");
            PrintMap(map_j2, "");

            while(i < 6)
            {

                printf("Placement du bateau numero %d. Taille : %d case(s)\n", i+1, size[i]);

                x=50000000;y=50000000000;h=0;
                int correct=0;


                while((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1)
                {
                    correct = 0;
                    printf("Saisissez une coordonnee X entre 0 et %d \nX : ", MAP_W-1);
                    scanf("%d", &x);
                    printf("Saisissez une coordonnee Y entre 0 et %d \nY : ", MAP_H-1);
                    scanf("%d", &y);

                    if(size[i] > 1)
                    {
                        printf("Saisissez l'orientation du bateau : 0 pour horizontal et 1 pour vertical \n");
                        scanf("%d", &h);
                    }

                    int k = 0;
                    for(j=0;j<size[j];j++)
                    {
                        while(correct == 0 && k<size[j])
                        {
                            if(h == 0)
                            {
                                if(map_j2[y][x+j] != 0)
                                {
                                    correct = 1;
                                }else{
                                    correct = 0;
                                }
                            }else{
                                if(map_j2[y+j][x] != 0)
                                {
                                    correct = 1;
                                }else{
                                    correct = 0;
                                }
                            }
                            k++;
                        }
                    }

                    if((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1)
                    {

                        printf("Coordonnees incorrects, reeessayez \n");
                    }

                }




                    if(h!=0)
                    {
                        switch(i)
                        {
                        case 0:
                            map_j2[y][x] = 1;
                            break;
                        case 1:
                            for(j=0;j<3;j++)
                            {
                                map_j2[y+j][x] = 2;
                            }
                            break;
                        case 2:
                            for(j=0;j<3;j++)
                            {
                                map_j2[y+j][x] = 2;
                            }
                            break;
                        case 3:
                            for(j=0;j<4;j++)
                            {
                                map_j2[y+j][x] = 3;
                            }
                            break;
                        case 4:
                            for(j=0;j<4;j++)
                            {
                                map_j2[y+j][x] = 3;
                            }
                            break;
                        case 5:
                            for(j=0;j<6;j++)
                            {
                                map_j2[y+j][x] = 4;
                            }
                            break;
                        }
                    }else{
                        switch(i)
                        {
                        case 0:
                            map_j2[y][x] = 1;
                            break;
                        case 1:
                            for(j=0;j<3;j++)
                            {
                                map_j2[y][x+j] = 2;
                            }
                            break;
                        case 2:
                            for(j=0;j<3;j++)
                            {
                                map_j2[y][x+j] = 2;
                            }
                            break;
                        case 3:
                            for(j=0;j<4;j++)
                            {
                                map_j2[y][x+j] = 3;
                            }
                            break;
                        case 4:
                            for(j=0;j<4;j++)
                            {
                                map_j2[y][x+j] = 3;
                            }
                            break;
                        case 5:
                            for(j=0;j<6;j++)
                            {
                                map_j2[y][x+j] = 4;
                            }
                            break;
                        }
                    }
                i++;
                PrintMap(map_j2, "");
            }

        }

        if(placementAuto == 0)
        {
            PlacementCorvette(map_j2);
            PlacementCroiseur(map_j2);
            PlacementCroiseur(map_j2);
            PlacementDestroyer(map_j2);
            PlacementDestroyer(map_j2);
            PlacementPorteAvion(map_j2);
            PrintMap(map_j2, "");
            printf("Appuyez sur Entree \n");
            fflush(stdin);
            getchar();
        }
    }


    f();f();

    //***********************************************************************************

    printf("Debut du jeu ! Appuyez sur Entree \n");
    fflush(stdin);
    getchar();
    system("cls");

    tour = 0;
    int compteur1 = 21;int compteur2 = 21;
    x=0;y=0;

    Save(3, 0, tour, compteur1, compteur2, map_j1, map_j2, tab_j1, tab_j2);


    while(compteur1 > 0 && compteur2 > 0)
    {
        if(tour == 0)
        {
            Save(3, 1, tour, compteur1, compteur2, map_j1, map_j2, tab_j1, tab_j2);

            printf("C'EST LE TOUR DU JOUEUR 1 ! \n");
            PrintMap(tab_j1, "Vos tirs effectues");
            f();
            PrintMap(map_j1, "Vos bateaux");
            f();
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);

            while((tab_j1[y][x] != 0) || (x>MAP_W || y>MAP_H) || (x<0 || y<0))
            {
                printf("Vous avez rentre des coordonnees incorrects ou des coordonnees que vous avez deja rentree \n");
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);
            }


            if(map_j2[y][x] != 0)
            {
                printf("TOUCHE EN %d:%d!!\n", x, y);
                compteur2--;
                map_j2[y][x] = 5;
                tab_j1[y][x] = 5;
            }else{
                printf("PLOUF EN %d:%d....\n", x, y);
                map_j2[y][x] = 9;
                tab_j1[y][x] = 9;
            }

            printf("Appuyez sur Entree pour passer au tour du Joueur 2\n");
            fflush(stdin);
            getchar();
            system("cls");
            tour=1;
        }


        if(tour != 0)
        {
            Save(3, 1, tour, compteur1, compteur2, map_j1, map_j2, tab_j1, tab_j2);

            printf("C'EST LE TOUR DU JOUEUR 2 ! \n");
            PrintMap(tab_j2, "Vos tirs effectues");
            f();
            PrintMap(map_j2, "Vos bateaux");
            f();
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);

            while((tab_j2[y][x] != 0) || (x>MAP_W || y>MAP_H) || (x<0 || y<0))
            {
                printf("Vous avez rentre des coordonnees incorrects ou des coordonnees que vous avez deja rentree \n");
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);
            }


            if(map_j1[y][x] != 0)
            {
                printf("TOUCHE EN %d:%d!!\n", x, y);
                compteur1--;
                map_j1[y][x] = 5;
                tab_j2[y][x] = 5;
            }else{
                printf("PLOUF EN %d:%d....\n", x, y);
                map_j1[y][x] = 9;
                tab_j2[y][x] = 9;
            }

            printf("Appuyez sur Entree pour passer au Joueur 1\n");
            fflush(stdin);
            getchar();
            system("cls");
            tour = 0;
        }
    }

    if(compteur1 <= 0)
    {
        Color(0, 4);
        printf("\n LE JOUEUR 2 A GAGNEEEEEE !!!\n");
        Color(15, 0);
    }

    if(compteur2 <= 0)
    {
        Color(15, 0);
        printf("\n LE JOUEUR 1 A GAGNEEEEEE !!!\n");
        Color(15, 0);
    }

    printf("\nAppuyez sur Entree pour retourner au menu \n");
    getchar();
    main();

}


void Joueur_IA()
{
    int map_j[MAP_H][MAP_W] = {0};
    int map_ia[MAP_H][MAP_W] = {0};

    int tab_j[MAP_H][MAP_W] = {0};
    int tab_ia[MAP_H][MAP_W] = {0};

    int size[6] = {1,3,3,4,4,6};

    int x;int y;int h = 0;

    int i = 0;
    int j = 0;


    printf("Vous avez choisi le mode Joueur VS IA \nAppuyez sur Entree");
    fflush(stdin);
    getchar();

    system("cls");

    int placementAuto;
    printf("JOUEUR 1 \nVoulez-vous placer vos bateaux aleatoirement ? \n0 : OUI \n1 : NON \n");
    scanf("%d", &placementAuto);

    if(placementAuto == 0)
    {
        PlacementCorvette(map_j);
        PlacementCroiseur(map_j);
        PlacementCroiseur(map_j);
        PlacementDestroyer(map_j);
        PlacementDestroyer(map_j);
        PlacementPorteAvion(map_j);
    }

    if(placementAuto == 1)
    {
        system("cls");
    printf("Place tes bateaux moussaillon !");
    PrintMap(map_j, "");

    while(i < 6)
    {
        printf("Placement bateau numero %d. Taille : %d case(s)\n", i+1, size[i]);

        x=50000000;y=50000000000;h=0;
        int correct=0;


        while((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1 || (h<0 || h>1))
        {
            correct = 0;
            printf("Saisissez une coordonnee X entre 0 et %d \nX : ", MAP_W-1);
            scanf("%d", &x);
            printf("Saisissez une coordonnee Y entre 0 et %d \nY : ", MAP_H-1);
            scanf("%d", &y);

            if(size[i] > 1) //PAS BESOIN D'ORIENTATION POUR UN BATEAU D'UNE CASE
            {
                printf("Saisissez l'orientation du bateau : 0 pour horizontal et 1 pour vertical \n");
                scanf("%d", &h);
            }

            int k = 0;
            for(j=0;j<size[i];j++)
            {
                while(correct == 0 && k<size[j])
                {
                    if(h == 0)
                    {
                        if(map_j[y][x+j] != 0)
                        {
                            correct = 1;
                        }else{
                            correct = 0;
                        }
                    }else{
                        if(map_j[y+j][x] != 0)
                        {
                            correct = 1;
                        }else{
                            correct = 0;
                        }
                    }
                    k++;
                }
            }

            if((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1 || (h<0 || h>1))
            {

                printf("Coordonnees incorrects, reeessayez \n");
            }

        }




            if(h!=0)
            {
                switch(i)
                {
                case 0:
                    map_j[y][x] = 1;
                    break;
                case 1:
                    for(j=0;j<3;j++)
                    {
                        map_j[y+j][x] = 2;
                    }
                    break;
                case 2:
                    for(j=0;j<3;j++)
                    {
                        map_j[y+j][x] = 2;
                    }
                    break;
                case 3:
                    for(j=0;j<4;j++)
                    {
                        map_j[y+j][x] = 3;
                    }
                    break;
                case 4:
                    for(j=0;j<4;j++)
                    {
                        map_j[y+j][x] = 3;
                    }
                    break;
                case 5:
                    for(j=0;j<6;j++)
                    {
                        map_j[y+j][x] = 4;
                    }
                    break;
                }
            }else{
                switch(i)
                {
                case 0:
                    map_j[y][x] = 1;
                    break;
                case 1:
                    for(j=0;j<3;j++)
                    {
                        map_j[y][x+j] = 2;
                    }
                    break;
                case 2:
                    for(j=0;j<3;j++)
                    {
                        map_j[y][x+j] = 2;
                    }
                    break;
                case 3:
                    for(j=0;j<4;j++)
                    {
                        map_j[y][x+j] = 3;
                    }
                    break;
                case 4:
                    for(j=0;j<4;j++)
                    {
                        map_j[y][x+j] = 3;
                    }
                    break;
                case 5:
                    for(j=0;j<6;j++)
                    {
                        map_j[y][x+j] = 4;
                    }
                    break;
                }
            }
            i++;
            PrintMap(map_j, "");
        }
    }




    f();f();
    PlacementPorteAvion(map_ia);
    PlacementCroiseur(map_ia);
    PlacementCroiseur(map_ia);
    PlacementDestroyer(map_ia);
    PlacementDestroyer(map_ia);
    PlacementCorvette(map_ia);

    printf("Debut du jeu ! Appuyez sur Entree \n");
    fflush(stdin);
    getchar();

    //**************************************************

    int tourJ = 0;
    int compteurJ = 21;int compteurIA = 21;
    x=0;y=0;

    while(compteurJ > 0 && compteurIA > 0)
    {
        Save(2, 1, tourJ, compteurJ, compteurIA, map_j, map_ia, tab_j, tab_ia);

        if(tourJ == 0)
        {
            PrintMap(tab_j, "Vos tirs effectues");
            f();
            PrintMap(map_j, "Vos bateaux");
            f();
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);

            while((tab_j[y][x] != 0) || (x>MAP_W || y>MAP_H) || (x<0 || y<0))
            {
                printf("Vous avez rentre des coordonnees incorrects ou des coordonnees que vous avez deja rentree \n");
                printf("Entrez une coordonnee cible : \nX : ");
                scanf("%d", &x);
                printf("Y : ");
                scanf("%d", &y);
            }


            if(map_ia[y][x] != 0)
            {
                printf("TOUCHE EN %d:%d!!\n", x, y);
                compteurIA--;
                map_ia[y][x] = 5;
                tab_j[y][x] = 5;
            }else{
                printf("PLOUF EN %d:%d....\n", x, y);
                map_ia[y][x] = 9;
                tab_j[y][x] = 9;
            }

            printf("Appuyez sur Entree \n");
            fflush(stdin);
            getchar();

            tourJ = 1;

        }else{

            Save(2, 1, tourJ, compteurJ, compteurIA, map_j, map_ia, tab_j, tab_ia);

            x = doRand(0, MAP_W+1);
            y = doRand(0, MAP_H+1);

            while(tab_ia[y][x] != 0)
            {
                x = doRand(0, MAP_W+1);
                y = doRand(0, MAP_H+1);
            }

            if(map_j[y][x] != 0)
            {
                printf("L'IA VOUS A TOUCHE EN %d:%d !!\n", x, y);
                map_j[y][x] = 5;
                compteurJ--;
            }else{
                printf("L'IA A FAIT PLOUF EN %d:%d...\n", x, y);
                map_j[y][x] = 9;
            }

            printf("Appuyez sur Entree \n");
            fflush(stdin);
            getchar();

            tourJ=0;
            tab_ia[y][x] = 1;
            f();
        }
    }



    if(compteurIA <= 0)
    {
        printf("\n VOUS AVEZ GAGNEEEEEE CONTRE L'IA!!!\n");
    }

    if(compteurJ <= 0)
    {
        printf("\n L'IA A GAGNEEEEEE !!! VOUS AVEZ PERDU...\n");
    }

    printf("\nAppuyez sur Entree pour retourner sur le menu \n");
    getchar();
    main();

}


void IA_IA()
{
    printf("Vous avez choisi le mode IA vs IA. \nAppuyez sur Entree\n");
    system("cls");

    int map_IA1[MAP_H][MAP_W] = {0};
    int map_IA2[MAP_H][MAP_W] = {0};
    int tour = 0;
    int tab1[MAP_H][MAP_W] = {0};
    int tab2[MAP_H][MAP_W] = {0};
    int x = doRand(0, MAP_W+1);
    int y = doRand(0, MAP_H+1);

    int compteur1 = 21;
    int compteur2 = 21;


    PlacementPorteAvion(map_IA1);
    PlacementCroiseur(map_IA1);
    PlacementCroiseur(map_IA1);
    PlacementDestroyer(map_IA1);
    PlacementDestroyer(map_IA1);
    PlacementCorvette(map_IA1);

    PlacementPorteAvion(map_IA2);
    PlacementCroiseur(map_IA2);
    PlacementCroiseur(map_IA2);
    PlacementDestroyer(map_IA2);
    PlacementDestroyer(map_IA2);
    PlacementCorvette(map_IA2);

    Save(1, 0, tour, compteur1, compteur2, map_IA1, map_IA2, tab1, tab2);

    fflush(stdin);
    getchar();
    system("cls");

    PrintMap(map_IA1, "IA 1");
    f();
    PrintMap(map_IA2, "IA 2");

    printf("Les bateaux ont ete places. \nAppuyez sur Entree pour commencer le jeu\n");
    fflush(stdin);
    getchar();


    while(compteur1 > 0 && compteur2 > 0)
    {
        Save(1, 1, tour, compteur1, compteur2, map_IA1, map_IA2, tab1, tab2);

        if(tour == 0)
        {
            while(tab1[y][x] != 0)
            {
                x = doRand(0, MAP_W+1);
                y = doRand(0, MAP_H+1);
            }

            if(map_IA2[y][x] != 0)
            {
                Color(0, 4);
                printf("IA 1 A TOUCHE IA 2 EN %d:%d\n", x, y);
                Color(15, 0);
                map_IA2[y][x] = 5;
                compteur2--;
            }else{
                Color(0, 15);
                printf("IA 1 A FAIT PLOUF EN %d:%d... \n", x, y);
                Color(15, 0);
                map_IA2[y][x] = 9;
            }

            tab1[y][x] = 1;

            tour = 1;


        }else{

            Save(1, 1, tour, compteur1, compteur2, map_IA1, map_IA2, tab1, tab2);

            while(tab2[y][x] != 0)
            {
                x = doRand(0, MAP_W+1);
                y = doRand(0, MAP_H+1);
            }

            if(map_IA1[y][x] != 0)
            {
                Color(0, 4);
                printf("IA 2 A TOUCHE IA 1 EN %d:%d\n", x, y);
                Color(15, 0);
                map_IA1[y][x] = 5;
                compteur1--;
            }else{
                Color(0, 15);
                printf("IA 2 A FAIT PLOUF EN %d:%d... \n", x, y);
                Color(15, 0);
                map_IA1[y][x] = 9;
            }

            tab1[y][x] = 1;
            tour = 0;

        }

    }


    Color(0, 10);
    printf("\a");
    if(compteur1 <= 0)
    {
        printf("IA 2 A GAGNEEEEEEE !!!\n");
    }else if(compteur2 == 0){
        printf("IA 1 A GAGNEEEEEEE !!!\n");
    }
    Color(15, 0);

    f();f();
    PrintMap(map_IA1, "IA 1");
    PrintMap(map_IA2, "IA 2");

    printf("\nAppuyez sur Entree pour retourner sur le menu \n");
    getchar();
    main();

}


void PrintMap(int map[MAP_H][MAP_W], char string[26])
{
    int i;
    int j;

    printf("%s\n", string);
    Color(12, 15);
    printf(" Y/X ");
    Color(0, 15);

    for(i=0;i<MAP_W;i++)
    {        if(i<10)
        {
            printf("%d  ", i);
        }else{
            printf("%d ", i);
        }
    }


    f();

    for(i=0;i<MAP_H;i++)
    {
        if(i<10)
        {
            printf(" %d   ", i);
        }else{
            printf(" %d  ", i);
        }

        for(j=0;j<MAP_W;j++)
        {
            switch((int)map[i][j])
            {
            case 0:
                Color(11, 11);
                break;
            case 1:
                Color(0, 10);
                break;
            case 2:
                Color(0, 13);
                break;
            case 3:
                Color(0, 14);
                break;
            case 4:
                Color(0, 8);
                break;
            case 9:
                Color(15, 15);
                break;
            default:
                Color(0, 4);
                break;
            }

            printf("%d  ", map[i][j]);
        }
        f();
        Color(0, 15);
    }
    Color(15, 0);

}


void PlacementCorvette(int map[MAP_H][MAP_W])
{
    int x = doRand(0, MAP_W-1);
    int y = doRand(0, MAP_H-1);

    while(map[y][x] != 0)
    {
        x = doRand(0, MAP_W-1);
        y = doRand(0, MAP_H-1);
    }

    map[y][x] = ID_CORVETTE;
}

void PlacementDestroyer(int map[MAP_H][MAP_W])
{
    int taille = 3;
    int x = doRand(0, MAP_W-1);
    int y = doRand(0, MAP_H-1);
    int h = doRand(0, 1);
    int i;


for(i=0;i<taille;i++)
{
    if(h==0)
    {
        while((map[y][x+i] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }else{
        while((map[y+i][x] != 0) || (y+taille > MAP_H))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }
}


    for(i=0;i<taille;i++)
    {
        if(h==0)
        {
            map[y][x] = ID_DESTROYER;
            x++;
        }else{
            map[y][x] = ID_DESTROYER;
            y++;
        }

    }

}


void PlacementCroiseur(int map[MAP_H][MAP_W])
{
    int taille = 4;
    int x = doRand(0, MAP_W-1);
    int y = doRand(0, MAP_H-1);
    int h = doRand(0, 1);

    int i;

for(i=0;i<taille;i++)
{
    if(h==0)
    {
        while((map[y][x+i] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }else{
        while((map[y+i][x] != 0) || (y+taille > MAP_H))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }
}

    for(i=0;i<taille;i++)
    {
        if(h==0)
        {
            map[y][x] = ID_CROISEUR;
            x++;
        }else{
            map[y][x] = ID_CROISEUR;
            y++;
        }

    }

}


void PlacementPorteAvion(int map[MAP_H][MAP_W])
{
    int taille = 6;
    int x = doRand(0, MAP_W-1);
    int y = doRand(0, MAP_H-1);
    int h = doRand(0, 1);

    int i;int j;

for(i=0;i<taille;i++)
{
    if(h==0)
    {
        while((map[y][x+i] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
        }
    }else{
        while((map[y+i][x] != 0) || (y+taille > MAP_H))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
        }
    }
}


    for(i=0;i<taille;i++)
    {
        if(h==0)
        {
            map[y][x] = ID_PORTEAVION;
            x++;
        }else{
            map[y][x] = ID_PORTEAVION;
            y++;
        }

    }

}






void f(){ // Passer a la ligne
    printf("\n");
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void Color(int couleurDuTexte,int couleurDeFond) //JE PENSE QU'IL N'Y A PAS BESOIN DE COMMENTAIRE POUR CETTE FONCTION
{


//0 : Noir
//1 : Bleu foncé
//2 : Vert foncé
//3 : Turquoise
//4 : Rouge foncé
//5 : Violet
//6 : Vert caca d'oie
//7 : Gris clair
//8 : Gris foncé
//9 : Bleu fluo
//10 : Vert fluo
//11 : Turquoise
//12 : Rouge fluo
//13 : Violet 2
//14 : Jaune
//15 : Blanc


        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

