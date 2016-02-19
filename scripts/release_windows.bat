@ECHO OFF
ECHO ###########################
ECHO  Make release version of
ECHO  Flappy++ with one click
ECHO  Needs UPX, OptiPNG and
ECHO  CBP2MAKE but it will
ECHO  work anyway, without
ECHO  these features.
ECHO  by pajadam
ECHO ###########################
ECHO - Generating updated
ECHO   makefile from CBP project
cbp2make -in Flappy++.cbp -out Makefile.windows.static -targets "Windows_Static" -windows >nul
cbp2make -in Flappy++.cbp -out Makefile.linux.static -targets "Linux_Static" -unix >nul
cbp2make -in Flappy++.cbp -out Makefile.windows.dynamic -targets "Windows_Dynamic" -windows >nul
cbp2make -in Flappy++.cbp -out Makefile.linux.dynamic -targets "Linux_Dynamic" -unix >nul
ECHO - Packing Flappy++.exe
upx -q -9 bin\Windows\Flappy++.exe >nul
ECHO - Creating release directory
rd /s /q release >nul
mkdir "release" >nul
mkdir "release\data" >nul
ECHO - Moving needed objects to
ECHO   release folder
copy "bin\Windows\Flappy++.exe" "release\" >nul
copy "data\" "release\data" >nul
ECHO - Optimizing *.png files
SETLOCAL
SET "dir=%cd%\release\data"
FOR /r "%dir%" %%a IN (*.png) DO (
  optipng -silent -o7 -strip all "%%a"
)
ECHO Check out release folder
ECHO DONE :D
ECHO ###########################
GOTO :EOF

