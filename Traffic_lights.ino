  // inisialisasi lampu lalu lintas untuk pengendara
  int redKen = 13;  
  int yellowKen = 12; 
  int greenKen = 11; 
  // inisialisasi lampu lalu lintas untuk pejalan kaki
  int redPej = 3; 
  int greenPej = 2;
  //inisialisasi tambahan
  int button = 7;
  int crossTime = 2000;
  unsigned long changeTime;

void setup() {
  // inisialisasi timer
  changeTime = millis();
  // initialisasi pin menjadi output/input
  pinMode(redKen, OUTPUT);
  pinMode(yellowKen, OUTPUT);
  pinMode(greenKen, OUTPUT);
  pinMode(redPej, OUTPUT);
  pinMode(greenPej, OUTPUT);
  pinMode(button, INPUT);
  // diawali led hijau untuk pengendara dan led merah untuk pejalan kaki yang menyala
  digitalWrite(greenKen, HIGH);
  digitalWrite(redPej, HIGH);
  digitalWrite(redKen, LOW);
  digitalWrite(yellowKen, LOW);
  digitalWrite(greenPej, LOW);
  Serial.begin(9600);
}

void loop() {
  // variable button saat ditekan
  int state = digitalRead(button); 
  Serial.println(state);
  // jika button ditekan setelah 5 detik maka terjadi pergantian led
  if (state == HIGH && (millis() - changeTime) > 5000) {
    // memanggil pergantiaan led 
    changeLights();
  }
}

void changeLights() {
  digitalWrite(greenKen, LOW);    // led hijau untuk pengendara tidak menyala
  digitalWrite(yellowKen, HIGH);  // led kuning untuk pengendara menyala 
  delay(2000); 
  
  digitalWrite(yellowKen, LOW);   // led kuning untuk pengendara tidak menyala
  digitalWrite(redKen, HIGH);     // led merah untuk pengendara menyala
  
  digitalWrite(redPej, LOW);      // led merah untuk pejalan kaki tidak menyala
  digitalWrite(greenPej, HIGH);   // led hijau untuk pejalan kaki menyala
  delay(crossTime);
  
  // flash led hijau pejalan kaki 
  for (int x=0; x<10; x++) {
    digitalWrite(greenPej, LOW);
    delay(100);
    digitalWrite(greenPej, HIGH);
    delay(100);
  }
  digitalWrite(greenPej, LOW);    // led hijau untuk pejalan kaki tidak menyala
  digitalWrite(redKen, LOW);      // led merah untuk pengendara tidak menyala
  digitalWrite(redPej, HIGH);     // led merah untuk pejalan kaki menyala
  digitalWrite(greenKen, HIGH);   // led hijau untuk pengendara menyala
 
  changeTime = millis();
 }
