void new_hand() {
  null_cards_drawn_display();
  empty_hands();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  display_cards_drawn();
  game_progress = 20;
}


void null_cards_drawn_display() {
  for (int y = 0; y >= 1; y++) {
    for (int x = 0; x >= 7; x++) {
      lcd.setCursor(x, y);
      lcd.print(" ");
    }
  }
}


void empty_hands(){
  for (int x = 0; x > 4; x++){
    CPU[x]=0;
    Player[x]=0;
  }
  Player_card_count = 0;
  CPU_card_count = 0;
}

  
void draw_random_Player() {
  Serial.print("player card count");
  Serial.println(Player_card_count);
  int draw = random(0, 51);
  if (Deck[3][draw]=='1'){
    draw_random_Player();
  }
  Player[Player_card_count] = draw;
  Deck[3][draw]= '1';
  Serial.print("drawPlayer[");
  Serial.print(Player[Player_card_count]);
  Serial.println("]");
  Player_card_count++;
}


void display_cards_drawn() {
  lcd.setCursor(3, 0); //Shows player's cards
  for (int x = 0; Player_card_count - x > 0; x++) {
    lcd.print(Deck[1][Player[x]]);
    lcd.print(Deck[2][Player[x]]);
       
  }
  delay(200);
  lcd.setCursor(5, 1); //Shows CPU's cards, skips hidden card
  for (int x = 1; CPU_card_count - x > 0; x++) {
    lcd.print(Deck[1][CPU[x]]);
    lcd.print(Deck[2][CPU[x]]);
  }
  delay(200);
}


void draw_random_CPU() {
  Serial.print("CPU card count");
  Serial.println(CPU_card_count);
  int draw = random(0, 51);
    if (Deck[3][draw]=='1'){
    draw_random_CPU();
  }
  CPU[CPU_card_count] = draw;
  Deck[3][draw]= '1';
  Serial.print("drawCPU[");
  Serial.print(CPU[CPU_card_count]);
  Serial.println("]");
  CPU_card_count++;
}


void reveal_hidden() {
  lcd.setCursor(3, 1);
  lcd.print(Deck[1][CPU[0]]);
  lcd.print(Deck[2][CPU[0]]);
}


void Player_card_value() {
  for(int x = 0; x < 4; x++){
    Player_value_sum = Player_value_sum + Deck[0][Player[x]];
    if (Deck[1][Player[x]] == 'A'){
      Player_ace_count++;
    }
  }
}

void CPU_card_value() {
  for(int x = 0; x < 4; x++){
    CPU_value_sum = CPU_value_sum + Deck[0][CPU[x]];
    if (Deck[1][Player[x]] == 'A'){
      Player_ace_count++;
    }
  }
}