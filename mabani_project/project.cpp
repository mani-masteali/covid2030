#include <iostream>
#include <cmath>
#include <windows.h>
#include <ctime>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
using namespace std;

float seconds=5;
const int ROWS = 17;
const int COLS = 16;

char game_screen[ROWS][COLS];


struct position{
    int x=0;
    int y=0;

};
void sleep_sec()
{
    clock_t startClock = clock();
    float secondsAhead=seconds * CLOCKS_PER_SEC;
    while(clock()<startClock+secondsAhead)
        continue;
}
void printHealth(int Healthnum) {
    cout << "Health: [ ";
    for (int i = 0; i < Healthnum; ++i) {
        cout << "| ";
    }
    cout << "]  " ;
}
void printMenu() {
    cout << "main menu:" << endl;
    cout << "1 : New Game" << endl;
    cout << "2 : Settings" << endl;
    cout << "3 : Credits" << endl;
    cout << "4 : Help" << endl;
    cout << "5 : Exit" << endl;
    cout << "please enter a number: ";
}

void killer_bar(int Round,int Kill){
    int condition=Kill%14;
    switch(condition)
   { case 1: cout<<"First Blood"<<endl; break;
    case 2: cout<<"Double Kill"<<endl; break;
    case 3: if(Round%2==0) cout<<"Triple Kill"<<endl;   else cout<<"Hatrick"<<endl;  break;
    case 4: cout<<"Team Killer"<<endl; break;
    case 5: cout<<"Headshot"<<endl; break;
    case 6: cout<<"Rampage"<<endl; break;
    case 7: cout<<"Killing Spree"<<endl; break;
    case 8: cout<<"Unstopabble"<<endl; break;
    case 9: cout<<"Monster Kill"<<endl; break;
    case 10: cout<<"Multi Kill"<<endl; break;
    case 11: cout<<"Ludicrous Kill"<<endl; break;
    case 12: cout<<"Ultra Kill"<<endl; break;
    case 13 : cout<<"Dominating"<<endl; break;
    case 0: cout<<"Godlike"<<endl; break;
    }
}
void show_game_screen(int level, int Vaccine, int Credit, int Round, int HealthNum, int Gunammo,int Magammo, int Kill,position &player,position zombies[],position ammos[],position vaccines[])
 {

    cout<<"Level: "<<level<<"  Vaccine: "<<Vaccine<<"  Credit: "<<Credit<<"  Round: "<<Round<<endl;
    printHealth(HealthNum);
    cout<<"Ammo: "<<Gunammo<<"/"<<Magammo<<"  Kill: "<<Kill<<endl;
  //  declining the game screen elements
    srand(time(NULL));
    int x,y;
    for(int i=0;i<17;i++)
    {
       for(int j=0;j<16;j++)
       {
           if(i==0 || i==16)
          { game_screen[i][j]='-';
            game_screen[i][j]='-';
           }
           else if(i==1 && j==1)
           {
               player.x=i;
               player.y=j;
           }
           else
           {
               if(j==0 || j==15)
                   game_screen[i][j]='|';
               else
                   game_screen[i][j]=' ';
           }
       }
    }
    game_screen[1][1]='P';
    game_screen[15][14]='D';
    // randomize
    int zombie_count=0;
    while(zombie_count<level)
    {
        x=rand()%17;
        y=rand()%16;
        if(game_screen[x][y]==' ')
        {

                game_screen[x][y]='Z';
                zombies[zombie_count].x=x;
                zombies[zombie_count].y=y;
            zombie_count++;
        }

    }
    int ammo_count=0;
    while(ammo_count<(level/2))
    {
        x=rand()%17;
        y=rand()%16;
        if(game_screen[x][y]==' ')
        {

                game_screen[x][y]='A';
                ammos[ammo_count].x=x;
                ammos[ammo_count].y=y;
            ammo_count++;
        }

    }
    int vaccine_count=0;
    while(vaccine_count<level)
    {
        x=rand()%17;
        y=rand()%16;
        if(game_screen[x][y]==' ')
        {

                game_screen[x][y]='V';
                vaccines[vaccine_count].x=x;
                vaccines[vaccine_count].y=y;
            vaccine_count++;
        }

    }
    //show
    for(int i=0;i<17;i++)
    {    for(int j=0;j<16;j++)
        {
            if(game_screen[i][j]=='P')
            {
                string RESET="\033[0m";
                string GREEN = "\033[32m";
                cout<<GREEN<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='D')
            {
                string RESET="\033[0m";
                string MAGNETA="\u001b[35m";
                cout<<MAGNETA<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='Z')
            {
                string RESET="\033[0m";
                string RED="\u001b[31m";
                cout<<RED<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='A')
            {
                string RESET="\033[0m";
                string BLUE="\u001b[34m";
                cout<<BLUE<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='V')
            {
                string RESET="\033[0m";
                string YELLOW="\u001b[33m";
                cout<<YELLOW<<game_screen[i][j]<<RESET;
             }
                else
            cout<<game_screen[i][j];

        }
    cout<<endl;
    }

}

void show_updated_game_screen(int level, int Vaccine, int Credit, int Round, int Healthnum, int Gunammo,int pocketammo, int Kill)
{
     cout << "Level: " << level << "  Vaccine: " << Vaccine << "  Credit: " << Credit << "  Round: " << Round << endl;
    printHealth(Healthnum);
    cout << "Ammo: " << Gunammo << "/" << pocketammo << "  Kill: " << Kill << endl;
    for(int i=0;i<17;i++)
    {    for(int j=0;j<16;j++)
        {
            if(game_screen[i][j]=='P')
            {
                string RESET="\033[0m";
                string GREEN = "\033[32m";
                cout<<GREEN<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='D')
            {
                string RESET="\033[0m";
                string MAGNETA="\u001b[35m";
                cout<<MAGNETA<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='Z')
            {
                string RESET="\033[0m";
                string RED="\u001b[31m";
                cout<<RED<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='A')
            {
                string RESET="\033[0m";
                string BLUE="\u001b[34m";
                cout<<BLUE<<game_screen[i][j]<<RESET;
            }
            else if(game_screen[i][j]=='V')
            {
                string RESET="\033[0m";
                string YELLOW="\u001b[33m";
                cout<<YELLOW<<game_screen[i][j]<<RESET;
             }
                else
            cout<<game_screen[i][j];

        }
    cout<<endl;
    }
}

void clear_screen(){
#if defined _WIN32
system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
system("clear");
#elif defined (__APPLE__)
system("clear");
#endif
}

void movePlayer( position &player, char move) {
    int currentX = player.x;
    int currentY = player.y;

    if ( (move == 'W' || move=='w') && player.x>1) {
        player.x--;
    } else if ( (move == 'A' || move=='a')  && player.y>1) {
        player.y--;
    } else if ( (move == 'S' || move=='s') && player.x<(ROWS-2)) {
        player.x++;
    } else if ( (move == 'D' || move=='d') && player.y<(COLS-2)) {
        player.y++;
    }
    game_screen[currentX][currentY] = ' ';

    game_screen[player.x][player.y] = 'P';
    if(game_screen[currentX][currentY]==' ' && currentX==15 && currentY==14)
    {
        game_screen[currentX][currentY]='D';
    }
}
void moveZombies(  bool zombies_shot[],position zombies[], int level, position &player, int round,position ammos[],position vaccines[]) {
    for (int i = 0; i < level; i++) {
        if(zombies_shot[i]==false)
      {  int currentX = zombies[i].x;
        int currentY = zombies[i].y;

        if (player.y < zombies[i].y && round%2==0) {
        //move left
            zombies[i].y--;
        } else if (player.y > zombies[i].y && round%2==0 ) {
            // move right
            zombies[i].y++;
        } else {
            //vertical movement
            if (player.x < zombies[i].x && round%2==0 ) {
                // move up
                zombies[i].x--;
            } else if (player.x > zombies[i].x && round%2==0) {
                // move down
                zombies[i].x++;
            }
        }

        // Update game screen with changes
        game_screen[currentX][currentY] = ' ';
        game_screen[zombies[i].x][zombies[i].y] = 'Z';
        if(game_screen[currentX][currentY]==' ' && currentX==15 && currentY==14)
        {
            game_screen[currentX][currentY]='D';
        }
        else{
            for(int i=0;i<level;i++)
             {
                if(game_screen[currentX][currentY]==' ' && currentX==vaccines[i].x && currentY==vaccines[i].y)
                {
                    game_screen[currentX][currentY]='V';
                }
                else if(game_screen[currentX][currentY]==' ' && currentX==zombies[i].x && currentY==zombies[i].y)
                {
                    game_screen[currentX][currentY]='Z';
                }

            }
             for(int i=0;i<(level/2);i++)
             {
                 if(game_screen[currentX][currentY]==' ' && currentX==ammos[i].x && currentY==ammos[i].y)
                 {
                     game_screen[currentX][currentY]='A';
                 }
             }
        }

        }
        else if(zombies_shot[i]==true)
        {
            game_screen[zombies[i].x][zombies[i].y]=' ';
        }
    }
}
void printupgrademenu(int maxgunammo,int Mag_needed_credit,int gunRange,int Range_needed_credit,int Healthnum,int Health_needed_credit)
{
            cout<<"0: Return to game."<<endl;
            cout<<"1: Upgrade capacity of magazine-1 bullet (maximum is 7 bullets, now is" <<maxgunammo<<") , Credit required:"<< Mag_needed_credit<<endl;
            cout<<"2: Upgrade range of shotgun-1 times the size of the person himself (maximum is 10 times, now is"<< gunRange<<") , Credit required:"<< Range_needed_credit<<endl;
            cout<<"3: get an additional health-(maximum is 5 healths, now is"<<Healthnum<<" ) , Credit required:"<<Health_needed_credit<<endl;
}

void collectItem(position player, position vaccines[], position ammos[], int &Vaccine, int &Credit, int &Healthnum, int &pocketammo,int level) {
    // Check if the player is on the same position as any vaccine
    for (int i = 0; i < 20; i++) {
        if (player.x == vaccines[i].x && player.y == vaccines[i].y) {
            // Player collected a vaccine
            Vaccine++;
            Credit += level + 1;
            cout << "Vaccine collected!" << endl;
            cout << level + 1 << " credit gained!" << endl;
            // Remove the collected vaccine from the map
            vaccines[i].x = 18;
            vaccines[i].y = 18;
            // Update Healthnum
            Healthnum++; // Example update, adjust as needed
            cout << "Health updated!" << endl;

            return; // Exit the function since the item is collected
        }
    }

    // Check if the player is on the same position as any ammo
    for (int i = 0; i < 10; i++) {
        if (player.x == ammos[i].x && player.y == ammos[i].y) {
            // Player collected ammo
            pocketammo++;
            cout << "Ammo collected!" << endl;
            // Remove the collected ammo from the map
            ammos[i].x = 18;
            ammos[i].y = 18;
            return; // Exit the function since the item is collected
        }
    }
}
void zombie_attacks(position player, position zombies[], bool zombies_shot[], int &Healthnum, int level) {
    for(int i = 0; i < level; i++) {
        if((player.x == zombies[i].x && player.y == zombies[i].y && !zombies_shot[i] ) ||
           (player.x == zombies[i].x && player.y == zombies[i].y + 1 && !zombies_shot[i]) ||
           (player.x == zombies[i].x && player.y == zombies[i].y - 1 && !zombies_shot[i]) ||
           (player.x == zombies[i].x + 1 && player.y == zombies[i].y && !zombies_shot[i]) ||
           (player.x == zombies[i].x - 1 && player.y == zombies[i].y && !zombies_shot[i]) ||
           (player.x == zombies[i].x + 1 && player.y == zombies[i].y + 1 && !zombies_shot[i]) ||
           (player.x == zombies[i].x + 1 && player.y == zombies[i].y - 1 && !zombies_shot[i]) ||
           (player.x == zombies[i].x - 1 && player.y == zombies[i].y - 1 && !zombies_shot[i]) ||
           (player.x == zombies[i].x - 1 && player.y == zombies[i].y + 1 && !zombies_shot[i]) ) {
            Healthnum--;
            cout << "The Zombie is eating you! You lost one of your healths!" << endl;

        }
        else if(player.x == zombies[i].x && player.y == zombies[i].y && zombies_shot[i])
        {
            game_screen[player.x][player.y]='P';
        }
    }
}

int main()
{
    //enable ansi codes on windows consoles
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode;
    GetConsoleMode(hConsole, &mode);

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    SetConsoleMode(hConsole, mode);

    string RESET="\033[0m";
    string RED="\u001b[31m";
    cout<<RED<<" ######    #######   ##       ##  #### ########          #######    #####     #######    #####"<<RESET<<endl;
    cout<<RED<<"##     ## ##     ##  ##       ##   ##  ##     ##        ##     ##  ##   ##   ##     ##  ##   ##"<<RESET<<endl;
    cout<<RED<<"##        ##     ##  ##       ##   ##  ##     ##               ## ##     ##         ## ##     ##"<<RESET<<endl;
    cout<<RED<<"##        ##     ##  ##      ##    ##  ##     ##         ######   ##     ##   #######  ##     ##"<<RESET<<endl;
    cout<<RED<<"##        ##     ##   ##    ##     ##  ##     ##        ##        ##     ##         ## ##     ##"<<RESET<<endl;
    cout<<RED<<"##     ## ##     ##    ##  ##      ##  ##     ##        ##         ##   ##   ##     ##  ##   ##"<<RESET<<endl;
    cout<<RED<<" ######    #######      ###       #### ########         #########   #####     #######    #####"<<RESET<<endl;
    cout<<"Welcome to Covid2030 game!"<<endl;
    cout<<endl;

    // delcaring neccessary variables
    int level=1;
    int Vaccine=0;
    int Credit=0;
    int Round=0;
    int Kill=0;
    int Gunammo=3;
    int pocketammo=1;
    int maxgunammo=3;
    int gunRange=5;
    string Health="[ | | | ]";
    int Healthnum=3;

    position player;
    bool zombies_shot[20]={false};

    //declaring an empty array of zombies
    position zombies[20];
    for(int i=0;i<20;i++)
    {
        zombies[i].x=18;
        zombies[i].y=18;
    }
    position ammos[10];
    for(int i=0;i<10;i++)
    {
        ammos[i].x=18;
        ammos[i].y=18;
    }
    position vaccines[20];
    for(int i=0;i<20;i++)
    {
        vaccines[i].x=18;
        vaccines[i].y=18;
    }

 char exitChoice;
  bool displayMenu = true;
     start1:
    while (true) {
        if (displayMenu) {
            printMenu();
        }

        char choice;
        bool validInput = true;
        cin >> choice;

        switch (choice) {
            case '1':
         {       cout << "starting new game..." << endl;
                displayMenu = false;
                clear_screen();
                show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                bool game_goes_on=true;
                start2:
                while(game_goes_on==true)
               { char action;
               cout<<"Please enter your action(round will be updated in case of invalid input): "<<endl;
                cin>>action;
                switch (action)   {
                    case 'W' :
                    case 'A':
                    case 'S':
                    case 'D':
                    case 'w':
                    case 'a':
                    case 's':
                    case 'd':
                     Round++;
                     movePlayer(player,action);
                     moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                     collectItem(player, vaccines, ammos, Vaccine, Credit, Healthnum,pocketammo,level);
                     zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                     if(Healthnum<=0)
                     {
                     cout<<	"You Died!"<<endl;
                     cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                     char pchoice;
                     cin>>pchoice;
                     if(pchoice=='y')
                     {
                        cout<<"The game will restart in 5 seconds"<<endl;
                        level=1;
                        Vaccine=0;
                        Credit=0;
                        Round=0;
                        Kill=0;
                        Gunammo=3;
                        pocketammo=1;
                        maxgunammo=3;
                        gunRange=5;
                        Healthnum=3;
                        for(int i=0;i<20;i++)
                        zombies_shot[i]=false;
                       show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                       game_goes_on=true;
                       goto start2;
                     }
                     else if(pchoice=='n')
                         game_goes_on = false;
                         level=1;
                         Vaccine=0;
                         Credit=0;
                         Round=0;
                         Kill=0;
                         Gunammo=3;
                         pocketammo=1;
                         maxgunammo=3;
                         gunRange=5;
                         Healthnum=3;
                         for(int i=0;i<20;i++)
                         zombies_shot[i]={false};
                         displayMenu=true;
                          goto start1;
                     }
                     else {
                      show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
               }
                     if(player.x == 15 && player.y == 14) {
                        bool allvaccinescollected = true;
                        for(int i = 0; i < level; i++) {
                            if( vaccines[i].x != 18 ||  vaccines[i].y != 18) {
                                allvaccinescollected = false;
                                break;
                            }
                        }

                        if(allvaccinescollected && level < 20) {
                            level++;
                            Round=0;
                            for(int i=0;i<20;i++)
                            zombies_shot[i]={false};
                            cout << "You Won! You have reached level " << level << endl;
                                    show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                        } else if(allvaccinescollected && level >= 20) {
                            cout << "Congratulations! You have successfully collected all the vaccines! Now it is time to return to the Earth. Goodbye!" << endl;
                            level=1;
                            Vaccine=0;
                            Credit=0;
                            Round=1;
                             Kill=0;
                            Gunammo=3;
                            pocketammo=1;
                            maxgunammo=3;
                            gunRange=5;
                            Health="[ | | | ]";
                            Healthnum=3;
                            for(int i=0;i<20;i++)
                           zombies_shot[i]=false;
                            printMenu();
                        } else {
                            cout<<"First get all the vaccines."<<endl;
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);

                        }
                    }

                     break;
                     case 'M':
                     case 'm':
              {   int mchoice;
                      cout << "0 : Return to game" << endl;
                      cout << "1 : New Game" << endl;
                      cout << "2 : Settings" << endl;
                      cout << "3 : Exit" << endl;
                      cout << "please enter a number: ";
                        cin>>mchoice;
                        if(mchoice==0){
                            show_updated_game_screen(level,Vaccine,Credit,Round,Healthnum,Gunammo,pocketammo,Kill);

                         }
                         else if(mchoice==1) {
                            //new game
                            level=1;
                            Vaccine=0;
                            Credit=0;
                            Round=1;
                             Kill=0;
                            Gunammo=3;
                            pocketammo=1;
                            maxgunammo=3;
                            gunRange=5;
                            Health="[ | | | ]";
                            Healthnum=3;
                            for(int i=0;i<20;i++)
                           zombies_shot[i]=false;
                           show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                         }


                         else if(mchoice==2){
                            cout << "Current level: " << level << endl;
                            cout<<"Final level is : 20"<<endl;
                            sleep_sec();
                        show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);

                         }
                         else if (mchoice==3){
                         displayMenu=true;
                         level=1;
                         Vaccine=0;
                         Credit=0;
                         Round=1;
                          Kill=0;
                         Gunammo=3;
                         pocketammo=1;
                         maxgunammo=3;
                         gunRange=5;
                         Health="[ | | | ]";
                         Healthnum=3;
                         for(int i=0;i<20;i++)
                        zombies_shot[i]=false;
                         goto start1;
                        }
                         else
                         {
                            while(mchoice >3 || mchoice<0)
                          {   cout<<"Please just enter the numbers in the menu"<<endl;
                             cin>>mchoice;
                             if(mchoice==0){
                                 show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);

                              }
                              else if(mchoice==1) {
                                 //new game
                                 level=1;
                                 Vaccine=0;
                                 Credit=0;
                                 Round=1;
                                  Kill=0;
                                 Gunammo=3;
                                 pocketammo=1;
                                 maxgunammo=3;
                                 gunRange=5;
                                 Health="[ | | | ]";
                                 Healthnum=3;
                                 for(int i=0;i<20;i++)
                                zombies_shot[i]=false;
                                show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                              }


                              else if(mchoice==2){
                                 cout << "Current level: " << level << endl;
                                 cout<<"Final level is : 20"<<endl;
                                 sleep_sec();
                             show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);



                              }
                              else if (mchoice==3){
                              displayMenu=true;
                              level=1;
                              Vaccine=0;
                              Credit=0;
                              Round=1;
                               Kill=0;
                              Gunammo=3;
                              pocketammo=1;
                              maxgunammo=3;
                              gunRange=5;
                              Health="[ | | | ]";
                              Healthnum=3;
                              for(int i=0;i<20;i++)
                             zombies_shot[i]=false;
                              goto start1;
                             }

                           }

                         }


                    break;
                }

                       case 'E':
                       case 'e':
                      {       cout << "Exiting the game. Goodbye!" << endl;
                            return 0;
                    break;
                }


                case 'T':
                case 't':
                {
                    //shooting up
                    if (Gunammo == 0) {
                        cout << "No charged ammo!" << endl;
                        Round++;
                        show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        zombie_attacks(player, zombies, zombies_shot, Healthnum, level);
                    }
                    else {
                        bool shot = false;
                        int closest_zombie_index = -1;
                        int closest_zombie_distance = gunRange + 1;
                        bool outrange = false;
                        for (int i = 0; i < level; i++) {
                            if (zombies[i].y == player.y && zombies[i].x < player.x && zombies_shot[i] == false) {
                                int distance_to_zombie = player.x - zombies[i].x;
                                if (distance_to_zombie <= gunRange && distance_to_zombie < closest_zombie_distance) {
                                    closest_zombie_index = i;
                                    closest_zombie_distance = distance_to_zombie;
                                }
                                else if (distance_to_zombie > gunRange) {
                                    Gunammo--;
                                    cout << "Zombie is not in range! Come closer." << endl;
                                    show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                                    outrange = true;
                                    break;
                                }

                        }
                        if (closest_zombie_index != -1) {
                            Round++;
                            zombies_shot[closest_zombie_index] = true;
                            Kill++;
                            Credit = Credit + level + 1;
                            cout << level + 1 << " credit gained!" << endl;
                            shot = true;
                        }
                        if (shot == true) {
                            Gunammo--;
                            killer_bar(Round, Kill);
                            moveZombies(zombies_shot, zombies, level, player, Round, ammos, vaccines);
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                        else if (shot == false && outrange == false) {
                            Round++;
                            if (shot == false)
                                Gunammo--;
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                    }

                                       moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                                       zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                                       if(Healthnum<=0)
                                       {
                                       cout<<	"You Died!"<<endl;
                                       cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                                       char pchoice;
                                       cin>>pchoice;
                                       if(pchoice=='y')
                                       {
                                          cout<<"The game will restart in 5 seconds"<<endl;
                                          level=1;
                                          Vaccine=0;
                                          Credit=0;
                                          Round=0;
                                          Kill=0;
                                          Gunammo=3;
                                          pocketammo=1;
                                          maxgunammo=3;
                                          gunRange=5;
                                          Healthnum=3;
                                          for(int i=0;i<20;i++)
                                          zombies_shot[i]={false};
                                         show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                                         game_goes_on=true;
                                         goto start2;
                                       }
                                       else if(pchoice=='n')
                                           game_goes_on = false;
                                           level=1;
                                           Vaccine=0;
                                           Credit=0;
                                           Round=0;
                                           Kill=0;
                                           Gunammo=3;
                                           pocketammo=1;
                                           maxgunammo=3;
                                           gunRange=5;
                                           Healthnum=3;
                                           for(int i=0;i<20;i++)
                                           zombies_shot[i]={false};
                                           displayMenu=true;
                                            goto start1;
                                       }

                 break;
           }
                }


                case 'G':
                case 'g':
                {
                    //shooting down
                    if (Gunammo == 0) {
                        cout << "No charged ammo!" << endl;
                        Round++;
                        show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                    }
                    else {
                        bool shot = false;
                        int closest_zombie_index = -1;
                        int closest_zombie_distance = gunRange + 1;
                        bool outrange = false;
                        for (int i = 0; i < level; i++) {
                            if (zombies[i].y == player.y && zombies[i].x > player.x && zombies_shot[i] == false) {
                                int distance_to_zombie = zombies[i].x - player.x;
                                if (distance_to_zombie <= gunRange && distance_to_zombie < closest_zombie_distance) {
                                    closest_zombie_index = i;
                                    closest_zombie_distance = distance_to_zombie;
                                }
                               else  if (distance_to_zombie > gunRange) {
                                    Gunammo--;
                                    cout << "Zombie is not in range! Come closer." << endl;
                                    Round++;
                                    show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                                    outrange = true;
                                    break;
                                }
                            }
                        }
                        if (closest_zombie_index != -1) {
                            Round++;
                            zombies_shot[closest_zombie_index] = true;
                            Kill++;
                            Credit = Credit + level + 1;
                            cout << level + 1 << " credit gained!" << endl;
                            shot = true;
                        }
                        if (shot == true) {
                            Gunammo--;
                            killer_bar(Round, Kill);
                            moveZombies(zombies_shot, zombies, level, player, Round, ammos, vaccines);
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                        else if (shot == false && outrange == false) {
                            Round++;
                            if (shot == false)
                                Gunammo--;
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                    }
                                            moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                                            zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                                            if(Healthnum<=0)
                                            {
                                            cout<<	"You Died!"<<endl;
                                            cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                                            char pchoice;
                                            cin>>pchoice;
                                            if(pchoice=='y')
                                            {
                                               cout<<"The game will restart in 5 seconds"<<endl;
                                               level=1;
                                               Vaccine=0;
                                               Credit=0;
                                               Round=0;
                                               Kill=0;
                                               Gunammo=3;
                                               pocketammo=1;
                                               maxgunammo=3;
                                               gunRange=5;
                                               Healthnum=3;
                                               for(int i=0;i<20;i++)
                                               zombies_shot[i]={false};
                                              show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                                              game_goes_on=true;
                                              goto start2;
                                            }
                                            else if(pchoice=='n')
                                                game_goes_on = false;
                                                level=1;
                                                Vaccine=0;
                                                Credit=0;
                                                Round=0;
                                                Kill=0;
                                                Gunammo=3;
                                                pocketammo=1;
                                                maxgunammo=3;
                                                gunRange=5;
                                                Healthnum=3;
                                                for(int i=0;i<20;i++)
                                                zombies_shot[i]={false};
                                                displayMenu=true;
                                                 goto start1;
                                            }

                      break;
                }

                case 'F':
                case 'f':
               {
                    //shooting right
                    if (Gunammo == 0) {
                        cout << "No charged ammo!" << endl;
                        Round++;
                        show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                    }
                    else {
                        bool shot = false;
                        int closest_zombie_index = -1;
                        int closest_zombie_distance = gunRange + 1;
                        bool outrange = false;
                        for (int i = 0; i < level; i++) {
                            if (zombies[i].x == player.x && zombies[i].y > player.y && zombies_shot[i] == false) {
                                int distance_to_zombie = zombies[i].y - player.y;
                                if (distance_to_zombie <= gunRange && distance_to_zombie < closest_zombie_distance) {
                                    closest_zombie_index = i;
                                    closest_zombie_distance = distance_to_zombie;
                                }
                               else if (distance_to_zombie > gunRange) {
                                    Gunammo--;
                                    cout << "Zombie is not in range! Come closer." << endl;
                                    show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                                    outrange = true;
                                    break;
                                }
                            }
                        }
                        if (closest_zombie_index != -1) {
                            Round++;
                            zombies_shot[closest_zombie_index] = true;
                            Kill++;
                            Credit = Credit + level + 1;
                            cout << level + 1 << " credit gained!" << endl;
                            shot = true;
                        }
                        if (shot == true) {
                            Gunammo--;
                            killer_bar(Round, Kill);
                            moveZombies(zombies_shot, zombies, level, player, Round, ammos, vaccines);
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                        else if (shot == false && outrange == false) {
                            Round++;
                            if (shot == false)
                                Gunammo--;
                            moveZombies(zombies_shot, zombies, level, player, Round, ammos, vaccines);
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                    }

                                       moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                                       zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                                       if(Healthnum<=0)
                                       {
                                       cout<<	"You Died!"<<endl;
                                       cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                                       char pchoice;
                                       cin>>pchoice;
                                       if(pchoice=='y')
                                       {
                                          cout<<"The game will restart in 5 seconds"<<endl;
                                          level=1;
                                          Vaccine=0;
                                          Credit=0;
                                          Round=0;
                                          Kill=0;
                                          Gunammo=3;
                                          pocketammo=1;
                                          maxgunammo=3;
                                          gunRange=5;
                                          Healthnum=3;
                                          for(int i=0;i<20;i++)
                                          zombies_shot[i]={false};
                                         show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                                         game_goes_on=true;
                                         goto start2;
                                       }
                                       else if(pchoice=='n')
                                           game_goes_on = false;
                                           level=1;
                                           Vaccine=0;
                                           Credit=0;
                                           Round=0;
                                           Kill=0;
                                           Gunammo=3;
                                           pocketammo=1;
                                           maxgunammo=3;
                                           gunRange=5;
                                           Healthnum=3;
                                           for(int i=0;i<20;i++)
                                           zombies_shot[i]={false};
                                           displayMenu=true;
                                            goto start1;
                                       }

                  break;
                }


                case 'H':
                case 'h':
                {
                    //shooting left
                    if (Gunammo == 0) {
                        cout << "No charged ammo!" << endl;
                        Round++;
                        show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                    }
                    else {
                        bool shot = false;
                        int closest_zombie_index = -1;
                        int closest_zombie_distance = gunRange + 1;
                        bool outrange = false;
                        for (int i = 0; i < level; i++) {
                            if (zombies[i].x == player.x && zombies[i].y < player.y && zombies_shot[i] == false) {
                                int distance_to_zombie = player.y - zombies[i].y;
                                if (distance_to_zombie <= gunRange && distance_to_zombie < closest_zombie_distance) {
                                    closest_zombie_index = i;
                                    closest_zombie_distance = distance_to_zombie;
                                }
                                else if (distance_to_zombie > gunRange) {
                                    Gunammo--;
                                    cout << "Zombie is not in range! Come closer." << endl;
                                    show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                                    outrange = true;
                                    break;
                                }
                            }
                        }
                        if (closest_zombie_index != -1) {
                            Round++;
                            zombies_shot[closest_zombie_index] = true;
                            Kill++;
                            Credit = Credit + level + 1;
                            cout << level + 1 << " credit gained!" << endl;
                            shot = true;
                        }
                        if (shot == true) {
                            Gunammo--;
                            killer_bar(Round, Kill);
                            moveZombies(zombies_shot, zombies, level, player, Round, ammos, vaccines);
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                        else if (shot == false && outrange == false) {
                            Round++;
                            if (shot == false)
                                Gunammo--;
                            show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                        }
                    }


             moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                                       zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                                       if(Healthnum<=0)
                                       {
                                       cout<<	"You Died!"<<endl;
                                       cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                                       char pchoice;
                                       cin>>pchoice;
                                       if(pchoice=='y')
                                       {
                                          cout<<"The game will restart in 5 seconds"<<endl;
                                          level=1;
                                          Vaccine=0;
                                          Credit=0;
                                          Round=0;
                                          Kill=0;
                                          Gunammo=3;
                                          pocketammo=1;
                                          maxgunammo=3;
                                          gunRange=5;
                                          Healthnum=3;
                                          for(int i=0;i<20;i++)
                                          zombies_shot[i]={false};
                                         show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                                         game_goes_on=true;
                                         goto start2;
                                       }
                                       else if(pchoice=='n')
                                           game_goes_on = false;
                                           level=1;
                                           Vaccine=0;
                                           Credit=0;
                                           Round=0;
                                           Kill=0;
                                           Gunammo=3;
                                           pocketammo=1;
                                           maxgunammo=3;
                                           gunRange=5;
                                           Healthnum=3;
                                           for(int i=0;i<20;i++)
                                           zombies_shot[i]={false};
                                           displayMenu=true;
                                            goto start1;
                                       }
                  break;
                }

           case 'R':
           case 'r':
   {   Round++;
        if (pocketammo==0){
                cout<<"No Ammo!"<<endl;
                show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
               }
        else if (Gunammo==maxgunammo){
                cout<<"The gun is already Charged"<<endl;
               }
               else
        {   while(Gunammo<=maxgunammo && pocketammo!=0){

               pocketammo--;
                Gunammo++;
        }
         cout<<"Reloaded!"<<endl;
         show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
        }
                             moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                             zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
         show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
         if(Healthnum<=0)
         {
         cout<<	"You Died!"<<endl;
         cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
         char pchoice;
         cin>>pchoice;
         if(pchoice=='y')
         {
            cout<<"The game will restart in 5 seconds"<<endl;
            level=1;
            Vaccine=0;
            Credit=0;
            Round=0;
            Kill=0;
            Gunammo=3;
            pocketammo=1;
            maxgunammo=3;
            gunRange=5;
            Healthnum=3;
            for(int i=0;i<20;i++)
            zombies_shot[i]={false};
           show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
           game_goes_on=true;
           goto start2;
         }
         else if(pchoice=='n')
             game_goes_on = false;
             level=1;
             Vaccine=0;
             Credit=0;
             Round=0;
             Kill=0;
             Gunammo=3;
             pocketammo=1;
             maxgunammo=3;
             gunRange=5;
             Healthnum=3;
             for(int i=0;i<20;i++)
             zombies_shot[i]={false};
             displayMenu=true;
              goto start1;
         }

            break;
                }
                case 'u':
                    case 'U':
                          {  int uchoice;
                        do{

                        int Health_needed_credit=(level+1) * Healthnum;
                        int  Range_needed_credit=gunRange+level;
                        int  Mag_needed_credit=Gunammo *level;
                                    printupgrademenu(maxgunammo, Mag_needed_credit, gunRange, Range_needed_credit, Healthnum, Health_needed_credit);
            cin>>uchoice;
            if (uchoice==0)
            {
             show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);

            }
        else	if (uchoice==1)
            {

                if (Credit>=Mag_needed_credit &&maxgunammo!=7)
                {
                maxgunammo++;
                Credit=Credit-Mag_needed_credit;
                cout<<"Upgrade done successfully.Your magazine capacity is now: "<<maxgunammo<<endl;
                }
                else if (Credit<Mag_needed_credit &&maxgunammo!=7)
                {

                cout<<"Unfortunately, your credit is not enough to get this item. Please gain"<<Mag_needed_credit-Credit<< "more credit by playing."<<endl;
            }
                else
                {
                cout<<"The selected item is maximum."<<endl;
                }

            }
            else if (uchoice==2)
            {
                if (Credit>=Range_needed_credit && gunRange!=10)
            {
                gunRange++;
                Credit=Credit-Range_needed_credit;
                cout<<"Upgrade done successfully.Your shotgun range is now: "<<gunRange<<endl;
            }
           else if(Credit<Range_needed_credit &&gunRange!=10){

                cout<<"Unfortunately,your credit is not enough to get this item. Please gain"<<Range_needed_credit-Credit<< "more credit by playing."<<endl;
            }
            else
            {
                cout<<"The selected item is maximum."<<endl;;

            }

            }
            else if(uchoice==3)
            {
            if (Credit>=Health_needed_credit &&Healthnum!=5)
            {

            Healthnum++;
            Credit=Credit-Health_needed_credit;
        cout<<"Additional health received successfully.Your health is now "<<Healthnum<<endl;
          }
            else if(Credit<Health_needed_credit &&Healthnum!=5)
                cout<<"Unfortunately, your credit is not enough to get this item. Please gain"<<Health_needed_credit-Credit<< "more credit by playing."<<endl;
                else {
                cout<<"	The selected item is maximum."<<endl;

                }

            }
            else
            cout<<"Please just enter the numbers in the menu:"<<endl;
                }
                while (uchoice != 0);
            break;
                }
                default:
                 Round++;
                show_updated_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill);
                moveZombies(zombies_shot,zombies,level,player,Round,ammos,vaccines);
                zombie_attacks(player,zombies,zombies_shot,Healthnum,level);
                if(Healthnum<=0)
                {
                cout<<	"You Died!"<<endl;
                cout<<"You Lose! Would you like to try again?(y/n)"<<endl;
                char pchoice;
                cin>>pchoice;
                if(pchoice=='y')
                {
                   cout<<"The game will restart in 5 seconds"<<endl;
                   level=1;
                   Vaccine=0;
                   Credit=0;
                   Round=0;
                   Kill=0;
                   Gunammo=3;
                   pocketammo=1;
                   maxgunammo=3;
                   gunRange=5;
                   Healthnum=3;
                   for(int i=0;i<20;i++)
                   zombies_shot[i]={false};
                  show_game_screen(level, Vaccine, Credit, Round, Healthnum, Gunammo, pocketammo, Kill, player,zombies,ammos,vaccines);
                  game_goes_on=true;
                  goto start2;
                }
                else if(pchoice=='n')
                    game_goes_on = false;
                    level=1;
                    Vaccine=0;
                    Credit=0;
                    Round=0;
                    Kill=0;
                    Gunammo=3;
                    pocketammo=1;
                    maxgunammo=3;
                    gunRange=5;
                    Healthnum=3;
                    for(int i=0;i<20;i++)
                    zombies_shot[i]={false};
                    displayMenu=true;
                     goto start1;
                }
                    break;
        }


}while (choice != '0');




}

            case '2':
                cout << "Current level: " << level << endl;
                cout<<"Final level is : 20"<<endl;
                break;

            case '3':
                cout << "creators: EMAD MEMAR & MANI MASTEALI" << endl;
                sleep_sec();
                break;
            case '4':
                cout << "This is a survival game. You should try to keep away from zombies and collect ammo and vaccines." << endl;
                cout << "Player's location is shown by character (P), zombies(Z), vaccines(V), and ammos(A)" << endl;
                cout << "You gain credit by killing zombies, collecting ammos, and vaccines." << endl;
                cout<<endl;
                cout <<"The player moves with W(up), S(down), D(right), A(left)"<<endl;
                cout<<endl;
                cout <<"If you want to shoot the zombies use this instruction: "<<endl;
                cout<< " T(shooting up), G(shooting down), H(shooting left), F(shooting right)" <<endl;
                cout<<"Tip: you can enter either upper case letters or lowercase ones for shooting and movement "<<endl;
                cout<<endl;
                cout << "You lose if your health reaches 0." << endl;
                sleep_sec();
                break;
            case '5':
                cout << "Are you sure you want to exit the game?" << endl;
                cout << " n " << endl;
                cout << " y " << endl;

                cin >> exitChoice;

                if (exitChoice == 'n' || exitChoice == 'N') {
                    displayMenu = true;
                } else if (exitChoice == 'y' || exitChoice == 'Y') {
                    cout << "Good Bye!" << endl;
                    return 0;
                } else {
                    cout << "Please enter valid letters: y or n." << endl;
                    validInput = false;
                }
                break;
            default:
                cout << "Enter appropriate number." << endl;
                validInput = false;
                Round++;
                break;
        if (validInput) {
            displayMenu = true;
        }
    }

}
}









