#include <iostream>
#include <string>

#include "app.h"

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

int app::show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
    return 1;
}