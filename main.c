#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NB_BATEAU 4
#define ID_CORVETTE 1
#define ID_DESTROYER 2
#define ID_CROISEUR 3
#define ID_PORTEAVION 4
#define MAP_ITEMS 6
#define MAP_H 10
#define MAP_W 10


int main()
{
    Title();

    int mdj;
    printf("Choisissez le mode de jeu : \n1-IA vs IA \n2-Joueur vs IA \n3-Joueur vs Joueur \n4-Exit\n");
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
        exit(0);
    }

}






void Joueur_Joueur()
{

}
















void Joueur_IA()
{
    int map_j[MAP_H][MAP_W] = {0};
    int map_ia[MAP_H][MAP_W] = {0};

    int tab_j[MAP_H][MAP_W] = {0};
    int tab_ia[MAP_H][MAP_W] = {0};

    int size[6] = {1,3,3,4,4,6};

    int x;int y;int h = 0;

    int nbBateau = 21;
    int i = 0;
    int j = 0;


    printf("Vous avez choisi le mode Joueur VS IA \nAppuyez sur Entree");
    fflush(stdin);
    getchar();

    system("cls");

    while(i < 6)
    {
        PrintMap(map_j, "");
        printf("Placement bateau %d a %d case(s)\n", i+1, size[i]);

        x=50000000;y=50000000000;h=0;
        int correct=0;


        while((x+size[i] > MAP_W && h == 0) || (y+size[i] > MAP_H && h != 0) || correct == 1)
        {
            correct = 0;
            printf("Saisissez une coordonnee X entre 0 et %d \nX : ", MAP_W-1);
            scanf("%d", &x);
            printf("Saisissez une coordonnee Y entre 0 et %d \nY : ", MAP_H-1);
            scanf("%d", &y);
            printf("Saisissez l'orientation du bateau : 0 pour vertical et 1 pour horizontal \n");
            scanf("%d", &h);


            for(j=0;j<size[j];j++)
            {int k = 0;
                while(correct == 0 && k<size[j])
                {
                    if(h == 0)
                    {
                        if(map_j[y][x+j] != 0)
                        {
                            correct = 1;
                        }else{
                            correct = 0;
                        }printf("%d", correct);
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

            if(x+size[i] > MAP_W || y+size[i] > MAP_H || correct == 1)
            {

                printf("Coordonnees incorrects, reeessayer \n");
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

    }



    f();f();
    PlacementPorteAvionIA(map_ia);
    PlacementCroiseurIA(map_ia);
    PlacementCroiseurIA(map_ia);
    PlacementDestroyerIA(map_ia);
    PlacementDestroyerIA(map_ia);
    PlacementCorvetteIA(map_ia);

    printf("Debut du jeu ! Appuyer sur Entree \n");
    fflush(stdin);
    getchar();

    //**************************************************

    int tourJ = 0;
    int compteurJ = 21;int compteurIA = 21;
    x=0;y=0;

    while(compteurJ > 0 && compteurIA > 0)
    {
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
                printf("Vous avez rentrez des coordonnees incorrects ou des coordonnees que vous avez deja rentree \n");
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

            printf("Appuyer sur Entree \n");
            fflush(stdin);
            getchar();

            tourJ=1;
        }else{
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

            printf("Appuyer sur Entree \n");
            fflush(stdin);
            getchar();

            tourJ=0;
            tab_ia[y][x] = 1;
            f();
        }
    }

}























void Title()
{
    char string[] = "111110011111001111100111110010000001111100111110010001001001111121000100100010000100000010000100000010000001000000100010010010001211111001111100001000000100001000000111100010000001000100100111112100010010001000010000001000010000001000000111110011111001001210001001000100001000000100001000000100000000001001000100100121111100100010000100000010000111110011111001111100100010010012";
    char string2[] = "0000000000000,,.=czzttzzz==+..,,200000000,,sS5t:::::::::::::::::ttZt>.200000,aEEtt::::::::::::::::::::::::::t3>.2000,#5ttttz::;;;;;;;;;;;;;;;;;:::::::::::t3>.200/Etttt35SEEEERQE5F***I1::::0::::::::::::t3x.20/E3333EEtt3E7XE5P`000000;E::::..00000:::::::::::t3s,2JE53EEEEEEtz3k..00000000;5zzzz::::..000000:::::::::::!3x,2|E3EEEEEEEEEzzZ5sc..;;z5ttttttttzzz:::..000000:::::::::::7t.,2|E3EEEEEEEEEEEEEzzzzzztttttt3333ttttzzz:::..000000::::::::::/2{EEEEEEEEEEEEEEEEEEEEEEEEttttt333333ttttzzz:::..000000:::::ySx.wgEh.,20EEEEEEEEEEEEEEEEEEEEEEEEEEEEttt33333333ttttzzz:::..00000:Ztztt35::::3e.,20IEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEtt3Ftt55E33tttzzzz:::..:Ettztzt::::::::zF200EEEEEEEEEEEEEEEEEEZl.00`'00QEE55z:;z;;::Xt333tttzzz::t::ZtZF0000::::;F200QEEEEEEEEEEEEEEES5::.0000000}QZE5EL00`%.0I3333333ttt1zztzZ...000000;F20000VEEEE535EEEEEE1::::.0000000fUEE[[.000JL:Jttt333333ttttttzz:::..00;F:.200000EEEE33333EESF:::::..000000000000000]tgEEEEEttt3tt333tttttzzz::y.00:..20000000\EEEE333331:::::::::........0000.y5EEEEEEEEEEEtS53333333tttt/000000:..200000000QEEEEttttZ5sz::::::;izzzzzzz3@EEEEEEEEEE5SEES55Ettt333333Z00000000::..200000000004EEEEtttttt3ZEEEEEEEEEEEEEEEEEEEEEEEE5EEEZE3EEEEEtttttZ0::..0000::::.2000000000000`*EEEEEEtttttt33335EEEEEEEEEEEEEEEE5EEEEESEEEEEEEEEEF000::::::::::::.2000000000000000`*4EEEEEEtttttt33335EEEEEEEEEEESEEEEEZEEEEEEEEE5F:::::::::::::::::.20000000000000000000`*EEEEEEEttttt333335EEEEEESEE5EEZEEEEEEEEE5L0::::00::::::::::::.200000000000000000000000`*GEEEEEEttttt333335EZEEEEEZEEEEEEEEE5F0:::::::.::::::::::::.2000000000000000000000000000`*EEEEEE3ttttt33EE33E5EEEEEEEEEES0000::::::::::::::::::::20000000000000000000000000000000*QEEEEE3t3EEESE5E35EEEEEEEZ0000000::::::::::::::::::..200000000000000000000000000000000000*EEE5F4EEE3Et33335EEEZ.00000000:::::::::::::::::;z.....2000000000000000000000000000000000000000`000EEEtttttt33QE.::::.0000::::::::::;:::::::::::::!.200000000000000000000000000000000000000000000JEEEEEE3ttQF00'::::...00000::::::c=!::::00:=zzc:::2000000000000000000000000000000000000000000000004EEEE3F00000000:=::!::::::::::..0':...0000000::200000000000000000000000000000000000000000000000000`V`000000000000000000000000:!tt:=.::.0000:Sz.20000000000000000000000000000000000000000000000000000000000000000000000000000000000000:::000000====2";
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

    for(i = 0;i<2250;i++)
    {
        if(string2[i] == '0')
        {
            Color(0, 0);
            printf("%c", string2[i]);
        }else if(string2[i] == '2'){
            f();
        }else{
            Color(12, 0);
            printf("%c", string2[i]);
        }
    }





    f();
    Color(15,0);
}


void PrintMap(int map[MAP_H][MAP_W], char string[26])
{
    int i;
    int j;

    printf("%s\n  ", string);

    for(i=0;i<MAP_W;i++)
    {
        if(i<10)
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
            printf("%d ", i);
        }else{
            printf("%d", i);
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
                Color(0, 15);
                break;
            default:
                Color(0, 4);
                break;
            }

            printf("%d  ", map[i][j]);
        }
        f();
        Color(15, 0);
    }

}


void PlacementCorvetteIA(int map[MAP_H][MAP_W])
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

void PlacementDestroyerIA(int map[MAP_H][MAP_W])
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
        while((map[y+i][x] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }else{
        while((map[y][x+i] != 0) || (y+taille > MAP_H))
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


void PlacementCroiseurIA(int map[MAP_H][MAP_W])
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
        while((map[y+i][x] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
            i=0;
        }
    }else{
        while((map[y][x+i] != 0) || (y+taille > MAP_H))
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


void PlacementPorteAvionIA(int map[MAP_H][MAP_W])
{
    int taille = 6;
    int x = doRand(0, MAP_W-1);
    int y = doRand(0, MAP_H-1);
    int h = doRand(0, 1);

    int i;int j;


    if(h==0)
    {
        while((map[y][x] != 0) || (x+taille > MAP_W))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
        }
    }else{
        while((map[y][x] != 0) || (y+taille > MAP_H))
        {
            x = doRand(0, MAP_W-1);
            y = doRand(0, MAP_H-1);
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


void IA_IA()
{
    printf("Vous avez choisi le mode IA vs IA. \nAppuyer sur Entree\n");

    int map_IA1[MAP_H][MAP_W] = {0};
    int map_IA2[MAP_H][MAP_W] = {0};
    int tour = 0;
    int tab1[MAP_H][MAP_W] = {0};
    int tab2[MAP_H][MAP_W] = {0};
    int x = doRand(0, MAP_W+1);
    int y = doRand(0, MAP_H+1);

    int compteur1 = 21;
    int compteur2 = 21;



    PlacementPorteAvionIA(map_IA1);
    PlacementCroiseurIA(map_IA1);
    PlacementCroiseurIA(map_IA1);
    PlacementDestroyerIA(map_IA1);
    PlacementDestroyerIA(map_IA1);
    PlacementCorvetteIA(map_IA1);

    PlacementPorteAvionIA(map_IA2);
    PlacementCroiseurIA(map_IA2);
    PlacementCroiseurIA(map_IA2);
    PlacementDestroyerIA(map_IA2);
    PlacementDestroyerIA(map_IA2);
    PlacementCorvetteIA(map_IA2);


    fflush(stdin);
    getchar();

    PrintMap(map_IA1, "IA 1");
    f();
    PrintMap(map_IA2, "IA 2");

    printf("Appuyer sur Entree pour commencer le jeu\n");
    fflush(stdin);
    getchar();


    while(compteur1 > 0 && compteur2 > 0)
    {
        if(tour == 0)
        {
            while(tab1[y][x] != 0)
            {
                x = doRand(0, MAP_W+1);
                y = doRand(0, MAP_H+1);
            }

            if(map_IA2[y][x] != 0)
            {
                printf("IA 1 A TOUCHE IA 2 EN %d:%d\n", y, x);
                map_IA2[y][x] = 5;
                compteur2--;
            }else{
                printf("PLOUF... \n");
                map_IA2[y][x] = 9;
            }

            tab1[y][x] = 1;

            tour = 1;


        }else{
            while(tab2[y][x] != 0)
            {
                x = doRand(0, MAP_W+1);
                y = doRand(0, MAP_H+1);
            }

            if(map_IA1[y][x] != 0)
            {
                printf("IA 2 A TOUCHE IA 1 EN %d:%d\n", y, x);
                map_IA1[y][x] = 5;
                compteur1--;
            }else{
                printf("PLOUF... \n");
                map_IA1[y][x] = 9;
            }

            tab1[y][x] = 1;
            tour = 0;

        }

    }



    if(compteur1 <= 0)
    {
        printf("IA 2 A GAGNEEEEEEE !!!\n");
    }else if(compteur2 == 0){
        printf("IA 1 A GAGNEEEEEEE !!!\n");
    }

    PrintMap(map_IA1, "IA 1");
    PrintMap(map_IA2, "IA 2");

    printf("fini\n");
    getchar();
    main();

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

void Color(int couleurDuTexte,int couleurDeFond)
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

