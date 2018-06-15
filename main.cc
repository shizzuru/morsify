#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <regex>

using namespace std::literals::string_literals;

namespace{
    std::string processArgs(int argc, char** argv){
	if(argc > 2){
	    std::cout << "Too many arguments" << std::endl;
	    exit(EXIT_FAILURE);
	}
	else if(argc < 2){
	    std::cout << "Too few arguments" << std::endl;
	    exit(EXIT_FAILURE);
	}
	for(auto i=0; i<argc; ++i){
	    if(argv[i] == "-h"s || argv[i] == "--help"s){
		std::cout << "usage : morsify \"String to translate\"\n";
		exit(EXIT_SUCCESS);
	    }
	}
	return std::string(argv[1]);
    }

    auto ROOT="morse/";

    void PlayMorseCode(std::string toConvert){
	std::regex re("[a-zA-Z]+");
	if(!std::regex_match(toConvert, re)){
	    std::cout << "Wrong argument; Only letters can be parsed\n";
	    exit(EXIT_FAILURE);
	}
	
	sf::InputSoundFile fileData;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	for(auto a : toConvert){
	    if(a != ' '){
		std::string b = "";
		b += std::tolower(a);
		if(!buffer.loadFromFile(ROOT+ b +".ogg")){
		    std::cout << "Could not open " << ::ROOT+b+".ogg" << "\nExiting\n";
		    exit(EXIT_FAILURE);
		}
		fileData.openFromFile(ROOT+ b +".ogg");
		sound.setBuffer(buffer);
		sound.play();
	    }
	    else
		sf::sleep(sf::seconds(0.15f));
	    sf::sleep(sf::seconds(fileData.getDuration().asSeconds() + 0.25f));
	}
    }
}
int main(int argc, char** argv){
    PlayMorseCode(processArgs(argc, argv));
    return EXIT_SUCCESS;
}
