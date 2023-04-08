wget --no-check-certificate 'https://docs.google.com/uc?export=download&id=184uI_eqxPbYlA3Ps-tfyyLKgubNrzJvm' -O syslink-installer.cpp
g++ syslink-installer.cpp -o syslink-installer
./syslink-installer $1
rm syslink-installer*
