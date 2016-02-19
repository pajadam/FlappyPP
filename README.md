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

You need some things:
- Compile SFML library to 32bit static one
   Place it in 'lib/Windows' / 'lib/Linux' (OS dependent)
- Then you should run 'make -f MAKEFILENAME'
   There is version for Windows/Linux and Static/Linked one, chose your fate :D
   Or you can build project using Code::Blocks
- Finally you can check out Release folder, with game ready to play

# What is in project's directories?

- /src  - Code
- /data - Assets
- /bin  - Binaries
- /obj  - Build objects

# License
- [GPL v3.0] (http://www.gnu.org/licenses/gpl-3.0.txt)
