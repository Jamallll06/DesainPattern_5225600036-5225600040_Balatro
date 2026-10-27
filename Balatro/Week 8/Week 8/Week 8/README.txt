DESIGN PATTERN - PROJECT C++

Daftar file:
- Card.h, Hand.h
- ChosenHand.h, ChosenHand.cpp
- HandGenerator.h, HandGenerator.cpp
- HandPlayer.h, HandPlayer.cpp
- ScoringRule.h, ScoringRule.cpp
- JokerCard.h, JokerCard.cpp
- BlindRule.h, BlindRule.cpp
- RewardRule.h, RewardRule.cpp
- GameManager.h, GameManager.cpp
- main.cpp

Kompilasi dengan GCC:
g++ -std=c++11 main.cpp ChosenHand.cpp HandGenerator.cpp HandPlayer.cpp ScoringRule.cpp JokerCard.cpp BlindRule.cpp RewardRule.cpp GameManager.cpp -o DesignPattern

Jalankan:
./DesignPattern

Catatan:
- HandGenerator mengambil 5 kartu acak dari satu dek 52 kartu tanpa duplikasi.
- ScoringRule menjumlahkan nilai rank kartu.
- Joker menambahkan bonus 10 poin.
- BlindRule menggunakan target 100 poin.
- RewardRule memberi 0 jika kalah; jika menang, 20 + skor/10.
- Angka skor, bonus, target, dan hadiah adalah contoh implementasi karena dokumen tugas tidak menetapkan aturan detail.
