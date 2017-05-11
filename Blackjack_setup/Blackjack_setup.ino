#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //LiquidCrystal(rs, enable, d4, d5, d6, d7)
int button_down    = 8;
int button_confirm = 9;
int button_up      = 10;
int button_hit     = 11;

char Deck[4][52] = {
  {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, //value
  {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'}, //print value
  {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'}, //print suit
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} //used
};

int Player[4];
int Player_ace_count = 0;
int Player_value_sum = 0;
int Player_card_count = 0;
int CPU[4];
int CPU_ace_count = 0;
int CPU_card_count = 0;
int CPU_value_sum = 0;

int ALL = 100; //sum cash
int BetAmount[5]  =   {0, 25, 50, 100, ALL};
int Cardsdrawn = 0;
int game_progress = 0;
int Bet_picked = 0;
unsigned long currenttime = 0;
unsigned long previoustime = 0;
unsigned long switchtimer = 0;
bool new_game = 1;


void setup() {
  pinMode(button_down, INPUT);
  pinMode(button_confirm, INPUT);
  pinMode(button_up, INPUT);
  pinMode(button_hit, INPUT);

  randomSeed(analogRead(2) + analogRead(0));

  empty_hands();

  Serial.begin(9600);
  Serial.println("start_game");

  lcd.begin(16, 2);
  lcd.display();
  lcd.noAutoscroll();
  lcd.setCursor(0, 0);
  lcd.print("Velkommen til");
  lcd.setCursor(0, 1);
  lcd.print("Blackjack");
  delay(1000);
}
