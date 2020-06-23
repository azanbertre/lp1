#include <fstream>
#include "diary.h"

Diary::Diary(const std::string& filename) {
    this->filename = filename;
    this->messages_capacity = 50;
    this->messages_count = 0;
}

void Diary::add_message(const Message& message) {
    if (this->messages_count >= this->messages_capacity) {
        return;
    }
    this->messages[this->messages_count] = message;
    this->messages_count += 1;
}

void Diary::dump_messages() {
    std::ofstream file(this->filename, std::ios::app);
    if (!file.is_open()) {
        return;
    }

    std::string current_date = "";
    for (size_t i = 0; i < this->messages_count; i++) {
        Message current_message = this->messages[i];
        std::string message_date = current_message.dt.get_current_date();
        if (message_date != current_date) {
            // Adiciona espaço entre <mensagem> e nova data
            if (current_date.size() > 0) {
                file << "\n";
            }
            file << "# " << message_date << "\n\n";
        }
        file << current_message.format_message() << "\n";
    }
    file.close();
}

void Diary::load_messages() {
    // load messages from file
}