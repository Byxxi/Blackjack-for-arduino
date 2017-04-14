void new_hand() {
  null_cards_drawn_display();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  draw_random_Player();
  display_cards_drawn();
  draw_random_CPU();
  display_cards_drawn();
  return;
}


void shuffle_cards() {
  int i = 0;
for (int cardsuit = 1 ; cardsuit <= 4 ; ++cardsuit) {
    for (int cardnumber = 1 ; cardnumber <= 13 ; ++cardnumber) { 
        Cards[i] = suits[cardsuit];value[cardnumber];
        ++i;
    }
}


  for(int print_cards = 0; print_cards < 52; print_cards++){//print all cards to serial to check for errors
  Serial.print("card");
  Serial.println(Cards[print_cards]);
  }
}


void draw_random_Player() {
  Cards[Cardsdrawn] = Player[Player_card_count];
  Player_card_count++;
  Cardsdrawn++;
  return;
}


void draw_random_CPU() {
  Cards[Cardsdrawn] = CPU[CPU_card_count];
  CPU_card_count++;
  Cardsdrawn++;
  return;
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
  return;
}


void reveal_hidden() {
  lcd.setCursor(3, 1);
  lcd.print(CPU[0]);
  return;
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
