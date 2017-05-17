void new_hand() {
  Serial.println("new hand");
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
  for (int y = 0; y <= 1; y++) {
    for (int x = 4; x <= 11; x++) {
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
  if (Cardsdrawn < 52){
    int draw = random(0, 52);
    if (Deck[3][draw]=='1'){
      draw_random_Player();
      return;
    }
    Player[Player_card_count] = draw;
    Deck[3][draw]= '1';
    Serial.print("Card#[");
    Serial.print(Cardsdrawn);
    Serial.print("]=");
    Serial.print(Deck[1][Player[Player_card_count]]);
    Serial.println(Deck[2][Player[Player_card_count]]);
    Player_card_count++;
    Cardsdrawn++;
  }
}

void display_cards_drawn() {
  lcd.setCursor(4, 0); //Shows player's cards
  for (int x = 0; Player_card_count - x > 0; x++) {
    lcd.print(Deck[1][Player[x]]);
    lcd.print(Deck[2][Player[x]]);
       
  }
  delay(200);
  lcd.setCursor(6, 1); //Shows CPU's cards, skips hidden card
  for (int x = 1; CPU_card_count - x > 0; x++) {
    lcd.print(Deck[1][CPU[x]]);
    lcd.print(Deck[2][CPU[x]]);
  }
  delay(200);
}


void draw_random_CPU() {
  if (Cardsdrawn < 52){
    int draw = random(0, 52);
      if (Deck[3][draw]=='1'){
      draw_random_CPU();
      return;
    }
    CPU[CPU_card_count] = draw;
    Deck[3][draw]= '1';
    Serial.print("Card#[");
    Serial.print(Cardsdrawn);
    Serial.print("]=");
    Serial.print(Deck[1][CPU[CPU_card_count]]);
    Serial.println(Deck[2][CPU[CPU_card_count]]);
    CPU_card_count++;
    Cardsdrawn++;
  }
}

void reveal_hidden() {
  lcd.setCursor(4, 1);
  lcd.print(Deck[1][CPU[0]]);
  lcd.print(Deck[2][CPU[0]]);
}


void Player_card_value() {
  Player_value_sum = 0;
  Serial.print("player value =");
  for(int x = 0; x < Player_card_count; x++){
    Player_value_sum = Player_value_sum + Deck[0][Player[x]];
    Serial.print(Player_value_sum);
    Serial.print(",");
    if (Deck[1][Player[x]] == 'A'){
      Player_ace_count++;
    }
  }
  if (Player_value_sum > 21){
    if (Player_ace_count>=1){
      if (Player_ace_count>=Player_ace_subracted){
        Player_value_sum-=10;
        Player_ace_subracted++;
      }
    }
  }
  Serial.println("");
}

void CPU_card_value() {
  CPU_value_sum = 0;
  Serial.print("CPU value =");
  for(int x = 0; x < CPU_card_count; x++){
    CPU_value_sum = CPU_value_sum + Deck[0][CPU[x]];
    Serial.print(CPU_value_sum);
    Serial.print(",");
    if (Deck[1][CPU[x]] == 'A'){
      CPU_ace_count++;
    }
  }
  if (CPU_value_sum > 21){
    if (CPU_ace_count>=1){
      if (CPU_ace_count>=CPU_ace_subracted){
        CPU_value_sum-=10;
        CPU_ace_subracted++;
      }
    }
  }
  Serial.println("");
}
