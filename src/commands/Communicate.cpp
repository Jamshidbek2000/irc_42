#include "../../includes/Defines.hpp"

void send_message_to_server(int fd, int count, ...) {
	std::string message = ":RickRoll.de ";
	int i = 0;
	va_list arguments;
	va_start(arguments, count);
	while (i < count) {
		message = message + va_arg(arguments, const char*);
		i++;
		if (i != count) message = message + " ";
	}
	va_end(arguments);
	message += "\r\n";
	send(fd, message.c_str(), message.length(), 0);
}

std::vector<std::string> splitString(const std::string& message) {
	std::vector<std::string> tokens;
	std::istringstream iss(message);
	std::string word;
	while (iss.good()) {
		iss >> word;
		if (!word.empty()) {
			tokens.push_back(word);
		}
	}
	return tokens;
}

std::string extractArgument(int specificArg, const std::string& message, int aCount) {
	std::vector<std::string> tokens = splitString(message);
	if (specificArg >= 0 && specificArg < static_cast<int>(tokens.size())) {
		return tokens[specificArg];
		std::cout << tokens.size() << std::endl;
		if (tokens.size() > aCount && aCount != -1) return std::string();
	}
	return std::string();
}