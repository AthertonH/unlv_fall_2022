void newGame()
{
  char newGameChoice = 'a';
  while (true) {
    while (true) {
      cin >> newGameChoice;
      newGameChoice = toupper(newGameChoice);
      if (newGameChoice != 'X' && newGameChoice != 'N') {
        // Wrong input print error message
      } else {
        break;
      }
    }
    if (newGameChoice == 'X') {
      return;
    }
    game('a', 'a');
  }
}