#include "../../includes/Server.hpp"

int main(int argc, char **argv) {
	try {
		Server server(argc, argv);
		server.setAdminDetails();  // kinda extra, not needed will decide later
		server.setConnectionLimits();
		while (server.shouldReset()) {
			server.setup();
			server.run();
			close(server.getServerSocket());

			// if (command == SHUTDOWN) // only admin can do this
			// 	server.shutdown();
		}
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << std::endl;
	}
	return 0;
}