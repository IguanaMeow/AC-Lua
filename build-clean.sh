make clean
rm -rf bin_unix
rm -rf linux_release
cd src/
rm *.cpp~ *.h~
cd ../enet
make clean
make distclean
rm -rf autom4te.cache
cd ../lua
make clean
rm -rf src/src
rm -rf ../lib/liblua.a
cd ../lanes
make clean
cd ..
