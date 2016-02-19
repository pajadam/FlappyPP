echo #############################
echo  Make release version of
echo  Flappy++ with one click
echo  Needs UPX and OptiPNG 
echo  but it will
echo  work anyway, without
echo  these features.
echo  by pajadam
echo #############################
echo - Packing Flappy++
upx -q -9 bin/Linux/Flappy++
echo - Creating release directory
rm -r release
mkdir release
echo - Moving needed objects to
echo   release folder
cp bin/Linux/Flappy++ release/Flappy++
cp -r data release
echo - Optimizing *.png files
for i in `find -type f -name "*.png"`
do
	optipng -silent -o7 -strip all "$i"
done
echo DONE :D
echo #############################