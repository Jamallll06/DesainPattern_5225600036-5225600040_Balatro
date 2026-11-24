DESIGN PATTERN - PROJECT C++

Kompilasi dengan GCC:
g++ -std=c++14 main.cpp BlindRule.cpp CheckerDemo.cpp ChosenHand.cpp Hand.cpp HandEvaluator.cpp HandGenerator.cpp HandPlayer.cpp HandRank.cpp HandScoring.cpp RewardRule.cpp RunSession.cpp ShopSystem.cpp -o DesignPattern

Jalankan:
./DesignPattern

Kontrol pemilihan kartu:
- Setiap ronde pemain mendapat 8 kartu acak dari satu dek 52 kartu.
- Ketik nomor kartu untuk memilihnya atau membatalkan pilihan.
- Pilih minimal 1 dan maksimal 5 kartu; tekan P untuk memainkan hand.
- Tekan Q untuk mengakhiri run.
- Kartu yang dibagikan tidak memiliki duplikasi.

Checker kombinasi kartu memakai Chain of Responsibility. Kode dipisahkan
berdasarkan tanggung jawab kelas pada file header dan implementasi masing-masing.
Skor, blind, dan reward merupakan aturan contoh yang digunakan simulasi ini.
