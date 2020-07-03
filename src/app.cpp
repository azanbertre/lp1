#include <iostream>
#include <fstream>
#include <string>

#include "app.h"

app::app() : diary() {
    this->load_config();
};

app::app(const std::string& filename) : diary(filename) {}

int app::run(int argc, char* argv[]) {
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            std::string message = argv[2];
            // Pega mensagens com espaço
            for (int i = 3; i < argc; i++) {
                message.append(" ");
                message.append(argv[i]);
            }
            std::cout << message << std::endl;
            add(message);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        std::string message = argv[2];
        // Pega mensagens com espaço
        for (int i = 3; i < argc; i++) {
            message.append(" ");
            message.append(argv[i]);
        }
        search(message);
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void app::add() {
    std::string message;
    std::cout << "Informe a mensagem:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void app::add(const std::string content) {
    Message message = Message(content);

    diary.add_message(message);
    diary.dump_messages();
}

void app::list_messages() {
    for (size_t i = 0; i < diary.messages_count; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

void app::search(const std::string search) {
    std::vector<Message*> messages = diary.search(search);

    std::cout << messages.size() << " mensagens encontradas!" << std::endl;

    if (messages.empty()) {
        return;
    }

    for (size_t i = 0; i < messages.size(); i++) {
        std::cout << "- " << messages[i]->content << std::endl;
    }
}

void app::load_config() {

    std::string filename = "diary.config";
    std::ifstream file(filename);

    if (!file.good()) {
        std::ofstream file(filename);
        file << "path=diary.md" << "\n";
        file << "default_format=%d %t: %m" << "\n";
        file.close();

        // Carrega mensagens se arquivo já existir
        this->diary.filename = "diary.md";
        this->diary.load_messages();

        return;
    }

    std::string line;
    while (!file.eof()) {
        std::getline(file, line);

        if (line.size() == 0) {
            continue;
        }

        if (line.find("path") != std::string::npos) {
            this->diary.filename = line.substr(5, line.size());
        }

        if (line.find("default_format") != std::string::npos) {
            this->diary.default_format = line.substr(15, line.size());
        }
    }

    file.close();
}

int app::show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
    return 1;
}