#include "HandPlayer.h"
#include "ChosenHand.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

Hand HandPlayer::playHand(const Hand& availableCards) {
    ChosenHand chosen;
    std::string input;

    while (true) {
        std::cout << "\nPilih 1-5 kartu untuk dimainkan ("
            << chosen.size() << "/5 dipilih):\n";
        for (std::size_t i = 0; i < availableCards.cards.size(); ++i) {
            const Card& card = availableCards.cards[i];
            const auto& selectedCards = chosen.getCards();
            const bool selected = std::find(selectedCards.begin(),
                selectedCards.end(), card) != selectedCards.end();
            std::cout << "  " << (i + 1) << ". ["
                << (selected ? 'x' : ' ') << "] " << cardString(card) << '\n';
        }
        std::cout << "Ketik nomor kartu untuk pilih/batal pilih, P untuk mainkan, Q untuk akhiri run: ";

        if (!std::getline(std::cin, input)) return Hand{};

        std::replace(input.begin(), input.end(), ',', ' ');
        std::stringstream command(input);
        std::string token;
        bool invalidInput = false;

        while (command >> token) {
            std::transform(token.begin(), token.end(), token.begin(),
                [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });

            if (token == "q" || token == "quit") return Hand{};
            if (token == "p" || token == "play") {
                if (chosen.isValid()) return chosen.toHand();
                if (chosen.size() == 0) {
                    std::cout << "Pilih minimal 1 kartu sebelum dimainkan.\n";
                }
                continue;
            }

            std::stringstream numberInput(token);
            int cardNumber = 0;
            char extra = 0;
            if (!(numberInput >> cardNumber) || (numberInput >> extra) ||
                cardNumber < 1 || static_cast<std::size_t>(cardNumber) > availableCards.cards.size()) {
                invalidInput = true;
                break;
            }

            if (!chosen.toggleCard(availableCards.cards[cardNumber - 1])) {
                std::cout << "Maksimal 5 kartu. Batalkan pilihan kartu dulu.\n";
            }
        }

        if (invalidInput) {
            std::cout << "Input tidak valid. Masukkan nomor kartu, P/play, atau Q/quit.\n";
        }
    }
}
