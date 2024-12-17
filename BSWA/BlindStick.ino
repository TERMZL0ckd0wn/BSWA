/* 
  Ditulis semula oleh KamarulUkail 2024 | TERMZL0ckd0wn
  Sumber Projek : 1. https://termz.eu.org/projects/BSWA-BM (Bahasa Melayu)
                  2. https://termz.eu.org/projects/BSWA-EN (English)
                  2. https://github.com/TERMZL0ckd0wn/BSWA (Github)
*/

// Menyatakan berberapa pemboleh ubah untuk pin yang digunakan
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;
const int sensorAir = 8;

// Menyatakan berberapa pemboleh ubah yang boleh dimanipulasikan
long jangkaMasa;
int jarak;
int jarakSelamat;


void setup() { // Kawasan 
  
  // Nyatakan trigPin & buzzer adalah komponen output
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // Nyatakan echoPin & sensorAir adalah komponen input
  pinMode(echoPin, INPUT);
  pinMode(sensorAir, INPUT);

  // Sambungan bersiri/serial untuk memeriksa jarak
  Serial.begin(9600); // Info:https://ms.wikipedia.org/wiki/Komunikasi_bersiri
  
}

void loop() { // Kawasan berulang tanpa henti
  
  // Kosongkan trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1); // 1000 mikrosaat = 1 saat

  // Nyatakan trigPin sebagai HIGH untuk jangka masa 10 mikrosaat
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  

  // Baca echoPin lalu terima jangka masa gelombang ultrasonic dalam mikrosaat
  jangkaMasa = pulseIn(echoPin, HIGH);
  
  // Kira jarak menggunakan gelombang yang diterima
  jarak = jangkaMasa * 0.034/2; // jangkaMasa * kelajuanBunyi / 2

  // Pindahkan nilai pemboleh ubah jarak ke pemboleh ubah jarakSelamat
  jarakSelamat = jarak; 
  

  
  // Jika jarak melebihi 20cm atau sensorAir aktif ...
  if (jarakSelamat <= 20 || digitalRead(sensorAir) == HIGH) {
    digitalWrite(buzzer, HIGH); // Buzzer akan menyaring'
  } else { // Selain itu ...
    digitalWrite(buzzer, LOW); // Buzzer akan senyap
  }



  // Tuliskan jarak kepada "Serial Monitor" di atas kanan IDE ini
  Serial.print("Jarak Semasa: ");
  Serial.println(jarak);

  // Tamat

}
