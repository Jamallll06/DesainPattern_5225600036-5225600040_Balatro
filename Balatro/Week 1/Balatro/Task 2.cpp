#include <iostream>
#include <vector>
#include <string>

using namespace std;
//MUTABLE
// Menyimpan kondisi permainan saat ini.
class GameState {
public:
    int score = 0;
    bool gameOver = false;

    void UpdateScore(int amount) {
        score += amount;
    }

    bool IsGameOver() const {
        return gameOver;
    }

    void SetGameOver(bool value) {
        gameOver = value;
    }
};

// Menangani aksi/input pemain.
// Pada game Snake sebenarnya bagian ini akan membaca input keyboard.
class PlayerController {
public:
    void PlayerAction() {
        cout << "[1] Pemain memilih arah." << endl;
        cout << "    Contoh: ATAS / BAWAH / KIRI / KANAN" << endl;
    }
};

// Menangani aturan yang mengevaluasi aksi pemain.
class SnakeSystem {
public:
    void ResolveSystem(GameState& state) {
        cout << "[2] Sistem mengevaluasi gerakan Snake." << endl;
        cout << "    - Cek tabrakan dengan dinding" << endl;
        cout << "    - Cek tabrakan dengan tubuh Snake" << endl;
        cout << "    - Cek tabrakan dengan makanan" << endl;

        // Placeholder logic.
        // Pada game lengkap, makan makanan akan menambah skor
        // dan membuat Snake bertambah panjang.
        (void)state;
    }
};

// Memperbarui game state setelah sistem melakukan evaluasi.
class StateUpdater {
public:
    void UpdateState(GameState& state) {
        cout << "[3] Reward atau penalty diberikan." << endl;
        cout << "    - Makanan dimakan -> skor bertambah dan Snake memanjang" << endl;
        cout << "    - Collision -> Game Over" << endl;

        cout << "[4] Game state diperbarui." << endl;
        cout << "    - Posisi Snake berubah" << endl;
        cout << "    - Posisi makanan dapat berubah" << endl;
        cout << "    - Skor diperbarui" << endl;

        // Placeholder.
        (void)state;
    }
};

