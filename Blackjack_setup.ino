#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //LiquidCrystal(rs, enable, d4, d5, d6, d7)
byte button_down    = 8;
byte button_confirm = 9;
byte button_up      = 10;
byte button_hit     = 11;
#define H 0
#define C 1
#define D 2
#define S 3
#define X 10
#define J 10
#define Q 10
#define K 10
#define A 11

//test change
char value [13] = {2, 3, 4, 5, 6, 7, 8, 9, "X", "J", "Q", "K", "A"};
char* suits [4] = {"H", "C", "D", "S"};
char Cards[52];
char Player[4];
byte Player_ace_count = 0;
byte Player_card_count = 0;
char CPU[4];
byte CPU_ace_count = 0;
byte CPU_card_count = 0;


int ALL       = 100; //sum cash
byte BetAmount[5]  =   {0, 25, 50, 100, ALL};
byte Cardsdrawn = 0;
byte game_progress   = 0;
bool buttonstate    = 0;
byte Bet_picked      = 0;
unsigned long currenttime     = 0;
unsigned long previoustime     = 0;
unsigned long switchtimer     = 0;
bool new_game = 1;


void setup() {
  for (int null_player; null_player <= 3; null_player++) {
    Player[null_player] = 0;
  }
  for (int null_cpu = 0; null_cpu <= 3; null_cpu++) {
    CPU[null_cpu] = 0;
  }
  pinMode(button_down, INPUT);
  pinMode(button_confirm, INPUT);
  pinMode(button_up, INPUT);
  pinMode(button_hit, INPUT);


  Serial.begin(9600);
  Serial.println("start_game");

  lcd.begin(16, 2);
  lcd.display();
  lcd.noAutoscroll();
  lcd.setCursor(0, 0);
  lcd.print("Velkommen til");
  lcd.setCursor(0, 1);
  lcd.print("Blackjack");
  delay(3000);
}
