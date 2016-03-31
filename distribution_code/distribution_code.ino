#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;

// global constant for the number of Invaders in the game
const int NUM_ENEMIES = 16;

// a global variable that represents the LED screen
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// the following functions are for printing messages
void print_level(int level);
void print_lives(int lives);
void game_over();

class Color {
  public:
    int red;
    int green;
    int blue;
    Color() {
      red = 0;
      green = 0;
      blue = 0;
    }
    Color(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }
    uint16_t to_333() const {
      return matrix.Color333(red, green, blue);
    }
};

const Color BLACK(0, 0, 0);
const Color RED(7, 0, 0);
const Color ORANGE(7, 4, 0);
const Color YELLOW(7, 7, 0);
const Color GREEN(0, 7, 0);
const Color BLUE(0, 0, 7);
const Color PURPLE(7, 0, 7);
const Color WHITE(7, 7, 7);
const Color LIME(4, 7, 0);
const Color AQUA(0, 7, 7);

class Invader {
  public:
    // Constructors
    Invader() {
      x = 0;
      y = 0;
      strength = 0;
    }
    // sets values for private date members x and y
    Invader(int x_arg, int y_arg) {
    }
    // sets values for private data members
    Invader(int x_arg, int y_arg, int strength_arg) {
    }
    // sets values for private data members
    void initialize(int x_arg, int y_arg, int strength_arg) {
    }
    
    // getters
    int get_x() const {
    }
    int get_y() const {
    }
    int get_strength() const {
    }

    // Moves the Invader down the screen by one row
    // Modifies: y
    void move() {
    }
    
    // draws the Invader if its strength is greater than 0
    // calls: draw_with_rgb
    void draw() {
    }
    
    // draws black where the Invader used to be
    // calls: draw_with_rgb
    void erase() {
    }    
    
    // Invader is hit by a Cannonball.
    // Modifies: strength
    // calls: draw, erase
    void hit() {
    }

  private:
    int x;
    int y;
    int strength;
    
    // draws the Invader
    void draw_with_rgb(Color body_color, Color eye_color) {
    }
};

class Cannonball {
  public:
    Cannonball() {
      x = 0;
      y = 0;
      fired = false;
    }
    
    // resets private data members to initial values
    void reset() {
    }
    
    // getters
    int get_x() const {
    }
    int get_y() const {
    }
    bool has_been_fired() const {
    }
    
    // sets private data members
    void fire(int x_arg, int y_arg) {
    }
    
    // moves the Cannonball and detects if it goes off the screen
    // Modifies: y, fired
    void move() {
    }
    
    // resets private data members to initial values
    void hit() {
    }
    
    // draws the Cannonball, if it is fired
    void draw() {
    }
    
    // draws black where the Cannonball used to be
    void erase() {
    }

  private:
    int x;
    int y;
    bool fired;
};

class Player {
  public:
    Player() {
      x = 0;
      y = 0;
      lives = 3;
    }
    
    // getters
    int get_x() const {
    }
    int get_y() const {
    }
    int get_lives() const {
    }
    
    // setter
    void set_x(int x_arg) {
    }
    
    // Modifies: lives
    void die() {
    }
    
    // draws the Player
    // calls: draw_with_rgb
    void draw() {
    }
    
    // draws black where the Player used to be
    // calls: draw_with_rgb
    void erase() {
    }

  private:
    int x;
    int y;
    int lives;

    // sets private data members x and y to initial values
    void initialize(int x_arg, int y_arg) {
    }
    
    // draws the player
    void draw_with_rgb(Color color) {
    }
};

class Game {
  public:
    Game() {
      level = 0;
      time = 0;
    }
    
    // returns enemy at specified index, if in bounds
    Invader get_enemy(int index) {
    }
    
    // sets up a new game of Space Invaders
    // Modifies: global variable matrix
    // see http://arduino.cc/en/Reference/Setup
    void setup() {
    }
    
    // displays and runs Space Invaders!
    // see spec for details of game
    // Modifies: global variable matrix
    void loop(int potentiometer_value, bool button_pressed) {
    }

  private:
    int level;
    int time;
    Player player;
    Cannonball ball;
    Invader enemies[NUM_ENEMIES];

    // check if Player defeated all Invaders in current level
    bool level_cleared() {
    }

    // set up a level
    void reset_level() {
    }
};

// a global variable that represents the game Space Invaders
Game game;

// see http://arduino.cc/en/Reference/Setup
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  matrix.begin();

  // LETTER E
  matrix.drawPixel(26,15,GREEN.to_333());
  matrix.drawPixel(26,14,GREEN.to_333());
  matrix.drawPixel(26,13,GREEN.to_333());
  matrix.drawPixel(26,12,GREEN.to_333());
  matrix.drawPixel(26,11,GREEN.to_333());
  matrix.drawPixel(26,13,GREEN.to_333());
  

  matrix.drawPixel(25,15,GREEN.to_333());
  matrix.drawPixel(24,15,GREEN.to_333());

 
 

  matrix.drawPixel(25,13,GREEN.to_333());
  matrix.drawPixel(24,13,GREEN.to_333());

  matrix.drawPixel(25,11,GREEN.to_333());
  matrix.drawPixel(24,11,GREEN.to_333());

 
  
  // LETTER N 

  matrix.drawPixel(22,15,GREEN.to_333());
  matrix.drawPixel(22,14,GREEN.to_333());
  matrix.drawPixel(22,13,GREEN.to_333());
  matrix.drawPixel(22,12,GREEN.to_333());
  matrix.drawPixel(22,11,GREEN.to_333());
  matrix.drawPixel(21,14,GREEN.to_333());
  matrix.drawPixel(20,13,GREEN.to_333());
  matrix.drawPixel(18,13,GREEN.to_333());
  matrix.drawPixel(18,14,GREEN.to_333());
  matrix.drawPixel(19,12,GREEN.to_333());
  matrix.drawPixel(18,15,GREEN.to_333());
  matrix.drawPixel(18,12,GREEN.to_333());
  matrix.drawPixel(18,11,GREEN.to_333());

  //T

  matrix.drawPixel(16,15,GREEN.to_333());
  matrix.drawPixel(15,15,GREEN.to_333());
  matrix.drawPixel(14,15,GREEN.to_333());
  matrix.drawPixel(15,14,GREEN.to_333());
  matrix.drawPixel(15,13,GREEN.to_333());
  matrix.drawPixel(15,12,GREEN.to_333());
  matrix.drawPixel(15,11,GREEN.to_333());

  //E

  matrix.drawPixel(12,15,GREEN.to_333());
  matrix.drawPixel(12,14,GREEN.to_333());
  matrix.drawPixel(12,13,GREEN.to_333());
  matrix.drawPixel(12,12,GREEN.to_333());
  matrix.drawPixel(12,11,GREEN.to_333());
  matrix.drawPixel(12,13,GREEN.to_333());
  

  matrix.drawPixel(10,15,GREEN.to_333());
  matrix.drawPixel(11,15,GREEN.to_333());

 
 

  matrix.drawPixel(11,13,GREEN.to_333());
  matrix.drawPixel(10,13,GREEN.to_333());

  matrix.drawPixel(11,11,GREEN.to_333());
  matrix.drawPixel(10,11,GREEN.to_333());


  //R
  matrix.drawPixel(8,15,GREEN.to_333());
  matrix.drawPixel(8,14,GREEN.to_333());
  matrix.drawPixel(8,13,GREEN.to_333());
  matrix.drawPixel(8,12,GREEN.to_333());
  matrix.drawPixel(8,11,GREEN.to_333());
 

  matrix.drawPixel(7,15,GREEN.to_333());
  matrix.drawPixel(6,15,GREEN.to_333());
  matrix.drawPixel(6,14,GREEN.to_333());
  matrix.drawPixel(6,13,GREEN.to_333());
  matrix.drawPixel(7,13,GREEN.to_333());

  matrix.drawPixel(7,12,GREEN.to_333());
  matrix.drawPixel(6,11,GREEN.to_333());


//T
  matrix.drawPixel(20,9,GREEN.to_333());
  matrix.drawPixel(22,9,GREEN.to_333());
  matrix.drawPixel(21,9,GREEN.to_333());
  matrix.drawPixel(21,9,GREEN.to_333());
  matrix.drawPixel(21,8,GREEN.to_333());
  matrix.drawPixel(21,7,GREEN.to_333());
  matrix.drawPixel(21,6,GREEN.to_333());
  matrix.drawPixel(21,5,GREEN.to_333());

  //H
  matrix.drawPixel(19,9,GREEN.to_333());
  matrix.drawPixel(19,8,GREEN.to_333());
  matrix.drawPixel(19,7,GREEN.to_333());
  matrix.drawPixel(18,7,GREEN.to_333());
  matrix.drawPixel(17,7,GREEN.to_333());
  matrix.drawPixel(19,6,GREEN.to_333());
  matrix.drawPixel(19,5,GREEN.to_333());
  matrix.drawPixel(17,9,GREEN.to_333());
  matrix.drawPixel(17,8,GREEN.to_333());
  matrix.drawPixel(17,7,GREEN.to_333());
  matrix.drawPixel(17,6,GREEN.to_333());
  matrix.drawPixel(17,5,GREEN.to_333());

  //E

  matrix.drawPixel(15,9,GREEN.to_333());
  matrix.drawPixel(15,8,GREEN.to_333());
  matrix.drawPixel(15,7,GREEN.to_333());
  matrix.drawPixel(15,6,GREEN.to_333());
  matrix.drawPixel(15,5,GREEN.to_333());
  matrix.drawPixel(15,7,GREEN.to_333());
  

  matrix.drawPixel(14,9,GREEN.to_333());
  matrix.drawPixel(13,9,GREEN.to_333());

 
 

  matrix.drawPixel(14,7,GREEN.to_333());
  matrix.drawPixel(13,7,GREEN.to_333());

  matrix.drawPixel(14,5,GREEN.to_333());
  matrix.drawPixel(13,5,GREEN.to_333());

 //M

  matrix.drawPixel(29,3,GREEN.to_333());
  matrix.drawPixel(29,2,GREEN.to_333());
  matrix.drawPixel(28,2,GREEN.to_333());
  matrix.drawPixel(27,1,GREEN.to_333());
  matrix.drawPixel(26,2,GREEN.to_333());

  matrix.drawPixel(29,1,GREEN.to_333());
  matrix.drawPixel(29,0,GREEN.to_333());

  matrix.drawPixel(25,3,GREEN.to_333());
  matrix.drawPixel(25,2,GREEN.to_333());

  matrix.drawPixel(25,1,GREEN.to_333());
  matrix.drawPixel(25,0,GREEN.to_333());

  //A
  matrix.drawPixel(23,0,GREEN.to_333());
  matrix.drawPixel(23,1,GREEN.to_333());
  matrix.drawPixel(23,2,GREEN.to_333());
  matrix.drawPixel(23,3,GREEN.to_333());
  matrix.drawPixel(22,3,GREEN.to_333());
  matrix.drawPixel(21,3,GREEN.to_333());

  matrix.drawPixel(23,1,GREEN.to_333());
  matrix.drawPixel(22,1,GREEN.to_333());
  matrix.drawPixel(21,1,GREEN.to_333());


  matrix.drawPixel(21,3,GREEN.to_333());
  matrix.drawPixel(21,2,GREEN.to_333());

  matrix.drawPixel(21,1,GREEN.to_333());
  matrix.drawPixel(21, 0,GREEN.to_333());

//T

  matrix.drawPixel(19,3,GREEN.to_333());
  matrix.drawPixel(18,3,GREEN.to_333());
  matrix.drawPixel(17,3,GREEN.to_333());
  matrix.drawPixel(18,2,GREEN.to_333());
  matrix.drawPixel(18,1,GREEN.to_333());
  matrix.drawPixel(18,0,GREEN.to_333());

  //R

  matrix.drawPixel(15,3,GREEN.to_333());
  matrix.drawPixel(15,2,GREEN.to_333());
  matrix.drawPixel(15,1,GREEN.to_333());
  matrix.drawPixel(15,0,GREEN.to_333());
  
 

  matrix.drawPixel(14,3,GREEN.to_333());
  matrix.drawPixel(13,3,GREEN.to_333());
  matrix.drawPixel(13,2,GREEN.to_333());
  matrix.drawPixel(14,2,GREEN.to_333());
  matrix.drawPixel(13,0,GREEN.to_333());
  matrix.drawPixel(14,1,GREEN.to_333());

//I

 matrix.drawPixel(11,0,GREEN.to_333());
 matrix.drawPixel(11,1,GREEN.to_333());
 matrix.drawPixel(11,2,GREEN.to_333());
 matrix.drawPixel(11,3,GREEN.to_333());

 matrix.drawPixel(9,3,GREEN.to_333());
 matrix.drawPixel(8,2,GREEN.to_333());
 matrix.drawPixel(7,1,GREEN.to_333());
 matrix.drawPixel(6,0,GREEN.to_333());

 matrix.drawPixel(6,3,GREEN.to_333());
 matrix.drawPixel(7,2,GREEN.to_333());
 matrix.drawPixel(8,1,GREEN.to_333());
 matrix.drawPixel(9,0,GREEN.to_333());
  

}

// see http://arduino.cc/en/Reference/Loop
void loop() {
  int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);

  game.loop(potentiometer_value, button_pressed);
}

// displays Level
void print_level(int level) {
}

// displays number of lives
void print_lives(int lives) {
}

// displays "game over"
void game_over() {
}

