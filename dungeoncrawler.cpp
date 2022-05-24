//Ian Gerodias, Daksh Narang, Emmanuel Santos, Jesus Perez
//05-11-2022
//dungeonCrawlerProject
//text-based small game using nested if statements and random number generators
//version 20
#include <iostream>

#include <string>

using namespace std;

int main() {
  int round2Input;
  bool status = false;
  bool key = false;
  string choices, start, initialDivergence, riddleAnswer;
  cout << "Press ENTER to continue...\n";
  cout << "Humanity is on its last legs.\n";
  cin.get();
  cout << "War has ravaged the world twice over, and the last remnants of mankind cling to their lives desperately.\n";
  cin.get();
  cout << "A lone dragon approaches you, the player.\n";
  cin.get();
  cout << "Welcome, child. Your kind dies by the numbers every day.\n";
  cin.get();
  cout << "You wish to save them?\n";
  cout << "Press \"Y\" for Yes\n";
  cin >> start;
  while (start != "y" && start != "Y") { //checks for invalid input
    cout << "Invalid input, please try again\n";
    cin >> start;
  }
  if (start == "Y" || start == "y") // starting game
  {
    cout << "It is the year 2042, and the human race is in danger of being banished\n";
    cin.get();
    cout << "A dragon says \"If you are able to pass the challenge, humanity is saved, but if not it is the end\"\n";
    cin.get();
    cout << "You Wake up in a cave and you must find an exit withouth getting lost \n";
    cin.get();
    cout << "There are three paths presented in front of you.";
    cin.get();
    cout << "One path goes to the left, one goes to the right, and one goes down the middle.";
    cin.get();
    cout << "Press \"L\" to go down the left path.\n";
    cout << "Press \"R\" to go down the right path\n";
    cout << "Press \"M\" to go down the middle path.\n";
    cin >> initialDivergence;
    while (initialDivergence != "L" && initialDivergence != "M" && initialDivergence != "R" && initialDivergence != "r" && initialDivergence != "l" && initialDivergence != "m") { //checks for invalid input
      cout << "Invalid input, please try again\n";
      cin >> initialDivergence;
    }
    if (initialDivergence == "L" || initialDivergence == "l") {
      cout << "On the right tunnel there is a map of the cave\n";
      cin.get();
      cout << "On the left tunnel there is a lighting torch\n";
      cin.get();
      cout << "Make your choice. \n";
      cout << "\"R\" to go to right tunnel\n"; //start round 1
      cout << "\"L\" to go to left tunnel\n";
      cin >> choices; // first choice input
      while (choices != "L" && choices != "R" && choices != "r" && choices != "l") { //checks for invalid input
        cout << "Invalid input, please try again\n";
        cin >> choices;
      }
      if (choices == "L" || choices == "l") // 1st choice branch (Left)
      {
        cout << "You grab the torch and you light up the path ahead\n";
        cin.get();
        cout << "You have made it to the 2nd round, and given an option to take another Left or Right tunnel \n";
        cin.get();
        cout << "Right tunnel contains a numberpad on floor. \"R\" to go to right tunnel\n"; //start round 2
        cin.get();
        cout << "You hear multiple snakes hissing in the Left tunnel \"L\" to go to left tunnel\n";
        cin >> choices;
        while (choices != "L" && choices != "R" && choices != "r" && choices != "l") { //checks for invalid input on round 2
          cout << "Invalid input, please try again\n";
          cin >> choices;
        }
        if (choices == "R" || choices == "r") // 2nd choice branch (right)
        {
          cout << "you must input the half of 2+2\n"; // 2nd choice branch mini-game
          cin >> round2Input;
          if (round2Input == 2) //correct mini - game
          {
            cout << "The path ahead opens up\n";
          } else {
            cout << "Inccorect the cave starts to collapse with you in it." << endl;
            cout << "Game over." << endl;
            return 0; //ends game
          }
        } else if (choices == "L" || choices == "l") //2nd choice branch (left)
        {
          cout << "You tolerate the pain of walking through the snakes as they bite you\n ";
          cout << "But survive and make it out the other side\n";
          status = true; //setting status of player if chosen poisen path
        }

        cout << "Right tunnel you see a bottle on the floor. \"R\" to go to right tunnel\n"; // start round 3
        cout << "Left tunnel you see a mysterious key on the floor \"L\" to go to left tunnel\n";
        cin >> choices;
        while (choices != "L" && choices != "R" && choices != "r" && choices != "l") { //checks for invalid input on round 3
          cout << "Invalid input, please try again\n";
          cin >> choices;
        }
        if (choices == "R" || choices == "r") //3rd choice branch (right)
        {
          cout << "You picked up the antidote for snake poision\n";
          cout << "You move forward into the tunnel\n";
          status = false; //player is poisioned

        } else if (choices == "L" || choices == "l") //3rd choice branch (left)
        {
          cout << "You obtain the magic key and move forward into the tunnel\n";
          key = true; //player has the key

        }

        cout << "Right tunnel is a mysterious dark tunnel. \"R\" to go to right tunnel\n"; // start round 4
        cout << "Left tunnel you see a ligh comming from the end end of the cave \"L\" to go to left tunnel\n";
        cin >> choices;
        while (choices != "L" && choices != "R" && choices != "r" && choices != "l") { //checks for invalid input round 4
          cout << "Invalid input, please try again\n";
          cin >> choices;
        }
        if (choices == "R" || choices == "r") //4th choice branch (right)
        {
          cout << "You follow through the dark tunnel and find a locker door\n";
          if (key == true) //checking if player has key
          {
            cout << "CONGRATULATIONS YOU HAVE BEATEN THE DRAGON CHALLENGE\n";
          } else {
            cout << "You have no key to open the door\n";
            cout << "Gamme over.\n";
            return 0; //ends game
          }
        } else if (choices == "L" || choices == "l") //4th choice branch (left)
        {
          cout << "The light ahead was just a torch at a dead end cave\n";
          cout << "You failed re-think your choices\n";
          cout << "Game over.\n";
          return 0; //ends game
        }

      } else if (choices == "R" || choices == "r") //1st choice branch (right)
      {
        cout << "You received a map but you have no light to read it nor procceed ahead.\n";
        cin.get();
        cout << "You get lost in the darkness and taken, never to return\n";
        cin.get();
        cout << "The game is over, try again.";
      }
    }
    //path 2 start
    if (initialDivergence == "M" || initialDivergence == "m") {
      // dice role code

      srand(time(0));

      int randkey0, randkey1, randkey2, randkey3, randkey4, randkey5, randkey6, randkey7, randkey8;
      int count = 0;
      int d1 = rand() % 6 + 1;
      int d2 = rand() % 6 + 1;
      int p1 = rand() % 6 + 1;
      int p2 = rand() % 6 + 1;
      int d3 = rand() % 6 + 1;
      int d4 = rand() % 6 + 1;
      int p3 = rand() % 6 + 1;
      int p4 = rand() % 6 + 1;
      int d5 = rand() % 6 + 1;
      int d6 = rand() % 6 + 1;
      int p5 = rand() % 6 + 1;
      int p6 = rand() % 6 + 1;
      cout << "                                    ------------------------------------------------------------------------------" << endl;
      cout << "                                    * Welcome to the dice game!                                                  *" << endl;
      cout << "                                    * Throw your dice and hope that your total is greater than the dragons'.     *" << endl;
      cout << "                                    * To win this game get a bigger total than dragon for the majority of times. *" << endl;
      cout << "                                    ------------------------------------------------------------------------------" << endl << endl;
      cout << "Press any numkey and press enter to start";
      cin >> randkey0;
      if (cin.fail()) {
        cout << "You broke the game." << endl;
        return 0;
      }
      cout << endl;
      cout << "* Round 1 *" << endl << endl;

      do {
        cout << "The dragon got: " << d1 << " and " << d2 << endl;
        cout << "Dragon's dice total = " << d1 + d2 << endl << endl;
        cout << "It's your turn! press any key and enter to throw your dice." << endl;
        cin >> randkey1;
        cout << endl;
        cout << "You got: " << p1 << " and " << p2 << endl;
        cout << "Your dice total = " << p1 + p2 << endl << endl;
        if ((p1 + p2) == (d1 + d2)) {
          cout << "You and the dragon have got the same result from the dice roll." << endl << endl;
          cout << "Press any key and enter to restart this round." << endl;
          cin >> randkey2;
        }
      }
      while ((p1 + p2) == (d1 + d2));
      if (cin.fail()) {
        cout << "You broke the game." << endl;
        return 0;
      }
      if ((p1 + p2) > (d1 + d2)) //if player wins the first round.
      {
        cout << "Your dice total is greater than dragons'!" << endl;
        cout << "Congratulations, you have won this round!" << endl << endl;
      }
      if ((p1 + p2) < (d1 + d2)) //if player loses the first round.
      {
        cout << "Your dice total is lower than dragons'..." << endl;
        cout << "Good luck for the next round." << endl << endl;
      }

      cout << "Press any key and enter to enter Round 2." << endl; //start of round 2
      cin >> randkey3;
      if (cin.fail()) {
        cout << "You broke the game." << endl;
        return 0;
      }
        cout << endl;
        cout << "* Round 2 *" << endl << endl;

        do {
          cout << "The dragon got: " << d3 << " and " << d4 << endl;
          cout << "Dragon's dice total = " << d3 + d4 << endl << endl;
          cout << "It's your turn! press any key and enter to throw your dice." << endl;
          cin >> randkey4;
          cout << endl;
          cout << "You got: " << p3 << " and " << p4 << endl;
          cout << "Your dice total = " << p3 + p4 << endl << endl;

          if ((p3 + p4) == (d3 + d4)) {
            cout << "You and the dragon have got the same result from the dice roll." << endl << endl;
            cout << "Press any key and enter to restart this round." << endl;
            cin >> randkey5;
            cout << endl;
          }
        }
        while ((p3 + p4) == (d3 + d4));
        if (cin.fail()) {
          cout << "You broke the game." << endl;
          return 0;
        }

          if (((p3 + p4) > (d3 + d4)) && ((p1 + p2) < (d1 + d2))) //if player won second round and lost first round
          {
            cout << "Your dice total is greater than dragons'!" << endl;
            cout << "Congratulation, you have won this round!" << endl << endl;
          }
          if (((p3 + p4) < (d3 + d4)) && ((p1 + p2) > (d1 + d2))) //is player lost second round and won first round
          {
            cout << "Your dice total is lower than dragons'..." << endl;
            cout << "Good luck for the next round." << endl << endl;
          }

          if (((p1 + p2) > (d1 + d2)) && ((p3 + p4) > (d3 + d4))) //if player wins the first and second rounds.
          {
            cout << "YOU WON AGAIN!!!" << endl;
            cout << "Congratulation, you have beaten the dragon." << endl << endl;
            cout << "With your luck and confidence, you have saved the planet." << endl;
            cout << "The dragon spares humanity and flies away into the darkness." << endl;
          }

          if (((p1 + p2) < (d1 + d2)) && ((p3 + p4) < (d3 + d4))) //if player loses the first and second rounds.
          {
            cout << "The dragon won two times in a row." << endl;
            cout << "The dragon whoops you with its spiky tail and you drop stunned onto the ground beneath you." << endl;
            cout << "The dragon, with all its power, punches the ground cause earthquakes all around you." << endl;
            cout << "* YOU ARE DEAD   GAME OVER *" << endl;
          }

          if (((p1 + p2) > (d1 + d2)) && ((p3 + p4) < (d3 + d4)) || ((p3 + p4) > (d3 + d4)) && (p1 + p2) < (d3 + d4)) //if player won first round and lost second round or player won second round and lost first round.
          {
            cout << "Press any key and enter to enter Round 3." << endl; //start of round 3
            cin >> randkey6;
            cout << endl;
            cout << "* Round 3 *" << endl << endl;

            do {
              cout << "The dragon got: " << d5 << " and " << d6 << endl;
              cout << "Dragon's dice total = " << d5 + d6 << endl << endl;
              cout << "It's your turn! press any key and enter to throw your dice." << endl;
              cin >> randkey7;
              cout << endl;
              cout << "You got: " << p5 << " and " << p6 << endl;
              cout << "Your dice total = " << p5 + p6 << endl << endl;

              if ((p5 + p6) == (d5 + d6)) {
                cout << "You and the dragon have got the same result from the dice roll." << endl << endl;
                cout << "Press any key and enter to restart this round." << endl;
                cin >> randkey8;
                cout << endl;
              }
            }
            while ((p5 + p6) == (d5 + d6));

            if (((p5 + p6) > (d5 + d6)) && ((p1 + p2) > (d1 + d2)) || ((p5 + p6) > (d5 + d6) && (p3 + p4) > (d3 + d4))) //if player won in 3rd round and 1st round or player won in 3rd round and 2nd round. Player wins.
            {
              cout << "YOU WON AGAIN!!!" << endl;
              cout << "Congratulation, you have beaten the dragon." << endl << endl;
              cout << "With your luck and confidence, you have saved the planet." << endl;
              cout << "The dragon spares humanity and flies away into the darkness." << endl;
            } else //if player lost in 3rd round and 1st round or player lost in 3rd round and 2nd round. Player loses.
            {
              cout << "The dragon won two times in a row." << endl;
              cout << "The dragon whoops you with its spiky tail and you drop stunned onto the ground beneath you." << endl;
              cout << "The dragon, with all its power, punches the ground cause earthquakes all around you." << endl;
              cout << "* YOU ARE DEAD   GAME OVER *" << endl;
            }
          }

        }
        // PATH 3
        if (initialDivergence == "R" || initialDivergence == "r") { // path3 start
          int round1Input;
          round2Input = 1;
          int round3Input;
          status = false;
          key = false;
          string options; // variable declarations and needed values reset
          cout << "You find yourself in a cave with multiple chests near you.\n";
          cin.get();
          cout << "In front of you is a gate that you tried to open but seems locked.\n";
          cin.get();
          cout << "You search the chests and find a key in one of the chest.\n";
          cin.get();
          //Round 1
          cout << "You unlock a gate and as you step forward, you find yourself surrounded by locked prison cells.\n";
          cin.get();
          cout << "In front of you is the prison warden sitting in front of his desk and also asleep.\n";
          cin.get();
          cout << "Straight Behind him is another cave with an open prison cell!!!.\n";
          cin.get();
          cout << "WHAT WILL YOU DO ?\n";
          cin.get();
          cout << "You have 2 options.\n";
          cin.get();
          cout << "OPTION 1.\n";
          cin.get();
          cout << "Attack the prison warden while he is asleep.\n";
          cin.get();
          cout << "OR OPTION 2.\n";
          cin.get();
          cout << "Try to sneak past him.\n";
          cin.get();
          cout << "You must select 1 for OPTION 1 and 2 for OPTION 2.\n";
          cin >> options;
          while (options != "1" && options != "2") { // checking for invalid input
            cout << "Only select 1 or 2 as a response.\n";
            cin >> options;
          }
          if (options == "1") { //first if statement wrong choice
            cout << "The warden will wake up and capture you in a cell. Nice Try!\n";
          } else if (options == "2") { //first if statement right choice
            cout << "You will successfully sneak into the open prison cell that leads to a tunnel.\n";
            cin.get();
            //Round 2
            cout << "After wandering in the tunnel you find an exit that leads to a dinning hall.\n";
            cin.get();
            cout << "Before exiting you notice some human bones in the floor.\n";
            cin.get();
            cout << "Something feels off but then the smell of the food distracts you. It seems like there is no one around, and the tunnel keeps going into the darkness.\n";
            cin.get();
            cout << " WHAT WILL YOU DO ?\n";
            cin.get();
            cout << "Option 1\n";
            cin.get();
            cout << "Proceed and eat the feast on the table.\n";
            cin.get();
            cout << "Or option 2\n";
            cin.get();
            cout << "Keep going deeper into the dark tunnel.\n";
            cin.get();
            cout << "You must select 1 for OPTION 1 and 2 for OPTION 2.";
            cin >> options;
            while (options != "1" & options != "2") { //invalid input check
              cout << "Only select 1 or 2 as a response.\n";
              cin >> options;
            }
            if (options == "1") { //second if statement wrong choice
              cout << "You successfully fill your belly with the feast that was on the table. However, as you escape into the tunnel  you black out because the food was poisoned. Before you die you realize why the bones were there.\n";
            } else if (options == "2") { //second if statement right choice
              cout << "You have resisted the delicious smell of the food and keep going into the darkness of the cave.\n";
              cin.get();
              //Round 3
              cout << "As you follow the path in the dark cave, you have reached a dead end.\n";
              cin.get();
              cout << "There are 2 Giant doors, one on the left and one on the right.\n";
              cin.get();
              cout << "The door you choose will only unlock if you guess the RIDDLE.\n";
              cin.get();
              cout << "ARE YOU READY ?\n";
              cin.get();
              cout << "Option 1\n";
              cin.get();
              cout << "You choose the right door and must answer the next riddle. What does a liar do when he's dead?\n";
              cin.get();
              cout << "Or option 2\n";
              cin.get();
              cout << "You choose the left door and must answer the next riddle. What can fly but has no wings?\n";
              cin.get();
              cout << "You must select 1 for OPTION 1 and 2 for OPTION 2.";
              cin >> options;
              cin.ignore();
              if (options == "1") { //riddle 1
                cout << "What does a liar do when he's dead?\n ";
                cout << "Please input your answer.\n";
                cout << "Hint: it is two words\n";
                getline(cin, riddleAnswer);
                if (riddleAnswer == "lie still" || riddleAnswer == "Lie still") { //correct answer
                  cout << "YOU MADE IT, CELEBRATE YOUR FREEDOM !\n";
                } else { // incorrect answer
                  cout << "Another Hint: Dont lie to yourself.\n";
                  cout << "Come back when you\'re ready.\n";
                  return 0;
                }
              } else if (options == "2") { //riddle 2
                cout << "What can fly but has no wings?\n";
                cout << "Please input your answer.\n";
                cout << "Hint: Manage 1 word wisely !\n";
                getline(cin, riddleAnswer);
                if (riddleAnswer == "time" || riddleAnswer == "Time") { //right answer
                  cout << "FEEL PROUD TO PASS THE CHALLENGE, CELEBRATE WITH FREEDOM !\n";
                } else { //wrong answer
                  cout << "1 More Hint: You look at me when you wake up everyday....\n";
                  cout << "Come back when you\'re ready...\n";
                  return 0;
                }
              } else {
                cout << "Choose a valid option next time." << endl;
                cout << "You rot away as you can't escape this hellish dungeon." << endl;
                cout << "The game is over.";
              }
            }
          }
        }
      }
      cout << endl;
      return 0;
    }
