for file in /syslink/realtime/*.syslink
do
    $file &
done

for file in /syslink/sysinfo/*.syslink
do
    $file
done

/syslink/user/loggedinusers
/syslink/user/regularuserss
/syslink/user/username
/syslink/network/connectiontype
/syslink/network/hostname
/syslink/network/interfacename
/syslink/network/interfacetype
/syslink/network/ip
/syslink/network/speedtest &