# What is Flappy++?

This is Flappy Bird clone written in C++.
Currently it's being rewritten, cause my old one was litteraly bad.
New version is written in much better way :)

# Before rewrite...

Check how game works before rewrite. It's running on 40FPS when VSync is forced to OFF :D Yeah, thats one thing why I wanted rewrite it :)

[-> Click to download <-] (http://warsztat.gd/projects/flappypp)

# What am I using to build this?

I'm using following software to build my project:
- Code::Blocks 16 IDE
- GCC 5.1 (TDM-1 32 bit)
- SFML 2.3.2 32 bit, self-compiled, static

also useful:
- GIMP
- GVIM

# How can I build this one?

##### First of all you need to get some dependencies:
- SFML Library in `/lib/Windows/` or `/lib/Windows/`
- GCC compiler
- Make

##### You can also get some cool tools that will make this build even better!
You just need put path to them into global variables of your OS.
- UPX Packer
- OptiPNG
- CBP2MAKE

##### You dont need any of these, but it's useful piece of software :D 
It'll pack your executable, optimize PNG files and create up-to-date Makefiles when building ( now only on Windows ) :D

NOTE: You can use Code::Blocks project instead of makefiles.

##### Then you should run `make -f MakeFilename`. 
I've generated some makefiles. You can chose what you need:
- Windows -> Static/Dynamic SFML
- Linux   -> Static/Dynamic SFML

##### Built game will apear in `/release` directory.

NOTE: You need to compile SFML by yourself if you want use static linking.

# What is in project's directories?

- /src  - Code
- /data - Assets
- /bin  - Binaries
- /obj  - Build objects

# License
- [GPL v3.0] (http://www.gnu.org/licenses/gpl-3.0.txt)
