package com.blip.blop;

import org.libsdl.app.SDLActivity;

public class Smartblip extends SDLActivity
{
    @Override
    protected String[] getLibraries() {
        return new String[] {
            "SDL2",
            "SDL2_mixer",
            "main"
        };
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // The C++ game keeps all of its state in globals and cannot be
        // started twice in the same process. When the activity really goes
        // away (EXIT in the menu, swiped from recents), end the process so the
        // next launch starts clean.
        if (isFinishing()) {
            System.exit(0);
        }
    }
}
