void new_hand() {
  null_cards_drawn_display();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  display_cards_drawn();
}


void shuffle_cards() {
  Serial.println("print cards");
  for (int print_cards = 0; print_cards < 52; print_cards++) { //print all cards to serial to check for errors
    Serial.print(Deck[1][print_cards]);
    Serial.println(Deck[2][print_cards]);
  }
  Serial.println("print cards");
}


void draw_random_Player() {
  Serial.print("player card count");
  Serial.println(Player_card_count);
  int draw = random(0, 51);
  Player[Player_card_count] = draw;
  Serial.print("draw[");
  Serial.print(Player[Player_card_count]);
  Serial.println("]");
  Player_card_count++;
}



void draw_random_CPU() {
  Serial.print("CPU card count");
  Serial.println(CPU_card_count);
  int draw = random(0, 51);
  CPU[CPU_card_count] = draw;
  Serial.print("draw[");
  Serial.print(CPU[CPU_card_count]);
  Serial.println("]");
  CPU_card_count++;
}


void display_cards_drawn() {
  lcd.setCursor(3, 0); //Shows player's cards
  for (int x = 0; x >= 3; x++) {
    if (Player[x] != 0) {
      lcd.print(Player[x]);
    }
  }
  delay(200);
  lcd.setCursor(3, 1); //Shows CPU's cards, skips hidden card
  for (int i = 1; i >= 3; i++) {
    if (Player[i] != 0) {
      lcd.print(Player[i]);
    }
  }
  delay(200);
}


void reveal_hidden() {
  lcd.setCursor(3, 1);
  lcd.print(CPU[0]);
}


void null_cards_drawn_display() {
  for (int y = 0; y >= 1; y++) {
    for (int x = 0; x >= 7; x++) {
      lcd.setCursor(x, y);
      lcd.print(" ");
    }
  }
}
