void loop() {
  currenttime = millis();

  if ((digitalRead(button_up) || digitalRead(button_down) || digitalRead(button_confirm)) && (currenttime > switchtimer + 200) || new_game )
  {
    new_game = 0;
    switchtimer = currenttime;  
    
    switch (game_progress) {
      case 0: {
          start_game();
        }
      case 10: {
          Serial.println(Cardsdrawn);
          if (ALL < 25){
            game_over();
          }
          if (Cardsdrawn > 48) {
            game_over();
          }
          
          else
            new_hand();
          game_progress = 20;
        }
      case 20: {
          if (digitalRead(button_up)) {
            Bet_picked++;
          
            if (Bet_picked == 5) {
              Bet_picked = 0;
            }
            Serial.print(Bet_picked);
            Update_bet();
          }

          if (digitalRead(button_down)) {
            Bet_picked--;
            if (Bet_picked == 255) {
              Bet_picked = 4;
            }
            Serial.print(Bet_picked);
            Update_bet();
          }

          if (digitalRead(button_confirm)) {
            place_bet();
          }
        }
      case 30: {
          game_progress = 20;
        }
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
  shuffle_cards();
  game_progress = 10;
}


void game_over() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game over");
  lcd.setCursor(0, 1);
  lcd.print("$ left ");
  lcd.print(ALL);
}
