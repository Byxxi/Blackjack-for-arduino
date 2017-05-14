void Update_bet() {
  lcd.setCursor(13, 1);
  
  if (BetAmount[Bet_picked] < 100) {//fixes sticky characters if number goes from xxx to xx
    lcd.print(" ");
  }

  if (BetAmount[Bet_picked] < 10) {//fixes sticky characters if number goes from xxx or xx to x
    lcd.print("  ");
  }
  
  lcd.print(BetAmount[Bet_picked]);

  lcd.setCursor(13, 0);
  if (ALL < 100){
    lcd.print(" ");
  }
  
  if (ALL < 10){
    lcd.print("  ");
  }

  lcd.print(ALL);
}


void place_bet() {
  if (BetAmount[Bet_picked] > ALL) { //if bet is higher than current cash, bet won't go through
    return;
  }

  else if (BetAmount[Bet_picked] == 0) { //if bet is 0, fold and get new cards
    game_progress = 10;
    Serial.println("go to 10");
    return;
  }

  else {
    ALL = ALL - BetAmount[Bet_picked];
    game_progress = 30;
    Serial.println("go to 30");
    Update_bet();
  }
}


void loss(){
  game_progress = 10;
  Serial.println("loss");
}


void win(){
  ALL += BetAmount[Bet_picked]*2;
  game_progress = 10;
  Serial.println("win");
  Update_bet();
}