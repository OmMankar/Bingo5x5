#include <algorithm> // shuffle
#include <array>     // array
#include <chrono>
#include<iostream>
#include <iomanip>
#include <iostream> // cout
#include <random>   // default_random_engine

using namespace std;

class Bingo
{
private:
  string Name;      //_name;
  int ticket[5][5]; // 5x5 2-D matrix
  vector<char> _striekMatch = {'B', 'I', 'N', 'G', 'O'};
  int key = 0; // user will enter this one by one to achieve Bingo.

public:
  void SetName(string name);
  string GetName();
  void SetKey(int key);
  int GetKey();
  void TicketGeneration();        // Ticket is generated.
  void Current_view();            // To provide the view of the ticket so that we can select appropriate key.
  bool ValidKeyCheck(int number); // key which is chosen should lie between 1 and 25.
  bool checkbingo();              // use to keep a track wether someone has completed bingo.
  void update_Bingo();            // once a key is selcted then we cancel that number from our ticket.
  void checkRow(int &_streikMatchCount,int RowIndex); // check wether all the numbers in a row  are selected or not
  void checkColumn(int &_streikMatchCount,int ColumnIndex);//// check wether all the numbers in a column are selected or not
  void checkDiagonal1(int &_streikMatchCount);// check wether all the numbers in a diagonal are selected or not
  void checkDiagonal2(int &_streikMatchCount);// check wether all the numbers in a diagonal are selected or not
};

void Bingo::SetName(string name)
{
  Name = name;
};
string Bingo::GetName()
{
  return Name;
};
void Bingo::SetKey(int _key)
{
  key = _key;
};
int Bingo::GetKey()
{
  return key;
};
bool Bingo::ValidKeyCheck(int number)
{
  if (number < 0 || number > 25)
  {
    return false;
  }
  return true;
}
void Bingo::TicketGeneration()
{

#if 0
                              cout<<Name<<" Enter Numbers"<<endl;
                              for(int i=0;i<5;i++){
                                for(int j=0;j<5;j++){
                                  cin>>ticket[i][j];
                                }
                              }
#else
  cout << endl;
  cout << endl;
  cout << "Generated ticket of Player : " << Name << endl;
  array<int, 25> foo{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                     14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

  // obtain a time-based seed:
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  shuffle(foo.begin(), foo.end(), default_random_engine(seed));

  int ctr = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      ticket[i][j] = foo[ctr++];
    }
  }
#endif
}
void Bingo::checkRow(int &_streikMatchCount,int Row_index)
{
  if (_streikMatchCount < 5 && ticket[Row_index][0] == 0 && ticket[Row_index][1] == 0 && ticket[Row_index][2] == 0 & ticket[Row_index][3] == 0 && ticket[Row_index][4] == 0)
  {
    _streikMatchCount++;
  }
}
void Bingo::checkColumn(int &_streikMatchCount,int Column_index)
{
  if (_streikMatchCount < 5 && ticket[0][Column_index] == 0 && ticket[1][Column_index] == 0 && ticket[2][Column_index] == 0 & ticket[3][Column_index] == 0 && ticket[4][Column_index] == 0)
  {
    _streikMatchCount++;
  }
}
void Bingo::checkDiagonal1(int &_streikMatchCount)
{
  if (_streikMatchCount < 5 && (ticket[0][0] == 0 && ticket[1][1] == 0 && ticket[2][2] == 0 && ticket[3][3] == 0 && ticket[4][4] == 0)){
    _streikMatchCount++;
  }
}
void Bingo::checkDiagonal2(int &_streikMatchCount)
{
  if (_streikMatchCount < 5 && (ticket[0][4] == 0 && ticket[1][3] == 0 && ticket[2][2] == 0 && ticket[3][1] == 0 && ticket[4][0] == 0)){
    _streikMatchCount++;
  }
}
bool Bingo::checkbingo()
{

  int _streikMatchCount = 0;

 
    
      for(int Index=0;Index<5;Index++){
      checkColumn(_streikMatchCount, Index);
      checkRow(_streikMatchCount, Index);}
 
  
  
  checkDiagonal1(_streikMatchCount);
  checkDiagonal2(_streikMatchCount);

  for (int i = 0; i < _streikMatchCount; i++){
    _striekMatch[i] = '*';
  }

  if (_streikMatchCount == 5){
    return true;
  }
  return false;
}
void Bingo ::Current_view()
{
  cout << endl;
  cout << Name << "'s  Ticket" << endl;
  cout << endl;
  cout << _striekMatch[0] << "   " << _striekMatch[1] << "   " << _striekMatch[2] << "   " << _striekMatch[3] << "   " << _striekMatch[4] << "          ";
  cout << endl;

  for (int i = 0; i < 5; i++)
  {
    cout << endl;
    cout << endl;
    cout << setw(2) << ticket[i][0] << "   " << setw(2) << ticket[i][1] << "   " << setw(2) << ticket[i][2] << "   " << setw(2) << ticket[i][3] << "   " << setw(2) << ticket[i][4] << "          ";
    cout << endl;
  }
  cout << endl;
  cout << endl;
}
void Bingo ::update_Bingo()
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (ticket[i][j] == GetKey())
      {
        ticket[i][j] = 0;
        break;
      }
    }
  }
}
int main()
{

  cout << "WELCOME TO THE BINGO GAME :) :)" << endl;

  Bingo Player1, Player2;
  cout << "Enter First Player Name" << endl; // Taking name as input from player1
  string name;
  cin >> name;
  Player1.SetName(name);

  cout << "Enter Second Player Name" << endl; // Taking name as input from player2
  cin >> name;
  Player2.SetName(name);

  Player1.TicketGeneration(); // Generate ticket for Player1
  Player1.Current_view();

  Player2.TicketGeneration(); // Generate ticket for Player2
  Player2.Current_view();

  while (1)
  { // infinte wihle loop until any one of the player completes the bingo.

    // Player1 giving choosing a Number from the ticket.
    int number;
    cout << Player1.GetName() << " Choose a number from your ticket" << endl;
    cin >> number;

    if (Player1.ValidKeyCheck(number))
    { // checking if the number given is less than 26

      Player1.SetKey(number);
      Player1.update_Bingo(); // Finding the Input Number inside the ticket.
      Player2.SetKey(Player1.GetKey());
      Player2.update_Bingo();
      Player1.checkbingo();
      Player2.checkbingo();
      Player1.Current_view();
      Player2.Current_view();
    }
    else
    {
      cout << Player1.GetName() << " You have entered Incorrect NUMBER" << endl; // A number not in ticket is given as input.
    }

    if (Player1.checkbingo() == true || Player2.checkbingo() == true)
    { // to stop the while loop as one of them or both have complete a bingo.
      break;
    }
    // Player1 giving choosing a Number from the ticket.

    cout << Player2.GetName() << " Choose a number from your ticket" << endl;
    cin >> number;

    if (Player2.ValidKeyCheck(number))
    { // checking if the number given is less than 26

      Player2.SetKey(number);
      Player2.update_Bingo(); // Finding the Input Number inside the ticket.
      Player1.SetKey(Player2.GetKey());
      Player1.update_Bingo();
      Player2.checkbingo();
      Player1.checkbingo();
      Player1.Current_view();
      Player2.Current_view();
    }

    else
    {
      cout << Player2.GetName() << " You have entered Incorrect NUMBER" << endl; // A number not in ticket is given as input.
    }
    if (Player1.checkbingo() == true || Player2.checkbingo() == true)
    { // to stop the while loop as one of them or both have complete a bingo.
      break;
    }
  }

  if (Player1.checkbingo() == true && Player2.checkbingo() == true)
  { // when both the player complete the bingo at the same time.
    cout << "DRAW";
  }
  else if (Player1.checkbingo() == true && Player2.checkbingo() == false)
  { // when player1 complete the bingo first.
    cout << Player1.GetName() << " is the winner .";
  }
  else
  {
    cout << Player2.GetName() << " is the winner .";
  }

  return 0;
}
