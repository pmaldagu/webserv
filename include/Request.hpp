#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "lib.hpp"

class Request
{
    public :
        Request();
        Request(char* buffer, Server& srv);
        Request(Request const& copy);
        virtual ~Request();

        Request&							operator=(Request const& copy);

		/*parser*/
		void								splitBuffer(char *buffer);
		void								parseHttpVersion();
		void								parseType( void );
		void								parsePath( void );
		void								parseLocation(Server& srv);
		void								parseFilename();
		void								parseBody( void );
		void								dechunk( void ); 

		/*getter*/
		std::list<std::string>				getBuffer( void ) const;
		std::string							getType( void ) const;
		std::string							getPath( void ) const;
		std::list<std::string>				getAccept( void ) const;
		std::string							getHttpver( void ) const;
		std::string							getRoot( void ) const;
		std::string							getFilename( void ) const;
		std::string							getBody( void ) const;
		bool								getBadStatus( void ) const;

		/*respond*/
		std::string							errorPage(std::string str);
		std::string							respond(class Server& srv);
		
		/*check*/
		std::string							checkBody(int fd);
		std::vector<class CGI>::iterator	checkCGI(Server & server);

		/*GET request*/
		std::string							GETRequest(Server& srv);
		void								parseAccept( void );
		std::string							GETResponse(class Server &srv);
		std::string							contentType();
		std::string							autoIndex();
		std::string							directoryListing(DIR* dirp);
		//std::string							createHeader(class Server& srv);
		std::string							formatSize(std::string size);
		std::string							formatLastMod(struct timespec* lastmod);
		std::string							previousPage( void );

		/*POST request*/
		std::string							POSTRequest(Server& srv);
		std::string							postAppend();

		/*DELETE request*/
		std::string							DELETERequest();

		/*debug*/
		void								debug( void );

    private :
		std::list<std::string>	_buffer;
		std::string				_type;
		std::string				_path;
		std::list<std::string>	_accept;
		std::string				_httpver;
		std::string				_filename;
		std::string				_root;
		std::string				_body;
		bool					_bad_status;
		Location*				_location;
};

#endif
