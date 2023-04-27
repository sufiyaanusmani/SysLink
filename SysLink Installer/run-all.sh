for file in /syslink/realtime/*.syslink
do
    $file & 2> /dev/null
done

for file in /syslink/network/*.syslink
do
    $file 2> /dev/null
done

for file in /syslink/sysinfo/*.syslink
do
    $file 2> /dev/null
done

/syslink/user/loggedinusers.syslink 2> /dev/null
/syslink/user/regularusers.syslink 2> /dev/null
/syslink/user/username.syslink 2> /dev/null
