#include <iostream>
#include <filesystem>
#include <string.h>
#include <vector>

using std::filesystem::directory_iterator;
using std::filesystem::exists;

void dirTraversal(std::string dirName, std::string align)
{
    //vector storing all of our directory and file names
    std::vector<std::string> dfNames;
    directory_iterator dirIterEnd;

    //used to print spacings and | when needed
    std::string tabbedLvl = "";
    long unsigned int dirNum = 0;

    //collect all sub directories in the current directory into a vector
    for (directory_iterator dirIter(dirName); dirIter != dirIterEnd; dirIter++)
    {
        if ((*dirIter).is_directory())
        {
            dfNames.push_back((*dirIter).path().string());
            dirNum++;
        }
    }

    //collect all files in the current directory into a vector
    for (directory_iterator dirIter(dirName); dirIter != dirIterEnd; dirIter++)
    {
        if ((*dirIter).is_regular_file())
        {
            dfNames.push_back((*dirIter).path().string());
        }
    }

    //align is used to tell us which level in our tree of files and dirs
    //need a | or tabbed space
    for (auto al : align)
    {
        if (al == '0')
		{
			tabbedLvl += "\xb3   ";
		}
		else if (al == '1')
		{
			tabbedLvl += "    ";
		}
    }

    for (long unsigned int i = 0; i < dfNames.size(); i++)
    {
        //directories printed and traversed using recursion first
        if (i < dirNum)
        {
            if (i == dfNames.size() - 1)
            {
                //there is nothing left in the current directory to print, update align to show that
                //and we recurse to next next sub directory
                std::cout << tabbedLvl << "\xc0\xc4\xc4 \033[1;34m" << 
                dfNames[i].substr(dirName.size() + 1, dfNames[i].size()) << "\033[0m" << std::endl;
                dirTraversal(dfNames[i], align + '1');
            }
            else
            {
                //there is still stuff left to print in the current directory, update align to show that
                //and recurse to next sub directory
                std::cout << tabbedLvl << "\xc3\xc4\xc4 \033[1;34m" << 
                dfNames[i].substr(dirName.size() + 1, dfNames[i].size()) << "\033[0m" << std::endl;
                dirTraversal(dfNames[i], align + '0');
            }
            continue;
        }

        //files being printed after directories
        if (i == (dfNames.size() - 1))
        {
            //last file so make sure to all flat bar at the bottom to show that
            std::cout << tabbedLvl << "\xc0\xc4\xc4 " << 
            dfNames[i].substr(dirName.size() + 1, dfNames[i].size()) << std::endl;
        }
        else
        {
            std::cout << tabbedLvl << "\xc3\xc4\xc4 " << 
            dfNames[i].substr(dirName.size() + 1, dfNames[i].size()) << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        //current directory is default directory if no args beside command is present
        std::cout << "\033[1;34m.\033[0m" << std::endl;
        dirTraversal(".", "");
    }
    else
    {
        //make sure that the inputted directory is valid
        if (!exists(argv[1]))
        {
            std::cerr << "invalid directory" << std::endl;
            return -1;
        }

        std::cout << "\033[1;34m" << argv[1] << "\033[0m" << std::endl;
        dirTraversal(argv[1], "");
    }

    return 0;
}