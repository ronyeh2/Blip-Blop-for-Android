#include "main.h"
#include "SDL.h"


int main(int argc, char **argv)
{
    // Must be set before SDL_Init (graphics.cpp).
    // - BACK (TV remote, phone) is delivered to the game as SDLK_AC_BACK
    //   instead of finishing the activity: it opens the pause menu / goes back.
    // - The accelerometer is not a joystick, TV remotes are plain keys
    //   (arrows / SELECT / BACK) and real gamepads are SDL game controllers.
    SDL_SetHint(SDL_HINT_ANDROID_TRAP_BACK_BUTTON, "1");
    SDL_SetHint(SDL_HINT_ACCELEROMETER_AS_JOYSTICK, "0");
    SDL_SetHint(SDL_HINT_TV_REMOTE_AS_JOYSTICK, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "0");

    if (!InitApp(0, 0))
        return 1;

    game.go();

    // "EXIT" in the main menu: returning ends the activity (Smartblip
    // then ends the process so a relaunch starts from a clean state).
    return 0;
}
