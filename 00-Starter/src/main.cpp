#include "Game.h"

int main()
{
  
    Game my_game_{};

    my_game_.Init();

    my_game_.Game_Loop();

    return 0;
}