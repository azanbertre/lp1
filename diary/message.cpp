#include <string>
#include "message.h"

std::string Message::format_message() {
    std::string formmated_message = "- ";
    formmated_message.append(this->dt.get_current_time());
    formmated_message.append(" ");
    formmated_message.append(this->content);
    return formmated_message;
}