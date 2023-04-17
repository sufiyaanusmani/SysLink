echo $1 | sudo -S rm -rf /syslink 2> /dev/null
echo $1 | sudo -S apt install -y speedtest-cli
g++ syslink-installer.cpp -o syslink-installer
./syslink-installer $1
echo $1 | sudo -S chmod 777 -R /syslink
gcc compile-all.c -o compile-all
./compile-all
mkdir /tmp/syslink
echo $1 | sudo -S rm -rf syslink
echo "SysLink Installed Successfully"
