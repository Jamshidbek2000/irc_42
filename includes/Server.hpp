#ifndef SERVER_HPP
#define SERVER_HPP

#include <map>
#include "Client.hpp"
#include "Defines.hpp"
#include "Commands.hpp"
#include "User.hpp"

class Server {
   public:
	Server(int argc, char **argv);
	~Server();
	// INPUT PARSING
	void inputParser(int argc, char **argv);
	bool isRunning();
	int getPort();
	void setPort(int portNum);
	std::string getPassword();
	bool passwordCheck(std::string psswrd);
	void removeUser(int pollId);

	// USER
	std::map<int, User> users;
	void addUser(int userFd);
	void authenticate(std::string message, std::map<int, User>::iterator it);
	bool getPass(std::string &msg);

	// MAIN LOOPS
	void run();
	bool shouldReset();
	int setup();
	int getServerSocket();
	void setRunning(bool state);
	void setServerSocket(int socket);
	const Client &getClient(int clientNumb) const;

	void setupPoll();  // do we need this?
	void acceptConnection();

	// COMMAND HANDLING
	int processCommands(int pollId);
	void commandParser(int stringLength, std::string message);
	std::string getCommand(std::string message);

	// void CommandExecutionChecker(int stringLength, std::string message, std::string command);

	//COMMAND TO EXECUTE
	void message();
	void joinChannel();
	void leaveChannel();
	void kick();
	void invite();
	void quitServer();
	void nick();
	void listChannels();
	void modeUser();
	void modeOper();
	void topicUser();
	void topicOper();
	
	// CONNECTION LIMITS
	void setConnectionLimits();
	void setMaxLimit(int maxLimit);
	void setAllowedLimit(int allowedLimit);
	int getMaxlimit();
	int getAllowedLimit();

	// ADMIN
	void createAdmin();	 // needs to be written
	void setAdminDetails();
	std::string getAdmin();
	std::string getAdminPass();
	void setAdmin(std::string adminName);
	void setAdminPass(std::string adminPass);
	void shutdown();

	std::string extractWord(const std::string &line);
	std::string base64Decode(const std::string &encodedData);
	void setServerPassword();
	void setPassword(std::string serverPassword);

	class CustomException : public std::exception {
	   private:
		std::string message;

	   public:
		CustomException(const std::string &word);
		const char *what() const throw();
		virtual ~CustomException() throw();
	};

   private:
	// sockets
	bool serverState;
	int serverSocketFd;
	pollfd userPoll[CONNECTIONS];
	int onlineUserCount;
	// Server info
	std::string password;
	int port;

	bool reset;	 // first loop. always true

	// Connection limits
	int max_connections;
	int allowed_connections;

	// Server admin info
	std::string operator_name;
	std::string operator_password;
};

#endif