echo $1 | sudo -S rm -rf /syslink 2> /dev/null
g++ syslink-installer.cpp -o syslink-installer
./syslink-installer $1
echo $1 | sudo -S chmod 777 -R /syslink
gcc compile-all.c -o compile-all
./compile-all
echo $1 | sudo -S rm -rf syslink
echo "SysLink Installed Successfully"
