#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "Defines.hpp"

// enum CommandList {
// 	JOIN,
// 	LEAVE,
// 	QUIT,
// 	NICK,
// 	LIST,
// 	TOPIC_USER,
// 	TOPIC_OPER,
// 	MODE_USER,
// 	MODE_OPER,
// 	KICK,
// 	INVITE,
// 	SHUTDOWN
// };

class Commands {
   public:
   private:
};

void send_message_to_server(int fd, int count, ...);

#endif