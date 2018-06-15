# My first kinda good/clean project

## Introduction

I've set up a decent dev environment and it gave me enough motivation to actually do something productive...
productive... I mean this is a morse coder

## Requirements

SFML2 is used to play the audio.

It is NOT statically linked so you might want to install the devel packages with your favourite package manager. If it's not available, https://www.sfml-dev.org has a great documentation on how to compile it from sources.

gcc/g++

cmake

## Installation

git clone https://github.com/shizzuru/morsify.git

cd morsify

cmake -G "Unix Makefiles"

make

./morsify "Hello world"

## If someone stumbles upon this repo and sees something horrifying, please make a pull request, I'd love to learn more about C++ good practices
