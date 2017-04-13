#include <ArduinoSTL.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //LiquidCrystal(rs, enable, d4, d5, d6, d7)
#define h   0
#define c   1
#define d   2
#define s   3
char Card[4][13] = {  {2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A"},
  {2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A"},
  {2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A"},
  {2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A"}
};
char Player[4]    = {0, 0, 0, 0};
char CPU[4]     = {0, 0, 0, 0};
int ALL       = 100; //sum cash
int BetAmount[5]  =   {000, 25, 50, 100, ALL};
int CardsLeftInDeck = 52;
int game_progress   = 0;
int button_down     = 6;
int button_confirm  = 7;
int button_up       = 8;
int button_hit      = 9;
int Bet_picked      = 0;
int previoustime    = 0;
int currenttime     = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("setup");
  Serial.print("start_game");
  lcd.begin(16, 2);
  lcd.display();
  lcd.noAutoscroll();
  lcd.setCursor(0, 0);
  lcd.print("Velkommen til");
  lcd.setCursor(0, 1);
  lcd.print("Blackjack");
  delay(3000);
}
void loop() {
  switch (game_progress) {
    case 0: {
        start_game();
      }
    case 10: {
        if (CardsLeftInDeck < 4) {
          game_over();
        }
        else
          new_hand();
        game_progress = 20;
      }
    case 20: {
        currenttime = millis();

        if (digitalRead(button_up) && currenttime > previoustime + 500) {
          Bet_picked++;
          previoustime = currenttime;
          if (Bet_picked == 5) {
            Bet_picked = 0;
          }
          Serial.print(Bet_picked);
          Update_bet();
        }
        if (digitalRead(button_down) && currenttime > previoustime + 500) {
          Bet_picked--;
          previoustime = currenttime;
          if (Bet_picked < 0) {
            Bet_picked = 4;
          }
          Serial.print(Bet_picked);
          Update_bet();

        }
        if (digitalRead(button_confirm) && currenttime > previoustime + 500) {
          previoustime = currenttime;
          place_bet();
        }
      }
    case 30: {

      }
  }
}
void start_game() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YOU");
  lcd.setCursor(12, 0);
  lcd.print("$");
  lcd.print(ALL);
  lcd.setCursor(0, 1);
  lcd.print("CPU");
  lcd.setCursor(9, 1);
  lcd.print("BET$");
  lcd.print(BetAmount[Bet_picked]);
  Card[0][0] = 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A";
  Card[1][0] = 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A";
  Card[2][0] = 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A";
  Card[3][0] = 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K", "A";
  game_progress = 10;
  return;
}

void Update_bet() {
  lcd.setCursor(13, 1);
  if (BetAmount[Bet_picked] < 100) {
    lcd.print(" ");
  }
  if (BetAmount[Bet_picked] < 10) {
    lcd.print("  ");
  }

  lcd.print(BetAmount[Bet_picked]);
  Serial.print("   ");
  Serial.println(BetAmount[Bet_picked]);
  return;
}
void place_bet() {
  if (BetAmount[Bet_picked] > ALL) {
  	return;
  }
  else if (BetAmount[Bet_picked] == 0) {
    game_progress = 10;
  }
  else {
    ALL = ALL - BetAmount[Bet_picked];
    game_progress = 30;
    lcd.setCursor(13, 0);
    if (ALL > 100){
    	lcd.print(" ");
    }
    if (ALL > 10){
    	lcd.print("  ");
    }
    lcd.print(ALL);
  return;
  }

}
void null_cards_drawn_display() {
  for (int y = 0; y >= 1; y++) {
    for (int x = 0; x >= 7; x++) {
      lcd.setCursor(x, y);
      lcd.print(" ");
    }
  }
  return;
}
void game_over() {
  while (1) {
    lcd.setCursor(0, 0);
    lcd.print("Game over");
    lcd.setCursor(0, 1);
    lcd.print("$ left ");
    lcd.print(ALL);
  }
}
