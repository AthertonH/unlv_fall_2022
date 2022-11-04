#include <iostream>

using namespace std;
void playerTurn(int);
void computerTurn(int);

void anotherRound()
{
    int n=21;
    char response;
    cout<<"The game of Nim. The player to remove the last match loses"<<endl;
    cout<<"Would you like to go first ? (Y/N) :";
    cin>>response;
    if(response=='Y'||response=='y')
    {
        playerTurn(n);
    }
    else
    {
        computerTurn(n);
    } 
}

void playerTurn(int n)
{  int match;
   cout<<"\nPlayer Turn - Matches: "<<n<<endl;
   cout<<"Remove (1-3) :";
   cin>>match;
   n=n-match;
   if(n==0)
   {
       cout<<"\nComputer Won the game\n Do you want to play again ? (Y/N)";
       char response;
           cin>>response;
    if(response=='Y'||response=='y')
    {
       anotherRound();
    }
    else
    {
        exit(0);
    }
   }
   computerTurn(n);
}

void computerTurn(int n)
{
  cout<<"\nComputer Turn - Matches: "<<n<<endl; 
  int match;
  if(n%4==2)
  {
      match=1;
  }
  else if(n%4==3)
  {
      match=2;
  }
  else if(n%4==0)
  {
      match=3;
  }
  else
  {
      match=1;
  }
  n=n-match;
  cout<<"Computer Removes "<<match<<endl;
  if(n==0)
   {
       cout<<"\nPlayer Won the game\n Do you want to play again ? (Y/N)";
       char response;
       cin>>response;
    if(response=='Y'||response=='y')
    {
        anotherRound(); 
    }
    else
    {
        exit(0);
    }
   }
   playerTurn(n);
}

int main()
{
    anotherRound();
    return 0;
}