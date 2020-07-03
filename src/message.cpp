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

std::string Message::format_message(const std::string format) {
    std::string message = format;

    size_t date_pos = message.find("%d");
    if (date_pos != std::string::npos) {
        message.replace(date_pos, 2, this->dt.get_current_date());
    }

    size_t time_pos = message.find("%t");
    if (time_pos != std::string::npos) {
        message.replace(time_pos, 2, this->dt.get_current_time());
    }

    size_t content_pos = message.find("%m");
    if (content_pos != std::string::npos) {
        message.replace(content_pos, 2, this->content);
    }

    return message;
}