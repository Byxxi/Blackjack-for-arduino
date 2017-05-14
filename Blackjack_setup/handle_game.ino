void loop() {
  currenttime = millis();

  if (currenttime > switchtimer + 150){
    tick = 1;
    switchtimer = currenttime;
  }
  else{
    tick = 0;
  }

  if (tick && !bool_game_over)
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
          if (digitalRead(button_hit) && Player_card_count<4) {
            draw_random_Player();
            display_cards_drawn();
          }
          if (Player_card_count==4) {
            game_progress = 40;
          }
        }
        break;

      case 40: {//hand confirmed, CPU plays
        reveal_hidden();
        Player_card_value();
        CPU_card_value();
        Serial.print("Player_value=");
        Serial.println(Player_value_sum);
        Serial.print("CPU_value=");
        Serial.println(CPU_value_sum);
       
        if (Player_value_sum > 21 || CPU_value_sum > Player_value_sum && CPU_value_sum < 22){
          loss();
        }

        if (CPU_value_sum > 21 || CPU_card_count==4 && CPU_value_sum < Player_value_sum){
          win();
        }

        if (Player_value_sum>=CPU_value_sum && CPU_card_count<4) {
          draw_random_CPU();
          display_cards_drawn();
          CPU_card_value();
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
  lcd.setCursor(12, 1);
  lcd.print("$");
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
  bool_game_over = 1;
}
