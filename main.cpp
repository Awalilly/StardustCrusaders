#include "Game.cpp"

int main(){


    game match;

    match.PrintMenu();

    match.SetGameMode();


    match.WhoStarts();

    match.Play();

    match.PrintWinnerScreen();


}
