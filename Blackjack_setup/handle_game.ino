void loop() {
  currenttime = millis();

  if ((digitalRead(button_up) || digitalRead(button_down) || digitalRead(button_confirm) || digitalRead(button_hit)) && (currenttime > switchtimer + 200) || new_game || game_progress==10)
  {
    new_game = 0;
    switchtimer = currenttime;  
    
    switch (game_progress) {//new game
      case 0: {
          start_game();
        }
      case 10: {//new hand
          Serial.println(Cardsdrawn);
          if (ALL < 25){
            game_over();
          }
          else if (Cardsdrawn > 48) {
            game_over();
          }
          
          else
            Serial.println("new hand");
            new_hand();
        }
      case 20: {//pick bet amount
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
        break;
      case 30: {//bet confirmed
          if (digitalRead(button_confirm)) {
            game_progress = 40;
          }
          if (digitalRead(button_hit) && Player_card_count>4) {
            draw_random_Player();
            display_cards_drawn();
          }
        break;

      case 40: {//hand confirmed
        Player_card_value();
        Serial.println("40");
        reveal_hidden();


        }


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
