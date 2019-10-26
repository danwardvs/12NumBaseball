/**
 * Key Listener 2 (allegro 5!)
 *   Allan Legemaate
 * Listens for keys JUST pressed or JUST released
 *   since the last tick
 * 18/01/2017
**/

#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include <iostream>
#include <allegro5/allegro.h>

class keyListener {
  public:
    static bool anyKeyPressed;

    static void on_event(ALLEGRO_EVENT_TYPE event_type, int keycode);
    static void update();

    static bool key[ALLEGRO_KEY_MAX];
    static bool keyPressed[ALLEGRO_KEY_MAX];
    static bool keyReleased[ALLEGRO_KEY_MAX];
    static bool numKeyPressed;
    static bool numKeyReleased;

    static int lastKeyPressed;
    static int lastKeyReleased;
    static int currentKeyPressed;

  private:
    static bool lastTicksKey[ALLEGRO_KEY_MAX];
};

#endif // KEYLISTENER_H
