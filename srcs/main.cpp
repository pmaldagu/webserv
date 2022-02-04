#include "../include/lib.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error : Configuration file is missing." << RESET << std::endl;
        return (-1);
    }
    try
    {
        Config *file = new Config(argv[1]);

        file->setServ();
        //////////////// Print my data /////////////////
        for (int a = 0; a < file->getServ().size(); a++)
            file->getServ()[a].debug();
        ////////////////////////////////////////////////

        Webserv web(file->getServ());

        web.launch();
    }
    catch (std::exception &e)
    {
//        web.close();
//        delete file;
    }
    return (0);
}
