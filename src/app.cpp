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
    } else if (action == "interactive") {
        open_menu(this);
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void app::add() {
    std::string message;
    std::cout << "Message to add: " << std::ends;
    std::getline(std::cin, message);

    add(message);
}

void app::add(const std::string content) {
    Message message = Message(content);

    diary.add_message(message);
    diary.dump_messages();

    std::cout << "\n" << "Message added!!" << std::endl;
}

void app::list_messages() {
    std::cout << "# List of messages (" << this->diary.messages_count << ")\n" << std::endl;
    for (size_t i = 0; i < this->diary.messages_count; ++i) {
        const Message& message = this->diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

void app::search() {
    std::string search;
    std::cout << "Search keyword: " << std::ends;
    std::getline(std::cin, search);

    this->search(search);
}

void app::search(const std::string search) {
    std::vector<Message*> messages = diary.search(search);

    std::cout << "\n#" << messages.size() << " messages found!" << "\n" << std::endl;

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

    this->diary.load_messages();

    file.close();
}

int app::show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
    return 1;
}

void open_menu(app* app) {
    std::cout << "Diary 1.0" << "\n\n" << std::endl;
    std::cout << "Select an action below: " << "\n\n" << std::endl;
    std::cout << "1) List messages" << "\n" << std::endl;
    std::cout << "2) Add a new message" << "\n" << std::endl;
    std::cout << "3) Search all messages" << "\n\n" << std::endl;
    std::cout << "0) End" << "\n\n" << std::endl;
    std::cout << "Type here: " << std::ends;

    std::string choice;
    std::getline(std::cin, choice);

    // skip 1 line to show response
    std::cout << "\n" << std::endl;

    if (!std::isdigit(choice[0])) {
        std::cout << "Invalid option. Terminating..." << std::endl;
        return;
    }

    int selected = std::stoi(choice);

    // terminate
    if (selected == 0) {
        std::cout << "Terminating..." << std::endl;
        return;
    } else if (selected == 1) {
        app->list_messages();
    } else if (selected == 2) {
        app->add();
    } else if (selected == 3) {
        app->search();
    }
}