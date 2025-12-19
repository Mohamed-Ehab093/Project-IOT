// ===== إعداد الأرجل =====

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

char command; // متغير لتخزين البيانات القادمة من البلوتوث

void setup() {
  // إعداد الأرجل كمخرجات
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // تشغيل الاتصال التسلسلي مع البلوتوث
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Stop(); // توقف العربية مؤقتًا قبل تنفيذ أي أمر جديد

    switch (command) {
      case 'F':  forward();  break; // أمام
      case 'B':  backward(); break; // خلف
      case 'L':  left();     break; // شمال
      case 'R':  right();    break; // يمين
      case 'S':  Stop();     break; // توقف
    }
  }
}

// ======= دوال التحكم =======

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
