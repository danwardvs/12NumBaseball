/*
 * Main
 * This is the main for 12 Num Baseball
 * Calls state machine update and draw functions
 * 2017/11/14
 */
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "init.h"
#include "state.h"
#include "menu.h"

#include "input/mouseListener.h"
#include "input/keyListener.h"
#include "input/joystickListener.h"

#include "helpers/loaders.h"

#include "constants/colors.h"
#include "constants/screen.h"

// Current state object
state* currentState = nullptr;

// FPS system variables
int fps;
double old_time = 0;
const float MAX_FPS = 60;
int frames_array[100];
int frame_index = 0;

// Closing or naw
bool closing = false;
bool joystick_enabled = false;

// Allegro events
ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
ALLEGRO_TIMER* timer = nullptr;
ALLEGRO_DISPLAY* display = nullptr;
ALLEGRO_BITMAP* gameBuffer;

// Change game screen
void change_state() {
  //If the state needs to be changed
  if(nextState != STATE_NULL) {
    //Delete the current state
    if(nextState != STATE_EXIT) {
      delete currentState;
    }

    //Change the state
    switch(nextState) {
      case STATE_INIT:
        currentState = new init();
        std::cout << "Switched state to initialization.\n";
        break;

      case STATE_MENU:
        currentState = new menu();
        std::cout << "Switched state to main menu.\n";
        break;

      case STATE_EXIT:
        std::cout << "Exiting program.\n";
        closing = true;
        break;

      default:
        currentState = new menu();
    }

    //Change the current state ID
    stateID = nextState;

    //NULL the next state ID
    nextState = STATE_NULL;
  }
}

// Setup game
void setup() {

  std::cout << "Initializing Allegro.";

  // Init allegro
  if(!al_init())
    helpers::loaders::abort_on_error("Allegro could not initilize", "Error");

  // Window title
  al_set_window_title(display, "Loading...");

  // Controls
  al_install_keyboard();
  al_install_mouse();
  al_install_joystick();

  // GFX addons
  al_init_image_addon();
  al_init_primitives_addon();

  // Font
  al_init_ttf_addon();

  // Aquire screen
  al_set_new_display_flags(ALLEGRO_WINDOWED);
  display = al_create_display(constants::screen::WIDTH, constants::screen::HEIGHT);

  if(!display) {
    helpers::loaders::abort_on_error("Screen could not be created", "Error");
  }

  // Timer
  timer = al_create_timer(1.0 / MAX_FPS);

  // Register events
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_joystick_event_source());

  // Timer
  al_start_timer(timer);

  // Window title
  al_set_window_title(display, "12 Number Baseball");

  std::cout << " Sucesss." << std::endl;

  // Probably never going to be relevant but pretty cool anyways
  uint32_t version = al_get_allegro_version();
  int major = version >> 24;
  int minor = (version >> 16) & 255;
  int revision = (version >> 8) & 255;
  int release = version & 255;

  std::cout << "Allegro version " << major << "." << minor << "." << revision << "." << release << std::endl;

  // This is actually completely irrelevant other than making fun of Allan's PC when he runs this
  // Sorry, your PC is a very nice PC
  // mfw Allan's PC is now superior
  std::cout << "Running as " << al_get_app_name() << ", with " << al_get_ram_size() << " MB RAM." << std::endl;
}

// Handle events
void update() {
  // Event checking
  ALLEGRO_EVENT ev;
  al_wait_for_event(event_queue, &ev);

  switch(ev.type)  {
    // Timer
    case ALLEGRO_EVENT_TIMER:
      // Change state (if needed)
      change_state();

      // Update listeners
      mouseListener::update();
      keyListener::update();
      joystickListener::update();

      // Update state
      currentState -> update();
      break;

    // Exit
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      closing = true;
      break;

    // Keyboard
    case ALLEGRO_EVENT_KEY_DOWN:
    case ALLEGRO_EVENT_KEY_UP:
      keyListener::on_event(ev.type, ev.keyboard.keycode);
      break;

    // Joystick
    case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
    case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
      joystickListener::on_event(ev.type, ev.joystick.button);
      break;

    // Joystick plugged or unplugged
    case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
      al_reconfigure_joysticks();
      joystick_enabled = (al_get_num_joysticks() > 0);
      break;

    // Other
    default:
      break;
  }

  // Drawing
  if(al_is_event_queue_empty(event_queue)) {
    // Clear buffer
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw state graphics
    currentState -> draw();

    // Flip (OpenGL)
    al_flip_display();

    // Update fps buffer
    for(int i = 99; i > 0; i--)
      frames_array[i] = frames_array[i - 1];

    frames_array[0] = (1.0 / (al_get_time() - old_time));
    old_time = al_get_time();

    int fps_total = 0;

    for(int i = 0; i < 100; i++)
      fps_total += frames_array[i];

    // FPS = average
    fps = fps_total / 100;
  }
}

// Start here
int main() {
  // Basic init
  setup();

  // Set the current state ID
  stateID = STATE_INIT;
  currentState = new init();

  // Run game
  while(!closing)
    update();

  // Destory display
  al_destroy_display(display);

  return 0;
}
