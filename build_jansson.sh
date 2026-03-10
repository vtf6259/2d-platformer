wget https://github.com/akheron/jansson/archive/refs/tags/v2.15.0.tar.gz
tar xvf v2.15.0.tar.gz
cd jansson-2.15.0
ls
mkdir build
cd build
cmake ..
make
make test
cd ../..
cp jansson-2.15.0/build/lib/libjansson.a .