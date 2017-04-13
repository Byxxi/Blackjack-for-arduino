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
void draw_random_Player() {

  return;
}
void draw_random_CPU() {

  return;
}

void display_cards_drawn() {
  lcd.setCursor(3, 0); //viser spilleren sine kort
  for (int x = 0; x >= 3; x++) {
    if (Player[x] != 0) {
      lcd.print(Player[x]);
    }
  }
  delay(200);
  lcd.setCursor(3, 1); //viser CPU sine kort, hopper over skjult kort
  for (int i = 1; i >= 3; i++) {
    if (Player[i] != 0) {
      lcd.print(Player[i]);
    }
  }
  delay(200);
  return;
}
void reveal_hidder() {
  lcd.setCursor(3, 1);
  lcd.print(CPU[0]);
  return;
}