#include <fstream>
#include "diary.h"

Diary::Diary() : messages(nullptr), messages_count(0), messages_capacity(10) {
    this->messages = new Message[this->messages_capacity];
}

Diary::Diary(const std::string& filename) : messages(nullptr), messages_count(0), messages_capacity(10) {
    this->filename = filename;
    this->messages = new Message[this->messages_capacity];
    this->load_messages();
}

void Diary::update_capacity() {
    // this->messages_capacity * 2 vai dar problema. Exemplo: capacity = 10 e count = 20
    this->messages_capacity = this->messages_count + this->messages_capacity;
    Message* new_array = new Message[this->messages_capacity];
    for (size_t i = 0; i < this->messages_count; i++) {
        new_array[i] = this->messages[i];
    }
    delete[] this->messages;
    this->messages = new_array;
}

void Diary::add_message(const Message& message) {
    if (this->messages_count >= this->messages_capacity) {
        this->update_capacity();
    }
    this->messages[this->messages_count] = message;
    this->messages_count += 1;
}

void Diary::dump_messages() {
    std::ofstream file(this->filename);
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
            current_date = message_date;
        }
        file << "- " << current_message.dt.get_current_time() << " " << current_message.content << "\n";
    }
    file.close();
}

void Diary::load_messages() {
    std::ifstream file(this->filename, std::ios::app);
    if (!file.is_open()) {
        return;
    }

    std::string line;
    std::string current_date;
    while (!file.eof()) {
        std::getline(file, line);

        if (line.size() == 0) {
            continue;
        }

        if (line.at(0) == '#') {
            current_date = line.substr(2, 10);
        }

        if (line.at(0) != '-') {
            continue;
        }

        std::string content = line.substr(11, line.size());
        std::string current_time = line.substr(2, 10);
        datetime dt = datetime(
            (unsigned) std::stoi(current_date.substr(6, 8)),
            (unsigned) std::stoi(current_date.substr(3, 5)),
            (unsigned) std::stoi(current_date.substr(0, 2)),
            (unsigned) std::stoi(current_time.substr(0, 2)),
            (unsigned) std::stoi(current_time.substr(3, 5)),
            (unsigned) std::stoi(current_time.substr(6, 8))
        );

        Message message = Message(content, dt);
        if (this->messages_count >= this->messages_capacity) {
            this->update_capacity();
        }
        this->messages[this->messages_count] = message;
        this->messages_count += 1;
    }
}

std::vector<Message*> Diary::search(const std::string search) {

    std::vector<Message*> search_result;

    for (size_t i = 0; i < this->messages_count; i++) {
        Message* current_message = &this->messages[i];
        if (current_message->content.find(search) != std::string::npos) {
            search_result.push_back(current_message);
        }
    }

    return search_result;
}