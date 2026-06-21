void maman() {
  battement();
  //while (true) {}
}
void battement() {
  for (int i = 0; i < 255; i = i + 1) {
    on(i, 0, 0);
    delay(0);
  }
  for (int i = 255; i > -1; i = i - 1) {
    on(i, 0, 0);
    delay(5);
  }
}