#include "message.h"

Message::Message() {
    this->content = "";
    this->dt = datetime::now();
}

Message::Message(const std::string& content) {
    this->content = content;
    this->dt = datetime::now();
}

Message::Message(const std::string& content, const datetime& dt) {
    this->content = content;
    this->dt = dt;
}

std::string Message::format_message() {
    std::string formmated_message = "- ";
    formmated_message.append(this->dt.get_current_time());
    formmated_message.append(" ");
    formmated_message.append(this->content);
    return formmated_message;
}