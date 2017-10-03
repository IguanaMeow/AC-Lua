cd enet
./configure
make
cd ../lua
make linux install
cp src/liblua.a ../lib/
cd ..
make linux
