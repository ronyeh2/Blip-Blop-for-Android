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
}
