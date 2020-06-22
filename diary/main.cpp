#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "main.h"
#include "datetime.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    show_usage(argv[0]);
    return 1;
  }

  std::string message;

  std::string action = argv[1];
  if (action == "add" && argc == 2) {
    std::cout << "Informe a mensagem: " << std::endl;
    std::getline(std::cin, message);
  }

  if (action == "list") {
    show_list();
    return 0;
  }
  
  // para adicionar mensagens com espaço. Ex: "teste teste"
  for (size_t i = 2; i < argc; i++) {
    message.append(argv[i]);
    if (i < argc - 1) {
      message.append(" ");
    }
  }

  if (!write_message(message)) {
    std::cerr << "O arquivo não pode ser criado." << std::endl;
    return 0;
  }
  
  std::cout << "Mensagem Adicionada" << std::endl;
  return 0;
}

bool write_message(const std::string &message) {

  std::ofstream file("messages.md", std::ios::app);

  if (!file.is_open()) {
    return false;
  }

  datetime dt = datetime::now();

  if (need_new_title()) {
    file << "# " << dt.get_current_date() << "\n\n";
  }
    
  file << "- " << dt.get_current_time() << " " << message << "\n";
  file.close();

  return true;
}

bool need_new_title() {
  std::ifstream file("messages.md", std::ios::app);

  if (!file.is_open()) {
    return true;
  }

  datetime dt = datetime::now();

  std::string now = dt.get_current_date();
  std::string line;
  while (!file.eof()) {
    std::getline(file, line);

    if (line.size() == 0) {
      continue;
    }

    if (line.find(now) != std::string::npos) {
      return false;
    }
  }

  return true;
}

void show_list() {
  std::ifstream file("messages.md", std::ios::app);

  if (!file.is_open()) {
    std::cout << "Não foi possivel abrir o arquivo." << std::endl;
  }

  std::string line;
  while (!file.eof()) {
    std::getline(file, line);

    if (line.size() == 0) {
      continue;
    }

    if (line.find("-") == std::string::npos) {
      continue;
    }

    std::cout << line.substr(11, line.size()) << std::endl;
  }
}

void show_usage(const std::string &prog_name) {
  std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
}