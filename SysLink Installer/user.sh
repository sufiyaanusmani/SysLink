for file in /syslink/user/*.cpp
do
	g++ "$file" -o "${file%.cpp}"
done